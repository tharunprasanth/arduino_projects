#include<SoftwareSerial.h>
//serial port power
//const int AirValue = 468;   //you need to replace this value with Value_1
//const int WaterValue = 200;  //you need to replace this value with Value_2
// power outlet
const int AirValue = 634;   //you need to replace this value with Value_1
const int WaterValue = 273;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;

SoftwareSerial bt(2,3); /* (Rx,Tx) */  

void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  bt.begin(9600); /* Define baud rate for software serial communication */
}

void loop() {
  soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
  Serial.println(soilMoistureValue);
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
//  if(soilmoisturepercent > 100)
//  {
//    Serial.println("100 %");
//  }
//  else if(soilmoisturepercent <0)
//  {
//    Serial.println("0 %");
//  }
//  else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
//  {
//    Serial.print(soilmoisturepercent);
//    Serial.println("%");
//    
//  }
  
  bt.print("value,");
  bt.print(soilMoistureValue);
  bt.print(",percent,");
  bt.println(soilmoisturepercent);
  delay(1000);
}
