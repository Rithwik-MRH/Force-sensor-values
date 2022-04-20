#include <LiquidCrystal.h>

int contrast = 75;
const int forcePin = A0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(forcePin,INPUT);
  analogWrite(6,contrast);
  Serial.println("Health Monitoring Of Spine");
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("HMS");
  lcd.setCursor(0,1);
  lcd.print("-Shoe");
  delay(3000);
  lcd.clear();
}
void loop() {
  // put your main code here, to run repeatedly:
  int forceReading = analogRead(forcePin);
  Serial.println(forceReading);
  lcd.print(forceReading);
  delay(1000);
  lcd.clear();
}
