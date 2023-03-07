void logging(int ignit_fail, float temp_init, int seconds){
    // print all the interesting data

    //New debug variables 
    // V6 denotes code branch - has latest v2 updates but not Simon's v3 updates
    // V7 lowered deg change for light from 10 deg to 5 deg
    // V8 change to failed to light time from 65 up to 80 sec now to 120 sec (5 deg change from 15sec to 55sec)
    // V9 changed seconds to long as fan seems to kick in after a few hours. suspect int overflow
    Serial.print("V9 | pushpin: ");
    Serial.print(analogRead(push_pin));
    Serial.print(" | BTN: ");
    Serial.print(heater_on);
    //Serial.print(analogRead(push_pin));
    Serial.print(" | Glow: ");
    Serial.print(debug_glow_plug_on);

    
    float water_percentage = (100.00/255.00) * debug_water_percent_map;
    Serial.print(" | WTR_SP: ");
    Serial.print(water_percentage);    
    //Serial.print("/");
    //Serial.print(debug_water_percent_map);    
    
    Serial.print(" | Fail: ");
    //New debug variables 
    
    Serial.print(webasto_fail);
    Serial.print(" | IgFail#: ");
    Serial.print(Incidents);
//    Serial.print(" | BGo: ");
//    Serial.print(burn);
//    Serial.print(" | B Mode: ");
//    if(burn_mode == 0)
//      Serial.print("OFF");
//    if(burn_mode == 1)
//      Serial.print("Starting");
//    if(burn_mode == 2)
//      Serial.print("Running");
//    if(burn_mode == 3)
//      Serial.print("Shuting Down");

    Serial.print(" | Burn: ");
    Serial.print(burn);
    Serial.print(" | BurnMode: ");
    Serial.print(burn_mode);
    Serial.print(" | W_Tmp: ");
    Serial.print(water_temp);
    //Serial.print(" | W_Raw: ");
    //Serial.print(rawDataWater);
    Serial.print(" | E_Tmp: ");
    Serial.print(exhaust_temp);
    //Serial.print(" | E_Raw: ");
    //Serial.print(rawDataExhaust);
    if(burn_mode == 1)
    {
      //Serial.print("/");
      //Serial.print(temp_init+3);
    }
    Serial.print(" | Fan_Speed_%: ");
    Serial.print(fan_speed);
//    Serial.print(" | Fuel_HZ ");
//    if(delayed_period>0)
//      Serial.print(1000.00/delayed_period);
    Serial.print(" | Fuel: ");
    Serial.print(fuel_need);
   // Serial.print(" | Glow For (Sec): ");
   // Serial.print(glow_time);
    //Serial.print(" | Glow Left: ");
    //
    Serial.print(glow_left);
    Serial.print(" | Batt: ");

    Serial.print(Battery_Voltage(),1);    
    
    Serial.print(" | Time: ");
    Serial.print(seconds);
    Serial.print(" |  ");
    Serial.println(message); 

    int Running = int(heater_on);

}
