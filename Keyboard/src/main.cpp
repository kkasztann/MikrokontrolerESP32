#include <Keypad.h> //biblioteka od klawiatury

const byte ROWS = 4; // ile wierszy
const byte COLS = 4; //ile kolumn

byte rowPins[ROWS] = {27, 14, 12, 13}; //piny wierszy
byte colPins[COLS] = {26, 25, 33, 32}; //piny kolumn


char keys[ROWS][COLS] = { //mapowanie klawiatury
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

String wpisano=" ";
bool dopisano=false;

Keypad klawiatura = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //inicjalizacja klawiatury

void setup(){
  Serial.begin(9600);
}

void loop(){
  char klawisz = klawiatura.getKey();

  if (klawisz){
    Serial.print("Wciśnięto: ");
    Serial.println(klawisz);
    dopisano=true;
  }

  if (dopisano){
    wpisano+=klawisz;
    Serial.println("Dotychczas wpisano:"+wpisano);
    dopisano=false;
  }
}
