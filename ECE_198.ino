#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

float sensor_volt = 0;
float RS = 0;           //  Get the value of RS via in a clear air
float R0 = 0;           // Get the value of R0 via in Alcohol
float sensorValue = 0;

void setup() {
  lcd.init();       // Initialize the LCD display screen
  lcd.backlight();  // Turn on backlight of LCD display screen.
  pinMode(A0, INPUT);
}

void loop() {
  for (int i = 0 ; i < 100 ; i++) {
    sensorValue = sensorValue + analogRead(A0);
  }
  delay(10);
  sensorValue = sensorValue / 100.0;      //get average of reading
  sensor_volt = sensorValue / (1024 * 5.0);
    lcd.setCursor(1, 0);          // Go to position column 2 & row 1
  lcd.print("Volt: ");
  lcd.print(sensor_volt);

  RS = (5.0 - sensor_volt) / sensor_volt;
  R0 = RS / 50.0;                         //50 is found using interpolation from the graph
  lcd.setCursor(0, 1);          // Go to position column 1 & row 2
  lcd.print("R0 = ");
  lcd.println(R0, 5);
  delay(100);
  lcd.clear();               // Clear LCD display screen
  sensorValue = 0;

}
