const int IN1 = 7;
const int IN2 = 8;
const int ENA_PIN = 9;
int pos;
int abso = 12;
int timing = 0;
int a = 1;

void setup() {
  pinMode(ENA_PIN, OUTPUT);
  digitalWrite(ENA_PIN, HIGH);
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  int movement = random(1, 5);

}

void loop() {
  while(a==1){
    retract(10);
    random_mode();
    a=0;
  }
  
}




void random_mode() {
  unsigned long random_time = millis();
  int mode = 1;

  while (millis() - random_time < 30000) {

    if (mode > 0) {
      timing = random_ext(abso);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    } else {
      timing = random_ret(abso);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);

    } unsigned long  prev_time = millis();

    while (millis() - prev_time < timing) {
      Serial.println(millis() - prev_time);
      digitalWrite(12, HIGH);
      digitalWrite(12, LOW);
    } mode = -mode;

  }
  digitalWrite(4, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  return;
}

int random_ext(int abso) {
  int movement = random(1, 5);

  if (movement + abso > 20) {
    return movement = 0;
  } else {
    abso += movement;
    movement = movement * 1200;
    return movement;
  }
}

int random_ret(int abso) {
  int movement = random(1, 5);

  if (abso - movement < 0) {
    return movement = 0;
  } else {
    abso -= movement;
    movement = movement * 1200;

    return movement;
  }
}

void extend(int x) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(x*1200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void retract(int x) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(x*1200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
