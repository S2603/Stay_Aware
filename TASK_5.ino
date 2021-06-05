#define BlYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define TriggerPin 5
#define EchoPin 4
char auth[]=" EDU1Xrb1vq_mbkSE-8ytyNZyrnQmDMz0";
char ssid[]="Shuvo";
char pass[]="Suvo2662";
WidgetLCD lcd(V1);
void setup()
{
  Serial.begin(9600);
  pinMode(TriggerPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  Blynk.begin(auth,ssid,pass);
  lcd.clear();  //Use it to clear the LCD Widget 
}
void loop()
{
  lcd.clear();
  lcd.print(0,0,"Distance in cm");
  long duration,distance;
  digitalWrite(TriggerPin,LOW);
  delayMicroseconds(3);
  digitalWrite(TriggerPin,HIGH);
  delayMicroseconds(12);
  digitalWrite(TriggerPin,LOW);
  duration=pulseIn(EchoPin,HIGH);
  distance=(duration/2)/29.1;
  Serial.println(distance);
  Serial.println("Cm");
  if(distance<=50)
  {
   lcd.print(7,1,distance);
   Blynk.notify("Maintain Distance");
  }
  else
  {
    lcd.print(7,1,distance);
  }
  Blynk.run();
  delay(3500);
}
