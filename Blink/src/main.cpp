#include <Arduino.h>
String wyraz="";
void setup()
{
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  digitalWrite(5, LOW);
}

void loop()
{
    if(Serial.available())
          {
            wyraz=Serial.readStringUntil('\n');
            Serial.println(wyraz);
          }
   if (wyraz=="szybko"){
     digitalWrite(5, HIGH);
     delay(50);
     digitalWrite(5, LOW);
     delay(50);
   }

  else if (wyraz=="wolno"){
    digitalWrite(5, HIGH);
    delay(1000);
    digitalWrite(5, LOW);
    delay(1000);
  }
  else if (wyraz=="koniec"){
    digitalWrite(5, LOW);
  }
}
