
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper stepperL(stepsPerRevolution, 8, 9, 10, 11);
Stepper stepperR(stepsPerRevolution, 4, 5, 6, 7);

int startX = 0;
int startY = 0;

void setup() {
  // set the speed at 60 rpm:
  stepperL.setSpeed(30);
  stepperR.setSpeed(30);
  startX = map(analogRead(0),0,1023,-1,1);
  startY = map(analogRead(1),0,1023,-1,1);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  
  int vrx = map(analogRead(0),0,1023,-1,1) - startX;
  int vry = map(analogRead(1),0,1023,-1,1) - startY;

  Serial.print("stepl: ");
  Serial.print(vrx); 
  Serial.print("  step2: ");
  Serial.println(vry); 


  if (vrx != 0)
    stepperL.step((int)(vrx));

  if(vry != 0)
      stepperR.step((int)(vry));
  

}
