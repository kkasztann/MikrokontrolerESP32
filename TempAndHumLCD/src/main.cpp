#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SimpleDHT.h>

int pinDHT11 = 2;
SimpleDHT11 dht11;
LiquidCrystal_I2C lcd(0x27,21,22);

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temperatura: null");
  lcd.setCursor(0,1);
  lcd.print("Wilgotnosc: null");
}

void loop() {

  byte temperature = 0;
  byte humidity = 0;
  byte sTemp;
  byte sHumi;

  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    lcd.setCursor(0,0);
    lcd.print("ReadDHT11failed");
    lcd.setCursor(0,1);
    lcd.print("Err="); lcd.print(err);
    delay(1000);
    return;
  }


  if (temperature!=sTemp){
    // Temperatura na LCD
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Temperatura:");
    lcd.setCursor(13,0);
    lcd.print((int)temperature);
    lcd.setCursor(15,0);
    lcd.print("C");
  }

  if (humidity!=sHumi){
    // Wilgotnosc na LCD
    lcd.setCursor(0,1);
    lcd.print("               ");
    lcd.setCursor(1,1);
    lcd.print("Wilgotnosc:");
    lcd.setCursor(13,1);
    lcd.print((int)humidity);
    lcd.setCursor(15,1);
    lcd.print("%");
  }

  // Temperatura i wilgotnośc na Serialu
  Serial.println("=================================");
  Serial.println("Wynik pomiaru:");
  Serial.print("Temperatura(C): ");Serial.println((int)temperature);
  Serial.print("Wilgotnosc(%): ");Serial.println((int)humidity);

   sTemp=temperature;
   sHumi=humidity;

  delay(1500);
}
