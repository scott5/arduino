#include <LiquidCrystal_I2C.h>
#include <Wire.h>


const byte lcdAddr = 0x27;  // Address of I2C backpack
const byte lcdCols = 20;    // Number of character in a row
const byte lcdRows = 4;     // Number of lines

int windowLength = lcdCols;
char blank[] = "                    "; // 20 blanks will clean a line


// Set up the display
LiquidCrystal_I2C lcd(lcdAddr, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// Demo parameters
const char sensorID[]= "Garage";
const int readDelay = 10000; // how long to wait between sensor reads

void setup() {
  lcd.begin(lcdCols, lcdRows, LCD_5x8DOTS);
  lcd.backlight(); // Turn on the backlight
  lcd.setCursor(0,0);
  lcd.print(sensorID);
  lcd.setCursor(0,1);
  lcd.print("2018-12-21 18:15:31"); // We need an RTC module to get actual time
  lcd.setCursor(0,2);
  lcd.print("Temp: --C");
  lcd.setCursor(0,3);
  lcd.print("Humi: --%");  
}

void loop() {
  int degC;
  int pctH;
  
  delay(readDelay);
  degC = random(10, 20);
  pctH = random(35,80);
  lcd.setCursor(6,2);
  lcd.print(degC);
  lcd.setCursor(6,3);
  lcd.print(pctH);
}
