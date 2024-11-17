unsigned long showUntil = millis();
bool wakeScreen = true;

void trigShow() 
{
  showUntil = millis() + uptimeState;
}

void showDisplay()
{
  if (showUntil < millis()) 
  {
    //IDLE Screen

    //On screen 
    if (modeMain)
    {
      Display(TempDHT22);
    }
    //Off sreen
    else 
    {
      display.clear(); //Turn screen to blank 
    }
  } 
  else 
  {
    //On Screen
    if (modeMain) 
    {
      if (wakeScreen) 
      {
         Display(111); 
         delay(1000);
         wakeScreen = false;
      }
      else {
      switch (modeFan) 
      {
        case 0:
          Display(999); /* 999 = "Auto" */
        break;
        default:
          Display(modeFan);
        break;
      }}
    }
    //Off Screen
    else
    {
      //Going to Sleep
      Display(222); /* 22 = sleep */
    }
  }
}