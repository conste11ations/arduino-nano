
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x3f, 20, 4);

const int AirValue = 620;   //you need to replace this value with Value_1
const int WaterValue = 310;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;

void setup()
{
    Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
	lcd.begin();
}

void loop()
{
  soilMoistureValue = analogRead(A0);
  Serial.println(soilMoistureValue);
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  
  if(soilmoisturepercent > 100) {
    Serial.println("100 %");
    lcd.setCursor(0, 0);
    lcd.print("Soil Moisture");
    lcd.setCursor(0, 1);
    lcd.print("100 %");
  } else if(soilmoisturepercent <0) {
    Serial.println("0 %");
    lcd.setCursor(0, 0);
    lcd.print("Soil Moisture");
    lcd.setCursor(0, 1);
    lcd.print("0 %");
  } else {
    //else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
    Serial.print(soilmoisturepercent);
    Serial.println("%");
    lcd.setCursor(0, 0);
    lcd.print("Soil Moisture");
    lcd.setCursor(0, 1);
    lcd.print(soilmoisturepercent);
    lcd.print(" %");
  }
    delay(1000);
    lcd.clear();
  
  
  delay(500);
}
