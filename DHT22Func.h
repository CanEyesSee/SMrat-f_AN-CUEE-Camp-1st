DHT_Unified dht(DHTPIN, DHTTYPE);

// Return value
//  -1 : Err <unable to connect>

int temp(){
  //set class <sensors_event_t as event>
  sensors_event_t event;

  //Link class to Lib
  dht.temperature().getEvent(&event);

  //Check if sensor is in good state
  if (isnan(event.temperature)) {
    if(debugAble){Serial.println(F("Error reading temperature!"));}
    return -1;
  }
  
  //Get Temp data(oC)
  double tempC = event.temperature;
  
  return short(tempC); 
}