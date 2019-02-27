/**
 * --------------------------------------------------------------------------
 * An Arduino humidity controller
 * See README.md for parts list.
 * --------------------------------------------------------------------------
 * Setup:
 * 
 * Board:      Arduino Nano
 * Bootloader: ATmega328P (Old Bootloader)
 * Port:       Whichever one gives works when Tools -> Get Board Info is run.
 * --------------------------------------------------------------------------
 * Pin connections for test LED:
 * 
 * 
 * --------------------------------------------------------------------------
 * Pin connections for LCD
 * (Refer to https://www.arduino.cc/en/Tutorial/HelloWorld for complete
 * instructions.)
 * 
 * LCD VSS to GND
 * LCD VDD to 5V
 * LCD V0 to 10 Kohm potentiometer wiper; potentiometer terminals to GND
 *   and 5V
 * LCD RS pin to Arduino digital pin 12
 * LCD RW pin to GND
 * LCD E pin to Arduino digital pin 11
 * LCD D4 pin to Arduino digital pin 5
 * LCD D5 pin to Arduino digital pin 4
 * LCD D6 pin to Arduino digital pin 3
 * LCD D7 pin to Arduino digital pin 2
 * LCD A pin (AKA LED+ pin) to 220 ohm resistor; resistor to 5V
 * LCD K pin (AKA LED- pin) to GND
 * --------------------------------------------------------------------------
 */

#include <LiquidCrystal.h>

// LED blink
const unsigned char LED_PIN = 13;
const unsigned short BLINK_DELAY = 1000; // ms
unsigned char pinState = 0;

// LCD screen
const unsigned char
  RS_PIN = 12,
  E_PIN = 11,
  D4_PIN = 5,
  D5_PIN = 4, 
  D6_PIN = 3,
  D7_PIN = 2;
LiquidCrystal lcd(
  RS_PIN,
  E_PIN,
  D4_PIN,
  D5_PIN,
  D6_PIN,
  D7_PIN
);
const unsigned char LCD_COLUMNS = 16;
const unsigned char LCD_ROWS = 2;

void setup() {
  
  // LED blink
  pinMode(LED_PIN, OUTPUT);

  // LCD screen
  // set up the LCD's number of columns and rows:
  lcd.begin(LCD_COLUMNS, LCD_ROWS);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  
}

void loop() {
  
  pinState = !pinState;
  digitalWrite(LED_PIN, pinState);

  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);

  delay(BLINK_DELAY);
  
}
