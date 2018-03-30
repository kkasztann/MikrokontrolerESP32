#include <Arduino.h>
int static czerwona=13;
int static zielona=12;
int static niebieska=14;

void setup() {
  Serial.begin(9600);
  pinMode(czerwona, OUTPUT); //Konfiguracja wyprowadzeń jako wyjścia
  pinMode(zielona, OUTPUT);
  pinMode(niebieska, OUTPUT);
}

void loop() {
    digitalWrite(zielona, HIGH);
    delay(500);
    digitalWrite(zielona, LOW);
    digitalWrite(niebieska, HIGH);
    delay(500);
    digitalWrite(niebieska, LOW);
    digitalWrite(czerwona, HIGH);
    delay(500);
    digitalWrite(czerwona, LOW);
    delay(500);
}
