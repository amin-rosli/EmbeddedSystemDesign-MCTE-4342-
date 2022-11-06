#define trig 13
#define echo 12
#define redled 11
#define greenled 10
int max_distance = 60;

unsigned long curr_time, prev_time;
long duration, distance, distance2, fadeValue;
int brightness1, brightness2;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  curr_time = millis();

  if (curr_time - prev_time >= 100) {

    digitalWrite(trig, LOW);
    delayMicroseconds(20);
    digitalWrite(trig, HIGH);
    delayMicroseconds(20);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = (duration / 2) / 29.1;
    prev_time = millis();
  }

  if (distance > max_distance) {
    brightness1 = 0;
    brightness2 = 100;
  } else if (distance < 4) {
    brightness1 = 100;
    brightness2 = 0;
  } else {
    brightness1 = map(distance, 0, max_distance, 100, 0);
    brightness2 = map(distance, 0, max_distance, 0, 100);
  }

  analogWrite(redled, brightness1);
  analogWrite(greenled, brightness2);

  Serial.print("distance =");
  Serial.print(distance);
  Serial.print(" brightness1 =");
  Serial.println(brightness1);
}