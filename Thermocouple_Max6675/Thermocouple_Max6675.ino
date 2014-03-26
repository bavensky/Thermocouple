#include <LiquidCrystal.h>
#include "max6675.h"
int thermoDO = 4;
int thermoCS = 5;
int thermoCLK = 6;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
int vccPin = 8;
int gndPin = 7;

LiquidCrystal lcd(2, 9, 3, 10, 16, 14);

void setup() 
{
  Serial.begin(9600); lcd.begin(16, 2);
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);
  lcd.print("Thermocouple");
  delay(2000);
}

void loop() 
{
   lcd.setCursor(0, 1);
   lcd.print("Temp:  ");lcd.print(thermocouple.readCelsius());lcd.print("c        ");
   /*Serial.print("C = "); 
   Serial.println(thermocouple.readCelsius());
   Serial.print("F = ");
   Serial.println(thermocouple.readFahrenheit());*/
   delay(1000);
}
