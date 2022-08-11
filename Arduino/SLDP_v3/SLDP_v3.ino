
#define FORCE_SENSOR_PIN A0

#include <LiquidCrystal.h>
#include <Wire.h> // Must include Wire library for I2C
#include "SparkFun_MMA8452Q.h" // Includes the SFE_MMA8452Q library

// Default MMA8452Q object create. (Address = 0x1D)
// include the library code:


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
MMA8452Q accel;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Wire.begin();
  // Print a message to the LCD.
  //lcd.print("Check Down");
  accel.init();
}

void loop() {

 // lcd.begin(16, 2)
  
  /*
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
*/
// pin of force sensor:1,2,3
  int accel_reading = 0;
//  if (true){
//    int x = accel.getX();
//    int y = accel.getY();
//    int z = accel.getZ();
//    int accel_reading = pow((1/2), (x + y + z ));
//  }
//  
  int analogReading0 = analogRead(0);
  int analogReading1 = analogRead(1);
  int analogReading2 = analogRead(2);
  int result = 0;
  String direction;
  if (analogReading0 < 10 && analogReading1 < 10 && analogReading2 < 10){
    lcd.println(" Try again");
  } 
  else {
    if (analogReading0 >= analogReading1 && analogReading0 >= analogReading2 ){
      result = analogReading0;
      direction = "top";
    } 
    else if (analogReading1 >= analogReading0 && analogReading1 >= analogReading2){
      result = analogReading1;
      direction = "sweet spot";
    } 
    else if (analogReading2 >= analogReading0 && analogReading2 >= analogReading1){
      result = analogReading2;
      direction = "bottom";
    }
 
  }
   lcd.setCursor(0,1);
   lcd.print(direction);
   lcd.setCursor(0,0);
   lcd.print(result);
   lcd.print("  ");
   lcd.print(accel.getY());
  delay(1000);

  lcd.clear();

}
 
