//Code -->to get temperature from arduino and display on LED......

#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

void setup(){
  pinMode(A0,INPUT);// A0--> Input PIN
  lcd.begin(16,2);
}

void loop(){
  float samples=analogRead(A0);
  //each digital sample could be 5v/1024 Volts
  
  float analog_voltage_of_Samples=samples*5/1024;
  //Each 10mV(0.01V) givem ny LM35 is change in 1 degree
  
  //how many such degree C in given volatge read from LM35
  float temp=analog_voltage_of_Samples/0.01;
  
  lcd.setCursor(0,0);
  lcd.print(temp);
  lcd.setCursor(7,0);
  lcd.print("Deg C");
  
  delay(1000); 
  // Delay for1 1s
}

