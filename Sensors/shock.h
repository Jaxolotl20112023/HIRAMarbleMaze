#pragma once 
#include "photoresist.h"

typedef struct Shock {
  int port; 
  int state; 
} Shock; 

void shockDetect(Shock* shock) {

  shock->state = digitalRead(shock->port); 

  if (shock->state == HIGH) {
    on(led); 
    delay(500); 
  } else off(led); 
}

Shock tempShock;
Shock *shock; 
