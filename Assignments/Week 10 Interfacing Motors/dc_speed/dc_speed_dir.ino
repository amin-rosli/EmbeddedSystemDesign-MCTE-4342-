#define in1 0
#define in2 1
#define cw 2
#define ccw 3
#define motor_speed 5
#define pot A5

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(cw, INPUT_PULLUP);
  pinMode(ccw, INPUT_PULLUP);
  pinMode(motor_speed, OUTPUT);
  pinMode(pot, INPUT);

}
int dir = 0;

void loop() {
  if (digitalRead(cw) == LOW)
    dir = 0;

  if (digitalRead(ccw) == LOW)
    dir = 1;

  if (dir == 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (dir == 1) {
    digitalWrite(in2, HIGH);
    digitalWrite(in1, LOW);
  }

  int val = analogRead(pot); 
  int speed_val = map(val,0,1023,0,255);
  analogWrite(motor_speed,speed_val);

}
