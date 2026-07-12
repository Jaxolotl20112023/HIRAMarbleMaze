#include <Servo.h> 
#include "motor.h"

//  *** PLEASE DO NOT CHANGE OR TOUCH THIS CODE ***

void __init__() {

  pinMode(button1->id,INPUT_PULLUP);
  pinMode(button2->id,INPUT_PULLUP);
  pinMode(button3->id,INPUT_PULLUP);
  pinMode(button4->id,INPUT_PULLUP);
  pinMode(button5->id,INPUT_PULLUP);  

  motor1->servo.attach(motor1->port); 
  motor2->servo.attach(motor2->port); 
  motor3->servo.attach(motor3->port); 
  motor4->servo.attach(motor4->port); 
  motor5->servo.attach(motor5->port); 

  motor1->servo.write(90);
  motor2->servo.write(90);
  motor3->servo.write(90); 
  motor4->servo.write(90); 
  motor5->servo.write(90); 
}
 
void setup() {
  // ** SET THE PORTS OF YOUR MOTORS HERE ** 
  motor1->port = 2;
  motor2->port = 8; 
  motor3->port = 9; 
  motor4->port = 10; 
  motor5->port = 12;  

  // ** SET THE PORTS OF YOUR BUTTONS HERE **
  button1->id = 7;
  button2->id = 4;
  button3->id = 6;
  button4->id = 5;
  button5->id = 11;

  //  *** DO NOT CHANGE OR TOUCH THIS CODE *** 
  __init__(); 

  // *** CHANGE THE ANGLE YOU WANT YOUR MOTOR TO ROTATE ***
  motor1->rotation = 0; 
  motor2->rotation = 90; 
  motor3->rotation = 88; 
  motor4->rotation = 140;
  motor5->rotation = 90;

}

void loop() {

  // put your main code here, to run repeatedly:
  
  toggle(button1,motor1); // make a button1 a toggle button that controls motor 1

  toggle(button2,motor2);

  toggle(button3,motor3);  

  toggle(button4,motor4); 

  press(button5, motor5); // make button5 a press button that controls motor 5  

  delay(200);
}
