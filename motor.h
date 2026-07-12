#pragma once

#include <Arduino.h>
#include <Servo.h>

#define MOTOR_TO_TIME 730.666/180.00

typedef struct
{
  Servo servo;
  double rotation; 
  int port; 
} Motor; 

typedef struct Button 
{
  int id; 
  int pressed;
} Button; 

void move1(Motor *motor )
{
  double time = fabs((motor->rotation) * (MOTOR_TO_TIME));
  Serial.println(time);
  if (motor->rotation < 0) 
  {
    motor->servo.write(0); 
  } else if (motor->rotation > 0)
  {
    motor->servo.write(180);     
  } 
  delay(time); 
  motor->servo.write(90);
  // delay(500);
}

int toggle(Button *button, Motor *motor) {

  
  if(!digitalRead(button->id))
  {
    if(motor->rotation != 0) {
      motor->rotation = -1*motor->rotation; 
      if (button->pressed == 1) {
        button->pressed = 0; 
        move1(motor); 
        // move1(motor1); 
      } else {
        button->pressed = 1; 
        move1(motor); 
        // move1(motor1); 
      }
      delay(200);
    } else {
      if (button->pressed == 1) {
        button->pressed = 0; 
        
        motor->servo.write(0); 
        // move1(motor1); 
      } else {
        button->pressed = 1; 
        motor->servo.write(180); 
        // move1(motor1); 
      }
      // delay(200);
      }
    return 1; 
  }

  return 0; 
}

int press(Button *button, Motor *motor) { 

  if(!digitalRead(button->id) && button->pressed == 0)
  {
    button->pressed = 1;  
    move1(motor); 
    // delay(200);
    
    button->pressed = 0; 

    return 1; 

  }

  return 0; 
}

Button BUTTON_1 = {7,0}; 
Button BUTTON_2 = {4,0}; 
Button BUTTON_3 = {6,0}; 
Button BUTTON_4 = {5,0}; 
Button BUTTON_5 = {11,0}; 

Button *button1 = &BUTTON_1;
Button *button2 = &BUTTON_2;
Button *button3 = &BUTTON_3;
Button *button4 = &BUTTON_4;
Button *button5 = &BUTTON_5;

Motor s_motor1;
Motor s_motor2; 
Motor s_motor3;
Motor s_motor4; 
Motor s_motor5; 

Motor *motor1 = &s_motor1;
Motor *motor2 = &s_motor2; 
Motor *motor3 = &s_motor3;
Motor *motor4 = &s_motor4; 
Motor *motor5 = &s_motor5;




