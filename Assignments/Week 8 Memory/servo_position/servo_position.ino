#include <Servo.h>
#include <EEPROM.h>

const int pot = A0;
const int button1 = 3;
const int button2 = 4;
const int button3 = 5;
const int mode_led = 7;
const int mode_button = 2;

bool button_state;
bool last_button = LOW;
unsigned long prev_time = millis();
bool mode_state = LOW;
int potval;

Servo servo;
void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(mode_button, INPUT_PULLUP);
  pinMode(mode_led, OUTPUT);
  servo.attach(10);
}

void loop() {
  bool mode_read = digitalRead(mode_button);

  if (mode_read != last_button) {
    prev_time = millis();
  }

  if ((millis() - prev_time) > 100) {
    if (mode_read != button_state) {
      button_state = mode_read;

      if (button_state == LOW) {
        mode_state = !mode_state;
        digitalWrite(mode_led, mode_state);
      }
    }
  }
  last_button = mode_read;
  if (mode_state == LOW ) {
    reader();
  } else if (mode_state == HIGH) {
    writer();
  }

}

void writer() {
  potval = analogRead(pot);
  potval = map(potval, 0, 1023, 0, 180);
  servo.write(potval);
  if (digitalRead(button1) == LOW) {
    EEPROM.update(0, potval);
  }
  else if (digitalRead(button2) == LOW)
  {
    EEPROM.update(1, potval);
  }
  else if (digitalRead(button3) == LOW)
  {
    EEPROM.update(2, potval);
  }
  return;
}

void reader() {
  if (digitalRead(button1) == LOW) {
    potval = EEPROM.read(0);
    servo.write(potval);
  }
  else if (digitalRead(button2) == LOW)
  {
    potval = EEPROM.read(1);
    servo.write(potval);
  }
  else if (digitalRead(button3) == LOW)
  {
    potval = EEPROM.read(2);
    servo.write(potval);
  }
  return;
}
