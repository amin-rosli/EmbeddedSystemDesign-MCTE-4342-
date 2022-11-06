#include "pitches.h"
#define pot A0
#define buzzer 8
#define but1 1
#define but2 2
#define but3 3
#define but4 4
#define but5 5

void setup() {
  pinMode(but1, INPUT_PULLUP);
  pinMode(but2, INPUT_PULLUP);
  pinMode(but3, INPUT_PULLUP);
  pinMode(but4, INPUT_PULLUP);
  pinMode(but5, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

int notes [5][5] = {
  {NOTE_A1, NOTE_B1, NOTE_C1, NOTE_E1, NOTE_F1},
  {NOTE_A2, NOTE_B2, NOTE_C2, NOTE_E2, NOTE_F2},
  {NOTE_A3, NOTE_B3, NOTE_C3, NOTE_E3, NOTE_F3},
  {NOTE_A4, NOTE_B4, NOTE_C4, NOTE_E4, NOTE_F4},
  {NOTE_A5, NOTE_B5, NOTE_C5, NOTE_E5, NOTE_F5}
};

int buttons[] = {
  1, 2, 3, 4, 5
};

void loop() {
  int pot_val = analogRead(pot);
  int pitch = map(pot_val, 0, 1023, 0, 5);



  for (int a = 0; a < 5; a++) {
    int pressed = digitalRead(buttons[a]);

    if (pressed == LOW) {
      tone(buzzer, notes[a][pitch]);
      delay(300);
    }
    else {
      noTone(buzzer);
    }
  } 

}
