class fade {


public:
  int brightness;
  int turn_num;
  int fadeamount;
  int ledpin;
  fade(int pin, int turn, int amount) {

    turn_num = turn;
    fadeamount = amount;
    ledpin = pin;

    brightness = 0 + (turn_num * 40);
    pinMode(ledpin, OUTPUT);
  }

  void check() {
    brightness = brightness + fadeamount;

    if (brightness <= 0 || brightness >= 100) {
      fadeamount = -fadeamount;
    }

    analogWrite(ledpin, brightness);
  }
};

fade led[] = { fade(9, 0, 5), fade(10, 1, 5), fade(11, 2, 5) };

int led_num = sizeof(led) / sizeof(led[0]);
unsigned int curr_time, prev_time;
int pot;

void setup() {
  Serial.begin(9600);
  pinMode(A5, INPUT);
}

void loop() {
  curr_time = millis();
  pot = analogRead(A5);
  pot = map(pot,0,1023,0,200);

  if (curr_time - prev_time > pot) {
    for (int a = 0; a < led_num; a++) {
      led[a].check();
    }
    prev_time = millis();
    Serial.println(pot);
  }
  delay(30);
}