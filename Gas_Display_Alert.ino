
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sv=0;

void setup() {
  
  lcd.begin(16, 2);
  lcd.print("Gas level: ");
  pinMode(6,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(6, LOW);
  sv = analogRead(A0);
  lcd.setCursor(11, 0);
  lcd.print(sv);
  Serial.println(sv);
  lcd.setCursor(0, 1);
  if (sv<550){
    lcd.print("Normal");}
  else if (sv>550 and sv<700){
    lcd.print("Medium");}
  else{
    lcd.print("DANGER");
    digitalWrite(6, HIGH);}
  delay(100);
}
 