#include <memory>
int lastvalueMotor = 0;

void Fan(short speed /*0 to 100*/) 
{
  if (lastvalueMotor == 0 and speed > 0) 
  {
    analogWrite(motorPort, 255);
    delay(500);
  }

  int value = 0;
  if (speed > 0) { if (speed < cuttoffSpeed) {value = cuttoffSpeed;} else {value = speed;}}

  analogWrite(motorPort, map(value,0,100,0,255));
  delayMicroseconds(2);

  lastvalueMotor = value;
}