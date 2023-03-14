#include <stdbool.h>
#include <math.h>
#include "../libio/io.h"
#include "../liblcd/lcd.h"
#include "../mainsreq/mainsreq.h"

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

	if(BusI + BatteryChargeI < MainsMAX + PV + Wind)
{
CBAT_hi();
DBAT_lo();
bat_pwr(true);
}
else{
CBAT_lo();
DBAT_hi();
bat_pwr(false);
}
            if(~LC1 && ~LC2 && ~LC3){
                LS1_lo();
                LS1_red();
                LS2_lo();
                LS2_red();
                LS3_lo();
                LS3_red();
            }

            if(LC1 && ~LC2 && ~LC3){
                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();

                }

            else {
				LS1_lo();
                LS1_red();
			}
			}

            if(~LC1 && LC2 && ~LC3 ){
                if(Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
                    LS2_green();
                }
                else{
					LS2_lo();
                    LS2_red();
				}
            }

            if( LC1 && LC2 && ~LC3){
                if(Load1 + Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
                    LS2_green();
                }
                else{
					LS2_lo();
                    LS2_red();
				}
                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
                    LS1_green();
                }
                else {
					LS1_lo();
                    LS1_red();
				}
            }

            if(~LC1 && ~LC2 && LC3){
                if(Load3 < MainsMAX + PV + Wind){
                    LS3_hi();
                }
                else{
					LS3_lo();
                    LS3_red();
				}

            }

            if(LC1 && ~LC2 && LC3){
                if(Load3 + Load1  < MainsMAX + PV + Wind){
                    LS3_hi();
                    LS3_green();
                }
                else {
					LS3_lo();
                    LS3_red();
				}

                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
                    LS1_green();
                }
                else{
					LS1_lo();
                    LS1_red();
				}
            }

            if(~LC1 && LC2 && LC3  ){
                if(Load2 + Load3 < MainsMAX + PV + Wind){
                    LS3_hi();
                    LS3_green();
                }
                else {
					LS3_lo();
                    LS3_red();
				}

                if(Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
                    LS2_green();
                }
                else{
					LS2_lo();
                    LS2_red();
				}
            }

            if(LC1 && LC2 && LC3 ){
                if(Load1 + Load2 + Load3  < MainsMAX + PV + Wind){
                    LS3_hi();
                    LS3_green();
                }
                else {
					LS3_lo();
                    LS3_red();
				}


                if(Load2 + Load1 < MainsMAX + PV + Wind){
                    LS2_hi();
                    LS2_green();
				}
                else{
					LS2_lo();
                    LS2_red();
				}

                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
                    LS1_green();
                }
                else{
					LS1_lo();
                    LS1_red();
				}
            }
}
