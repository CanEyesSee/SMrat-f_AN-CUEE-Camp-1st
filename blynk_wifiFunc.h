//Store Slider value of visual pin 0
int sliderValue = 0;
 //Store state changed
  bool visualButton = false; /* note you have to changed to false by yourself. For you to able to check the state */

BLYNK_WRITE(V0) {  // Slider value received on virtual pin V1
  sliderValue = param.asInt();

  // Check if slider value is 1, then reset it in Blynk app
  if (sliderValue == 1) {
    Blynk.virtualWrite(V0, 0);  // Reset slider value in Blynk app
    Serial.println(sliderValue);
    visualButton = true;
  }
}