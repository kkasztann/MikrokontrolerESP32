#include <Arduino.h>

int Trig = 2;
int Echo = 4;
int CM;        //odległość w cm
long CZAS;     //długość powrotnego impulsu w uS

int static czerwona=13;
int static zielona=12;
int static niebieska=14;


void pomiar_odleglosci ()
{
  digitalWrite(Trig, LOW);        //ustawienie stanu wysokiego na 2 uS - impuls inicjalizujacy
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);       //ustawienie stanu wysokiego na 10 uS - impuls inicjalizujacy
  delayMicroseconds(15);
  digitalWrite(Trig, LOW);
  digitalWrite(Echo, HIGH);
  CZAS = pulseIn(Echo, HIGH);
  CM = CZAS / 58;                //szerokość odbitego impulsu w uS podzielone przez 58 to odleglosc w cm
}

void zgas(){
  digitalWrite(czerwona, LOW);
  digitalWrite(zielona, LOW);
  digitalWrite(niebieska, LOW);
}

void setup()
{
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);                     //ustawienie pinu w Arduino jako wyjście
  pinMode(Echo, INPUT);                      //ustawienie pinu  w Arduino jako wejście

  pinMode(czerwona, OUTPUT);
  pinMode(zielona, OUTPUT);
  pinMode(niebieska, OUTPUT);
  zgas();

  Serial.println("Test czujnika odleglosci");
}


void loop()
{
  pomiar_odleglosci();
  Serial.print("Odleglosc: ");
  Serial.print(CM);
  Serial.println(" cm");
  delay(200);

  if (CM<=10) {
    zgas();
    digitalWrite(zielona, HIGH);
  }
  else if (CM>10 && CM<=100){
    zgas();
    digitalWrite(czerwona, HIGH);
  }
  else if (CM>100){
    zgas();
    digitalWrite(niebieska, HIGH);
  }
}
