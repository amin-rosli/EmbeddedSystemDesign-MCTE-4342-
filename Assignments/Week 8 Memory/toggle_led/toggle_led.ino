#include <EEPROM.h>
const int button = 6;
const int led = 7;

bool led_state;
bool button_state;
bool last_button = LOW;
unsigned long prev_time = millis();

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  readEEPROM();
}

void loop() {
 bool read_button = digitalRead(button);

  if(read_button != last_button) {
    prev_time = millis();
  }

  if((millis() - prev_time) > 100) {
    if(read_button != button_state) {
      button_state = read_button;
      
      if(button_state == LOW) {
        led_state = !led_state;
        EEPROM.update(0,led_state);
      }
    }
  }

  digitalWrite(led, led_state);
  last_button = read_button;
}


void readEEPROM() {
  led_state = EEPROM.read(0);
  Serial.println(led_state);
  
  if(led_state == 1){
    digitalWrite(led, HIGH);
  }else {
    digitalWrite(led, LOW);
  }
}
