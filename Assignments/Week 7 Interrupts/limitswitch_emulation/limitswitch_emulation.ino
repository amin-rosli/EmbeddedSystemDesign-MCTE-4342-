#define on 2
#define limitsw 5
#define motorstart 8
#define motorspeed 9

volatile byte motorstop = 0;

void setup() {
  pinMode(on, INPUT_PULLUP);
  pinMode(limitsw, INPUT_PULLUP);
  pinMode(motorstart, OUTPUT);
  pinMode(motorspeed, OUTPUT);
  analogWrite(motorspeed, 60);
  attachInterrupt(digitalPinToInterrupt(limitsw), limitsw_ISR, FALLING);
}

void loop() {
  if (digitalRead(on) == 0) {
    digitalWrite(motorstart,HIGH);
  }

  if (motorstop == 1) {
    digitalWrite(motorstart,LOW);
    motorstop = 0;
  }

}

void limitsw_ISR() {
  motorstop = 1;
}
