/* Water Level Sensor [S028] : http://rdiot.tistory.com/60 [RDIoT DEMO] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
int analogPin = 0;    // water sensor
int led = 13;         
int val = 0;          
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  pinMode(led, OUTPUT);
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S028:Water");
  
  val = analogRead(analogPin);   
 
  lcd.setCursor(0,1);
  lcd.print("val=" + (String)val + "  ");
 
  if (val > 650)                 
  {                               
      digitalWrite(led, HIGH);   // LED ON
      lcd.setCursor(0,2);
      lcd.print("LED=ON (val>650)");
 
  }
  else                           
  {
      digitalWrite(led, LOW);    // LED OFF
      lcd.setCursor(0,2);
      lcd.print("LED=OFF            ");
 
  }
  delay (500);
 
}
