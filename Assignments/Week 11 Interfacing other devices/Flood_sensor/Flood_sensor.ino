#define BLYNK_PRINT Serial
#include <SimpleTimer.h>
SimpleTimer timer;

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define TRIGGERPIN D1
#define ECHOPIN	D2

char auth[] = "authkey";
char ssid[] = "wifiname";
char pass[] = "wifipassword";
int noti=0;

WidgetLCD lcd(V1);

void setup()
{
  // Debug console

  Serial.begin(9600);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Blynk.begin(auth, ssid, pass);

  lcd.clear();
  lcd.print(0, 0, "Distance in cm");
}

void loop()
{
  lcd.clear();
  lcd.print(0, 0, "Water distance");
  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3);
 
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12);
 
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);

  if (distance<=10 && noti==0){
	Blynk.email("email address","Flood Sensor Alert","Distance between water and sensor is less than 10cm");
	noti=1;
  }
  timer.setInterval(1800000,resetnoti);
 
  Serial.println("Cm");
  lcd.print(0, 1, distance);
  lcd.print(5, 1, "cm");
 
  Blynk.run();

  delay(1000);

}

void resetnoti()
{
  noti=0;
}
