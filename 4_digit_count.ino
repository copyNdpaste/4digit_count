#include "TM1637.h"

#define TOUCH_SENSOR 3//the touch sensor is connected with D3 of Arduino/Catduino

#define CLK 4//pins definitions for the module and can be changed to other ports       
#define DIO 2
TM1637 disp(CLK,DIO);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TOUCH_SENSOR, INPUT);
   disp.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
  disp.init(D4056A);//D4056A is the type of the module
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorValue = digitalRead(TOUCH_SENSOR);
int count=0;
  if(sensorValue)
  {
    count++;
    disp.display(count);
    }
}
