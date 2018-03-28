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
  if (wyraz!="mrygaj mi tu do rana"){
    Serial.println("Napisz => mrygaj mi tu do rana");
    delay(1000);

    if(Serial.available())
          {
            wyraz=Serial.readStringUntil('\n');
            Serial.println(wyraz);
          }
 }else{
   digitalWrite(5, HIGH);
   delay(100);
   digitalWrite(5, LOW);
   delay(100);
 }



}
