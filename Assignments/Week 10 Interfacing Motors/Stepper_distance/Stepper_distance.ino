#include <Stepper.h>                                  // Header file for stepper

#define STEPS 2038                                    // Steps for a single revolution

Stepper stepper(STEPS, 4, 5, 6, 7);                   // Input for ULN2003 Motor driver
const int pot = A1;                                   // Initialise potentiometer

void setup() {

  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  stepper.setSpeed(10);                               // Set speed for the stepper motor

}

void loop() {
  int potVal = map(analogRead(pot),0,1024,0,2038);    // Convert potentiometer in terms of steps for a revolution
  Serial.println(potVal);
  
  if (digitalRead(2) == LOW) {
    stepper.step(potVal);                             // Steps for the stepper motor to move
  }
}
