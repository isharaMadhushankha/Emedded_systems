#include <Arduino.h>

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int x;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);

  lcd.setCursor(3,0);
  lcd.print("Lcd isready..");
  delay(500);
  lcd.clear();

}

void loop() {
  x = analogRead(A0);
  if(x<200){
    Serial.print("sencer value");
    Serial.println(x);
    lcd.setCursor(3,0);
    lcd.print("Sencer value:");
    lcd.setCursor(3,1);
    lcd.print(x);
    digitalWrite(13, HIGH);
    delay(500);
    lcd.clear();
  }

}
