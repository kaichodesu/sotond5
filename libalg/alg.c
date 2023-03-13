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
}
else{
CBAT_lo();
DBAT_hi();
}
            if(~LC1 && ~LC2 && ~LC3){
                LS1_lo();
                LS2_lo();
                LS3_lo();

            }

            if(LC1 && ~LC2 && ~LC3){
                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
					PWM()
                }

            else {
				LS1_lo();
			}
			}

            if(~LC1 && LC2 && ~LC3 ){
                if(Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
                }
                else{
					LS2_lo();


				}
            }

            if( LC1 && LC2 && ~LC3){
                if(Load1 + Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
                }
                else{
					LS2_lo();
				}
                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
                }
                else {
					LS1_lo();
				}
            }

            if(~LC1 && ~LC2 && LC3){
                if(Load3 < MainsMAX + PV + Wind){
                    LS3_hi();
                }
                else{
					LS3_lo();
				}

            }

            if(LC1 && ~LC2 && LC3){
                if(Load3 + Load1  < MainsMAX + PV + Wind){
                    LS3_hi();
                }
                else {
					LS3_lo();
				}

                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
                }
                else{
					LS1_lo();
				}
            }

            if(~LC1 && LC2 && LC3  ){
                if(Load2 + Load3 < MainsMAX + PV + Wind){
                    LS3_hi();
                }
                else {
					LS3_lo();

				}

                if(Load2 < MainsMAX + PV + Wind){
                    LS2_hi();
                }
                else{
					LS2_lo();
				}
            }

            if(LC1 && LC2 && LC3 ){
                if(Load1 + Load2 + Load3  < MainsMAX + PV + Wind){
                    LS3_hi();
                }
                else {
					LS3_lo();

				}


                if(Load2 + Load1 < MainsMAX + PV + Wind){
                    LS2_hi();

				}
                else{
					LS2_lo();

				}

                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();

                }
                else{
					LS1_lo();
				}
            }
}
