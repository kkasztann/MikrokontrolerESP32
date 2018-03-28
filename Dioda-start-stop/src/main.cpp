#include <Arduino.h>
String komenda="";
void setup()
{
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  digitalWrite(5, LOW);
  Serial.println("Wydaj polecenie dla diody: start|stop");
}

void loop()
{

    if(Serial.available()){
          komenda=Serial.readString();
          Serial.println(komenda);
    }
    //Serial.println(komenda);

    if(komenda=="start"){
         digitalWrite(5, HIGH);
         delay(100);
         digitalWrite(5, LOW);
         delay(100);
    }

    if(komenda=="stop"){
            digitalWrite(5, LOW);
    }
 }
