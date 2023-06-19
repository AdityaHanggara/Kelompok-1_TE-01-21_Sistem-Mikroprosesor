#include "arduino_secrets.h"
#include <LiquidCrystal.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "thingProperties.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  // Initialize serial and wait for port to open:
   Serial.begin(9600);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  initProperties();
  lcd.init();
  lcd.backlight();

  
  
  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
 ArduinoCloud.update();
  // Your code here 
  lcd.setCursor(0,0);
  lcd.print("Welcome");
  lcd.setCursor(0,1);
  lcd.print("SMART HOME");
  delay (100);
  lcd.clear();
  }

void onRelay1Change()  {
  
  if(relay1 == HIGH) {
    digitalWrite(D3, LOW);
    lcd.setCursor(0,0);
    lcd.print("Door Home");
    lcd.setCursor(0,1); 
    lcd.print("Access Granted");
    delay(10000);
    lcd.clear();
  }
  else{
  
    digitalWrite(D3, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Door Home");
    lcd.setCursor(0,1); 
    lcd.print("Access Closed");
    delay(10000);
    lcd.clear();
  }
  
}

void onRelay2Change()  {
  if(relay2)
    digitalWrite(D4, LOW);
  
  else
    digitalWrite(D4, HIGH);
    
}
