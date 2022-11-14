#define pot A0

void setup() {
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  int pot_val = analogRead(pot);
  unsigned int dur = map(pot_val,0,1023,0,5000);
  Serial.println(dur);
  
  PORTD|= 0b10000000;
  delayMicroseconds(dur);
  PORTD&= 0b01111111;
  delayMicroseconds(1000);
}
