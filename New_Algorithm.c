// setting up output variables
int32 LoadSw1; 
int32 LoadSw2;
int32 LoadSw3;
int32 DBattery;
int32 CBattery;
float32 MainsReq;
float32 MainsMAX = 5;
float32 BusVMAX = 2;
float32 BatteryChargeI = 0.5;
float32 BatteryDischI = 0.5;
float32 MainControl = (10/MainsMAX) * BusI;
float32 Load1 = 2;   //current draw of load1   1 worked
float32 Load2 = 4;    // current draw of load2    2 worked
float32 Load3 = 1; // Current draw of load3         3 worked


//Initialisation here, Load1,2,3, BatteryChargeI, PV and wind will be calculated from their respective pin.

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

if(LoadCall1 == 1  && LoadCall2 == 0 && LoadCall3 == 0){
	 //we will take the busI in the next if loop BusIdiff. If BusI < Bus
	 if(Load1 < MainsMAX + PV + Wind){
		 LS1_hi();
	 }
}
else LS1_lo();


if(LoadCall1 == 0  && LoadCall2 == 1 && LoadCall3 == 0 ){
	if(Load2 < MainsMAX + PV + Wind){
		 LS2_hi();
	 }
	 else LS2_lo();
}

if(LoadCall1 == 1  && LoadCall2 == 1 && LoadCall3 == 0){
	if(Load1 + Load2 < MainsMAX + PV + Wind){
		 LS2_hi();
	 }
	 else LS2_lo();
	 if(Load1 < MainsMAX + PV + Wind){
		 LS1_hi();
	 }
	 else LS1_lo();
}


if(LoadCall1 == 0  && LoadCall2 == 0 && LoadCall3 == 1){
	if(Load3 < MainsMAX + PV + Wind){
		LS3_hi();
	}
	else LS3_lo();
	
}


if(LoadCall1 == 1  && LoadCall2 == 0 && LoadCall3 == 1){
	if(Load3 + Load1  < MainsMAX + PV + Wind){
		LS3_hi();
	}
	else LS3_lo();
	
	if(Load1 < MainsMAX + PV + Wind){
		LS1_hi();
	}
	else LS1_lo();
}

if(LoadCall1 == 0  && LoadCall2 == 1 && LoadCall3 == 1  ){
	if(Load2 + Load3 < MainsMAX + PV + Wind){
		LS3_hi();
	}
	else LS3_lo();

	if(Load2 < MainsMAX + PV + Wind){
		LS2_hi();
	}
	else LS2_lo();
}


if(LoadCall1 == 1 && LoadCall2 == 1 && LoadCall3 == 1 ){
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
