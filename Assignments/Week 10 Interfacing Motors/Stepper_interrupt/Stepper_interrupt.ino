#include <Stepper.h>

#define STEPS 2038
#define pot A1
#define start 2
#define limit 3

Stepper stepper(STEPS, 4, 5, 6, 7);
volatile byte stopval = 0;


void setup() {
  Serial.begin(9600);
  pinMode(start, INPUT_PULLUP);
  pinMode(limit, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(limit), stopstep, RISING);
  stepper.setSpeed(10);
}

void loop() {
  if (digitalRead(2) == LOW)                                        // Checks if start button is pushed
    stopval = 1;                                                    // Set stopval as 1

  if (stopval == 1)                                                 // Checks if stopval is 1
    stepper.step(1);                                                // Runs the stepper motor
}

void stopstep() {                                                   // Interrupts schedule
  stopval = 0;                                                      // Set stopval as 0
}
