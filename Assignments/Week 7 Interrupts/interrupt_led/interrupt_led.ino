#define button 2
#define led 4
volatile byte buttonstate = 0;
byte ledstate = 0;
unsigned long prev_time;


void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(button), led_ISR , RISING);
}

void loop() {
  unsigned long curr_time = millis();
  digitalWrite(led, ledstate);
  if (curr_time - prev_time > 100 && buttonstate) {
    if (digitalRead(button) == 0 ) {
      ledstate = !ledstate;
      prev_time = millis ();
      buttonstate = 0;
    }
  }
}

void led_ISR() {
  buttonstate = 1;
}
