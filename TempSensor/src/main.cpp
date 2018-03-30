#include <SimpleDHT.h>

int pinDHT11 = 2;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("=================================");
  Serial.println("Wynik pomiaru:");

  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }

  Serial.print("Temperatura(C): ");Serial.println((int)temperature);
  Serial.print("Wilgotnośc(%): ");Serial.println((int)humidity);

  delay(1500);
}
