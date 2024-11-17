///////////////////////////////////////////////////////////////////
//This func made for check the button pressed if has been pressed then read the time that it takes
short buttonCheck()
{
  //Check if the button has been pressed
  if (!digitalRead(buttonPin)) 
  {
    //Define time start and essentials 
    bool buttonPressed = false;
    unsigned long buttonPressTime = millis();
    //wait until the button 
    int debounceCount = 0;
    while (true) 
    {
      delay(10);
      if (digitalRead(buttonPin)) {if (++debounceCount > 5) {break;}}
      else if((millis() - buttonPressTime) > longPressTime) {return 1;} 
    }
    return 0;
  }
  return -1;
}
///////////////////////////////////////////////////////////////////


// Note while using EXP.
//
//  /* call */
//  int but = buttonCheck(); //Read this func
//
//  /* test print 0 pressed 1 long -1 not */
//  if (but < 0) {/*not pressed*/}
//  else if(but) {Serial.println("Long Pressed");}
//  else {Serial.println("Short Pressed");}
//
//  /* wait until unpress */
//  while (!digitalRead(buttonPin)) {}
//  delay(100);