void modeFan_up()
{
  if (modeFan >= 3) {modeFan = 0;}
  else {modeFan++;}
}

void modeChange() 
{
  int switchCondition = buttonCheck(); //Save data(Button)

  delay(10);

    Serial.print("Sw");Serial.println(switchCondition);

  switch (modeMain)
  {
    case 0:
      //Wake up mode
      if ((switchCondition != -1) || visualButton) 
      {
        visualButton = false; //reset value
        modeMain = 1;         //operation mode

        wakeScreen = true;
        trigShow();
      }
    break;
    case 1:
      if (visualButton) {visualButton = false; if (switchCondition != 1) {switchCondition = 0;}}
      switch (switchCondition) 
      {
        case 0:
          //Short pulse
          modeFan_up();

          trigShow();
        break;
        case 1:
          //Sleep mode
          modeMain = 0;
          Fan(0);

          trigShow();
          while (!digitalRead(buttonPin)) {}
        break;
      }
    break; 
  }
}