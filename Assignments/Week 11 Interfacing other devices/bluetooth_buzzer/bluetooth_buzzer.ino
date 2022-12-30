char data = 0;
#include "pitches.h"
#define buzzer 8

void setup() {
  Serial.begin(38400);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) 
  {
    data = Serial.read();      
    Serial.print(data);        
    Serial.print("\n");      
    if (data == '1')           
      tone(buzzer, 1047); 
    else if (data == '0')   
      noTone(buzzer);   

    delay(20);
  }
}
