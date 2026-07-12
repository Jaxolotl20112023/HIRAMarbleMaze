#pragma once 

#include <Arduino.h>
#include <time.h>

typedef struct PhotoResist {
  int port;
  int sensitivity; 
  int curr_light_val;
  int past_light_val; 
} PhotoResist;

typedef struct LED { 
  int port; 
} LED; 

void on(LED led) {
  digitalWrite(led.port,HIGH); 
}

void off(LED led) {
  digitalWrite(led.port,LOW); 
}

LED led = {13};
void photoDetect(PhotoResist* photoResist) {
  photoResist->past_light_val = analogRead(photoResist->port); 

  delay(100); 

  photoResist->curr_light_val = analogRead(photoResist->port); 

  if (photoResist->past_light_val - photoResist->curr_light_val >= photoResist->sensitivity) {
    on(led);
  } else {
    off(led); 
  }
}

PhotoResist tempResist;
PhotoResist* photoResist = &tempResist;