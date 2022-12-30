#include <SPI.h>
#include <SD.h>
#define trig 6
#define echo 5
#define chipSelect 4
#define button 2
File testFile;

Sd2Card card;
SdVolume volume;
SdFile root;

unsigned long curr_time, prev_time, duration;
int distance;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    while (1);
  }
  Serial.println("card initialized.");

  if (SD.exists("test.txt")) {
    Serial.println("test.txt exists");
  } else Serial.println("test.txt doesnt exists");
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
  Serial.println(distance);

  testFile = SD.open("test.txt", FILE_WRITE);
  if (testFile) {
    testFile.println(String(distance));
    testFile.close();
    Serial.println(distance);
  } else {
    Serial.println("error opening test.txt");
  }

  delay(10);

  if (digitalRead(button) == LOW) {
    testFile.close();
    while (1);
  }
}
