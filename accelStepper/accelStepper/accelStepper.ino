#include <AccelStepper.h>
#include <movingAvg.h>


const int stepsPerRevolution = 200;

// initialize the stepper library on pins 8 through 11:
AccelStepper stepper1(AccelStepper::FULL4WIRE, 8, 9, 10, 11);
AccelStepper stepper2(AccelStepper::FULL4WIRE,  4, 5, 6, 7);

int range = 50;
int lastX = 0;
int lastY = 0;
int startX = 0;
int startY = 0;
float alpha = 0.8;
int reading  = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  lastX = analogRead(0);
  startX = lastX;
  lastY = analogRead(1);
  startY = lastY;
  stepper1.setMaxSpeed(500.0);
  stepper1.setAcceleration(300.0);

  stepper2.setMaxSpeed(500); 
  stepper2.setAcceleration(300.0);  


}

void loop() {

  reading = analogRead(0);
  int vrx = alpha * reading + (1 - alpha) * lastX;
  lastX = reading;
  reading = analogRead(1);
  int vry = alpha * reading + (1 - alpha) * lastY;
  lastY = reading;

  vrx = vrx - startX;
  vry = vry - startY;
  vrx = map(vrx,-530,530,-range,range);
  vry = map(vry,-530,530,-range,range);
  

  
  Serial.print("stepl: ");
  Serial.print(vrx); 
  Serial.print("  step2: ");
  Serial.println(vry); 
  
  stepper1.move(vrx);
  stepper2.move(vry);

      
  stepper1.run(); 
  stepper2.run();
}
