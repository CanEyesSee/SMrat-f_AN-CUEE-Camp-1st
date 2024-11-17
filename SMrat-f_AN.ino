/* GPIO */

 /* Display */
  #define CLK 16
  #define DIO 17

 /* Button */
  // Pin of button
  #define buttonPin 21

 /* DHT22(Temp Sensor) */
  #define DHTPIN 5
  #define DHTTYPE DHT22

 /* Fan(Motor) */
  //GPIO pin of motor
  #define motorPort 13


//////////////////////////////////////////////////////

/* Information setup/tunning/addition */

 /* Debug */
  // Debug console
  #define debugAble true

 /* Wifi and Blynk */
  //Wifi
   const char* ssid = "PS";
   const char* pass = "N5pvcc@52";

  //Blynk
   #define BLYNK_TEMPLATE_ID "TMPL6lqNdImUu"  
   #define BLYNK_TEMPLATE_NAME "SmartFanWifi" 
   #define BLYNK_AUTH_TOKEN "J7uDa7k_Gi9Up_1SNJgQMSpj7HttxPS9" // auth token
   const char* auth = BLYNK_AUTH_TOKEN;

 /* Button */
  // Time of long press <ms>
  #define longPressTime 1500 

 /* Motor */
  // Lowest speed
  #define cuttoffSpeed 45

 /* Temp (DHT22) */
  int TempDHT22;

 /* Display */
  //Show up time of state <ms>
  #define uptimeState 2000

 /* Main */
  // System
  // 0 : sleep
  // 1 : on duty
  int modeMain = 0;
  // Fan mode
  // 0 : Auto
  // 1,2,3 : Fan speed(Manual)
  int modeFan = 0;


//////////////////////////////////////////////////////

//Include lib/ Func

 /* wifi and Blynk*/
  #include <WiFi.h>
  #include <WiFiClient.h>
  #include <BlynkSimpleEsp32.h> 
  #include "blynk_WifiFunc.h"

 /* Display */
  #include <Arduino.h>
  #include <TM1637Display.h>
  #include "DisplayFunc.h"

 /* Button */
  #include "ButtonFunc.h"

 /* DHT22(Temp Sensor) */
  #include <Adafruit_Sensor.h>
  #include <DHT.h>
  #include <DHT_U.h>
  #include "DHT22Func.h"

 /* Motor */
  #include "FanFunc.h"

 /* mode */
  #include "modeFunc.h"

 /* Display Function */
  #include "DisplayC.h"

 /* ฺbutton Detect */
  #include "ButtonC.h"

//////////////////////////////////////////////////////

void setup() {
  // run once:

  // Debug return
   //if (debugAble) { Serial.begin(9600); } 
   #if (debugAble)
   Serial.begin(9600);
   #endif
    Serial.println(". ");

  // Set pin
   /* Button */
     pinMode(buttonPin, INPUT_PULLUP);  // Set the pin to pull up type

  // Preset of func
    /* DHT22 */
      dht.begin();

  // wifi 
    /* blynk */
      Blynk.begin(auth, ssid, pass, "blynk.cloud",80);
}

void loop() {
  //Reflesh data : Temp
  TempDHT22 = temp();

  //Refresh Blynk
    Blynk.run();
  
  //Check button
    modeChange();

  //Reflesh Screen
    showDisplay();

  delay(10);


  if (modeMain) {Modefan(modeFan);} 
  else 
  {
    Fan(0); //Shut oof fan
  }
  
}
