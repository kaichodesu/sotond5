#include <stdbool.h>
#include <math.h>
#include "../libio/io.h"
#include "../liblcd/lcd.h"

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
            if(~LC1 && ~LC2 && ~LC3){
                LS1_lo();
                LS2_lo();
                LS3_lo();

				LC1_red();
				LC2_red();
				LC3_red();

				LS1_red();
				LS2_red();
				LS3_red();

            }

            if(LC1 && ~LC2 && ~LC3){
                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();
					LC1_green();
					LC2_red();
					LC3_red();

					LS1_green();
					LS2_red();
					LS3_red();
                }

            else {
				LS1_lo();

				LC1_green();
				LC2_red();
				LC3_red();

				LS1_red();
				LS2_red();
				LS3_red();
			}
			}

            if(~LC1 && LC2 && ~LC3 ){
                if(Load2 < MainsMAX + PV + Wind){
                    LS2_hi();

					LC1_red();
					LC2_green();
					LC3_red();

					LS1_red();
					LS2_green();
					LS3_red();
                }
                else{
					LS2_lo();

					LC1_red();
					LC2_green();
					LC3_red();

					LS1_red();
					LS2_red();
					LS3_red();


				}
            }

            if( LC1 && LC2 && ~LC3){
                if(Load1 + Load2 < MainsMAX + PV + Wind){
                    LS2_hi();

					LC1_green();
					LC2_green();
					LC3_red();

					LS1_green();
					LS2_green();
					LS3_red();
                }
                else{
					LS2_lo();

					LC1_green();
					LC2_green();
					LC3_red();

					LS1_green();
					LS2_red();
					LS3_red();


				}
                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();

					LC1_green();
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

					LC1_red();
					LC2_red();
					LC3_green();

					LS1_red();
					LS2_red();
					LS3_green();
                }
                else{
					LS3_lo();

					LC1_red();
					LC2_red();
					LC3_green();

					LS1_red();
					LS2_red();
					LS3_red();


				}

            }

            if(LC1 && ~LC2 && LC3){
                if(Load3 + Load1  < MainsMAX + PV + Wind){
                    LS3_hi();

					LC1_green();
					LC2_red();
					LC3_green();

					LS1_green();
					LS2_red();
					LS3_green();
                }
                else {
					LS3_lo();

					LC1_green();
					LC2_red();
					LC3_green();

					LS1_green();
					LS2_red();
					LS3_red();



				}

                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();

					LC1_green();
					LS1_green();
                }
                else{
					LS1_lo();

					LC1_green();
					LS1_red();
				}
            }

            if(~LC1 && LC2 && LC3  ){
                if(Load2 + Load3 < MainsMAX + PV + Wind){
                    LS3_hi();

					LC1_red();
					LC2_green();
					LC3_green();

					LS1_red();
					LS2_green();
					LS3_green();
                }
                else {
					LS3_lo();

					LC1_red();
					LC2_green();
					LC3_green();

					LS1_red();
					LS2_green();
					LS3_red();

				}

                if(Load2 < MainsMAX + PV + Wind){
                    LS2_hi();

					LC2_green();
					LS2_green();


                }
                else{
					LS2_lo();

					LC2_green();
					LS2_red();
				}
            }

            if(LC1 && LC2 && LC3 ){
                if(Load1 + Load2 + Load3  < MainsMAX + PV + Wind){
                    LS3_hi();

					LC1_green();
					LC2_green();
					LC3_green();

					LS1_green();
					LS2_green();
					LS3_green();
                }
                else {
					LS3_lo();

					LC1_green();
					LC2_green();
					LC3_green();

					LS1_green();
					LS2_green();
					LS3_red();

				}


                if(Load2 + Load1 < MainsMAX + PV + Wind){
                    LS2_hi();

					LC2_green();
					LS2_green();


                }
                else{
					LS2_lo();

					LC2_green();
					LS2_red();

				}

                if(Load1 < MainsMAX + PV + Wind){
                    LS1_hi();

					LC1_green();
					LS1_green();

                }
                else{
					LS1_lo();

					LC1_green();
					LS1_red();
				}
            }
}
