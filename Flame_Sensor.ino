//This is experimental
bool Flame_Sensor(bool Initialise){
float InitV = 0;
float SecondV = 0;
float Change = 0;

  if(Initialise) {
    //Measure the heater resistance initially, before the heater is started
    //In fact, just measure the battery voltage with the heater on and off.  Assuming the battery doesn't drain too much
    //in a fraction of a second, the difference will be proportional to the heater resistance.
    InitV = Battery_Voltage();
    analogWrite(glow_plug_pin, 255);
    delay(1); //Don't let it heat up too much
    SecondV = Battery_Voltage();
    analogWrite(glow_plug_pin, 0);
    Flame_Diff = InitV - SecondV; //When the heater is hot, the resistance increases so the Diff should reduce
  } else {
    InitV = Battery_Voltage();
    analogWrite(glow_plug_pin, 255);
    delay(1); //Don't let it heat up too much
    SecondV = Battery_Voltage();
    analogWrite(glow_plug_pin, 0);
    // LFR adding an if statement to guard divide by zero here
    if((InitV - SecondV) == 0){
      Change = 0;
    } else {
      Change = Flame_Diff / (InitV - SecondV)*100;
    }
    Serial.print("InitV = "); Serial.print(InitV); Serial.print("SecondV = "); Serial.print(SecondV); Serial.print("Flame_Sensor = "); Serial.println(Change);
         
  }
  if(Change>Flame_Threshold) {
    return true;
  } else {
    return false;
  }
}
