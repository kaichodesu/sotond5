#include <stdbool.h>
#include <math.h>
#include "../libio/io.h"

//========================================================================//
// Scenario constants
const uint8_t MainsMAX = 2;
const uint8_t BatteryChargeI = 1;
const float Load1 = 1.2;
const float Load2 = 2;
const float Load3 = 0.8;
//========================================================================//

//  uints for initial time sensitive data storage
float PV, Wind, BusI, MainsReq;

void algorithm(void){
    MainsReq =   (10/MainsMAX) * BusI;
            if(BusI + BatteryChargeI < MainsMAX){
                DBAT_lo();
                CBAT_hi();
            }
            else{
                CBAT_lo();
                DBAT_hi();
            }

            if(MainsReq >= 10){
                MainsReq = 10;
            }

            if(~LC1 && ~LC2 && ~LC3){
                LS1_lo();
                LS2_lo();
                LS3_lo();

            }

            if(LC1 && ~LC2 && ~LC3){
                //we will take the busI in the next if loop BusIdiff. If BusI < Bus
                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
                }
            }
            else LS1_lo();

            if(~LC1 && LC2 && ~LC3 ){
                if(Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
                }
                else LS2_lo();
            }

            if( LC1 && LC2 && ~LC3){
                if(Load1 + Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
                }
                else LS2_lo();
                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
                }
                else LS1_lo();
            }

            if(~LC1 && ~LC2 && LC3){
                if(Load3 < MainsMAX + PV + Wind){
                    LS3_hi();
                }
                else LS3_lo();
            }

            if(LC1 && ~LC2 && LC3){
                if(Load3 + Load1  < MainsMAX + PV + Wind){
                    LS3_hi();
                }
                else LS3_lo();

                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
                }
                else LS1_lo();
            }

            if(~LC1 && LC2 && LC3  ){
                if(Load2 + Load3 < MainsMAX + PV + Wind){
                    LS3_hi();
                }
                else LS3_lo();

                if(Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
                }
                else LS2_lo();
            }

            if(LC1 && LC2 && LC3 ){
                if(Load1 + Load2 + Load3  < MainsMAX + PV + Wind){
                    LS3_hi();
                }
                else LS3_lo();

                if(Load2 + Load1 < MainsMAX + PV + Wind){
                    LS2_hi();
                }
                else LS2_lo();

                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
                }
                else LS1_lo();
            }
}
