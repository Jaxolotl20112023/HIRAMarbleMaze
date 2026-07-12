#include "photoresist.h"
#include "shock.h"
#include <stdio.h>

// ** DO NOT TOUCH **
void __init__() {
  photoResist->sensitivity = 5; 
  photoResist->curr_light_val = 0;
  photoResist->past_light_val = 0; 

  shock->state = LOW; 
}

void setup() {
  // put your setup code here, to run once:

  __init__();

  // ** CHANGE TO THE PORT YOU PLUG YOUR PHOTO_RESISTOR IN **
  photoResist->port = A5; 
  shock->port = 2; 
   

}

void loop() {
  // put your main code here, to run repeatedly:

  // DETECT MOTION USING THE PHOTORESISTOR
  photoDetect(photoResist); 

  // DETECT VIBRATIONS USING SHOCK
  shockDetect(shock); 

}
