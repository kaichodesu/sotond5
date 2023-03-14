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
int BusVMAX = 2;
//========================================================================//

//  uints for initial time sensitive data storage
float PV, Wind, BusI, MainsReq, BusV;
int BatteryDischI = 1;
bool LS1, LS2, LS3;

void algorithm(void){

	// setting up output variables


//Initialisation here, Load1,2,3, BatteryChargeI, PV and Wind will be calculated from their respective pin.

//We will monitor the pin until its value is approx 0, start a timer until the max value is reached, multiply that value by 4 and set it as our new TOP, this allows us to sample at every peak.

// The interrupt will be defined on initialisation, every time we reach TOP, it will trigger.

//Need to set up a PWM (Phase & frequency correct mode on timer 1)

//Need to initialise ADC ports (free-running mode)

//On interrupt we should also calculate MainsMAX. To do this:

/* On initialisation, Measure BusI and keep loads off while battery charges for a brief moment while doing the following:
 Measure BusI and request 10
 lower the request by some value and monitor BusV
 when BusV drops below BusVMAX (approx 2.38)increment BusV so that BusV is back to normal
 */

//We enter the algorithm below.


//if the difference between busI and MainsMAX + PV + Wind less than BatteryChargeI, discharge battery else charge

if(BusV < 3.3) // bus voltage natural value
{
	MainsReq +=0.1;
}

if(MainsReq > 10)
{
MainsReq = 10;
}


if(MainsReq >= 10)
{
	MainsReq = 10;
}

if(MainsReq <= 0)
{
	MainsReq = 0;
}

if((LC1 == 0)  && (LC2 == 0) && (LC3 == 0))
{
	LS1_lo();  LS1= 0;
	LS2_lo();  LS2= 0;
	LS3_lo();  LS3= 0;

	DBAT_lo();
	CBAT_hi();

}

if((LC1 == 1)  && (LC2 == 0) && (LC3 == 0)) //we will take the busI in the next if loop BusIdiff. If BusI < Bus
{
	if( (MainsMAX + PV + Wind) - Load1 < BatteryChargeI  )
	{
	CBAT_lo();   DBAT_hi();
	}
	else {DBAT_lo();   CBAT_hi();}

	 if(Load1 < MainsMAX + PV + Wind)
	 {
		 LS1_hi();  LS1= 1;
	 }
	 else {LS1_lo();  LS1= 0;}
	 if(LS1 == 0)
	 {
		 DBAT_lo();   CBAT_hi();
	 }

}



if((LC1 == 0)  && (LC2 == 1) && (LC3 == 0) )
{
	if( (MainsMAX + PV + Wind) - Load2 < BatteryChargeI  )
	{
	CBAT_lo();   DBAT_hi();
	}
	else {DBAT_lo();   CBAT_hi();}
	if(Load2 < MainsMAX + PV + Wind)
	 {
		 LS2_hi();  LS2= 1;
	 }
	 else {LS2_lo();  LS2= 0;}
	 if(LS2 == 1)
	 {
		 DBAT_lo();   CBAT_hi();
	 }
}




if((LC1 == 1)  && (LC2 == 1) && (LC3 == 0))
{
	if(Load1 + Load2 < MainsMAX + PV + Wind)
	 {
		 LS2_hi();  LS2= 1;
		 if( (MainsMAX + PV + Wind) - (Load1 + Load2) < BatteryChargeI  )
		{
			CBAT_lo();   DBAT_hi();
		}
		else {DBAT_lo();   CBAT_hi();}
	 }
	 else LS2_lo();

	 if(LS2 == 1)
	 {

	 	if( (MainsMAX + PV + Wind) - Load1 < BatteryChargeI  )
		{
			CBAT_lo();   DBAT_hi();
		}
		else {DBAT_lo();   CBAT_hi();}
	 }

	 if(Load1 < MainsMAX + PV + Wind)
	 {
		 LS1_hi();  LS1= 1;
	 }
	 else {LS1_lo();  LS1= 0;}

	 if(LS1 == 0)
	 {
		 DBAT_lo();   CBAT_hi();
	 }



}


if((LC1 == 0)  && (LC2 == 0) && (LC3 == 1))
{
	if(Load3 < MainsMAX + PV + Wind)
	{
		LS3_hi();  LS3= 1;
		if( (MainsMAX + PV + Wind) - Load3 < BatteryChargeI  )
		{
			CBAT_lo();   DBAT_hi();
		}
		else {DBAT_lo();   CBAT_hi();}
	}
	else {LS3_lo();  LS3= 0;}

}


if((LC1 == 1)  && (LC2 == 0) && (LC3 == 1))
{
	if(Load3 + Load1  < MainsMAX + PV + Wind)
	{
		LS3_hi();  LS3= 1;
		if( (MainsMAX + PV + Wind) -  (Load3 + Load1) < BatteryChargeI  )
		{
			CBAT_lo();   DBAT_hi();
		}
		else {DBAT_lo();   CBAT_hi();}

	}
	else {LS3_lo();  LS3= 0;}

	if(LS3 == 1)
	{
		if( (MainsMAX + PV + Wind) -  Load1 < BatteryChargeI  )
		{
			CBAT_lo();   DBAT_hi();
		}
		else {DBAT_lo();   CBAT_hi();}
	}

	if(Load1 < MainsMAX + PV + Wind)
	{
		LS1_hi();  LS1= 1;
	}

	else {LS1_lo();  LS1= 0;}

	if(LS1 == 0)
	{
		DBAT_lo();   CBAT_hi();
	}


}

if((LC1 == 0)  && (LC2 == 1) && (LC3 == 1)  )
{
	if(Load2 + Load3 < MainsMAX + PV + Wind)
	{
		LS3_hi();  LS3= 1;
		if( (MainsMAX + PV + Wind) - (Load2 + Load3) < BatteryChargeI  )
		{
			CBAT_lo();   DBAT_hi();
		}
		else {DBAT_lo();   CBAT_hi();}

	}
	else {LS3_lo();  LS3= 0;}
	if(LS3 == 1)
	{
		if( (MainsMAX + PV + Wind) - Load2 < BatteryChargeI  )
		{
			CBAT_lo();   DBAT_hi();
		}
		else {DBAT_lo();   CBAT_hi();}
	}

	if(Load2 < MainsMAX + PV + Wind)
	{
		LS2_hi();  LS2= 1;
	}

	else {LS2_lo();  LS2= 0;}
	if(LS2 == 1)
	{
		DBAT_lo();   CBAT_hi();
	}


}


if((LC1 == 1) && (LC2 == 1) && (LC3 == 1) )
{
	if(Load1 + Load2 + Load3  < MainsMAX + PV + Wind)
	{
		LS3_hi();  LS3= 1;
		if( (MainsMAX + PV + Wind) - (Load1 + Load2 + Load3) < BatteryChargeI  )
		{
			CBAT_lo();   DBAT_hi();
		}
		else {DBAT_lo();   CBAT_hi();}
	}

	else {LS3_lo();  LS3= 0;}
	if(LS3 == 1)
	{
		if( (MainsMAX + PV + Wind) - (Load1 + Load2) < BatteryChargeI  )
		{
			CBAT_lo();   DBAT_hi();
		}
		else {DBAT_lo();   CBAT_hi();}
	}


	if(Load2 + Load1 < MainsMAX + PV + Wind)
	{
		LS2_hi();  LS2= 1;
	}
	else {LS2_lo();  LS2= 0;}

	if(LS2 == 1)
	{
		if( (MainsMAX + PV + Wind) - Load1 < BatteryChargeI  )
		{
			CBAT_lo();   DBAT_hi();
		}
		else {DBAT_lo();   CBAT_hi();}
	}
	if(Load1 < MainsMAX + PV + Wind)
	{
		LS1_hi();  LS1= 1;
	}
	else {LS1_lo();  LS1= 0;}
		if(LS1 == 0)
		{
			DBAT_lo();   CBAT_hi();
		}
	}

}
