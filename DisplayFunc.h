TM1637Display display(CLK, DIO);

///N == 999  as : "Auto"

void Display(int N){            
  //display.clear();

  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };
  display.setBrightness(0x0f);

  /*switch (N)
  {
    case 111:
      // Custom text <Boot>
      const uint8_t ONdisplay[] = {
        SEG_A | SEG_F | SEG_G | SEG_B  , //0
        SEG_D ,                         //-
        SEG_D ,                 //-
        SEG_A | SEG_F | SEG_G | SEG_B  , //0            //0
      };
      display.setSegments(ONdisplay);
      Blynk.virtualWrite(V1, "Start Up!!!");              // Send value to Blynk app (replace V2)
    break;
    case 222:
      // Custom text <Sleep>
      const uint8_t OFFdisplay[] = {
        SEG_G , //0
        SEG_D ,                         //-
       SEG_D ,                 //-
       SEG_G, //0            //0
      };
      display.setSegments(OFFdisplay);
      Blynk.virtualWrite(V1, "Sleeping Zzz");              // Send value to Blynk app (replace V2)
    break;
    case 999: 
      // Custom text <Auto>
      const uint8_t AUTO[] = {
        SEG_A | SEG_F | SEG_B | SEG_G | SEG_E | SEG_C , //A
        SEG_E | SEG_D | SEG_C ,                         //u
        SEG_F | SEG_E | SEG_D | SEG_G ,                 //t
        SEG_E | SEG_D | SEG_C | SEG_G ,                 //o    N == 999 --> auto
      };
      display.setSegments(AUTO);
      Blynk.virtualWrite(V1, "Auto");              // Send value to Blynk app (replace V2)
    break;
    default:
      display.showNumberDec(N, false);
      Blynk.virtualWrite(V1, String(N));              // Send value to Blynk app (replace V2)
    break;
  }*/


  if ( N == 111) 
  {
    // Custom text <Boot>
      const uint8_t ONdisplay[] = {
        SEG_A | SEG_F | SEG_G | SEG_B  , //0
        SEG_D ,                         //-
        SEG_D ,                 //-
        SEG_A | SEG_F | SEG_G | SEG_B  , //0            //0
      };
      display.setSegments(ONdisplay);
      Blynk.virtualWrite(V1, "Start Up!!!");              // Send value to Blynk app (replace V2)
  }

  else if ( N == 222)
  {
    // Custom text <Sleep>
      const uint8_t OFFdisplay[] = {
        SEG_G , //0
        SEG_D ,                         //-
         SEG_D ,                 //-
        SEG_G, //0            //0
      };
      display.setSegments(OFFdisplay);
      Blynk.virtualWrite(V1, "Sleeping Zzz");              // Send value to Blynk app (replace V2)
  }

  else if ( N == 999)
  {
    // Custom text <Auto>
      const uint8_t AUTO[] = {
        SEG_A | SEG_F | SEG_B | SEG_G | SEG_E | SEG_C , //A
        SEG_E | SEG_D | SEG_C ,                         //u
        SEG_F | SEG_E | SEG_D | SEG_G ,                 //t
        SEG_E | SEG_D | SEG_C | SEG_G ,                 //o    N == 999 --> auto
      };
      display.setSegments(AUTO);
      Blynk.virtualWrite(V1, "Auto");              // Send value to Blynk app (replace V2)
  }

  else
  {
      display.showNumberDec(N, false);
      Blynk.virtualWrite(V1, String(N));              // Send value to Blynk app (replace V2)
  }
}