#include <TimeLib.h>

#include "DHT.h"  
#define DHTTYPE DHT11
uint8_t DHTPin = 2; 
// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);
unsigned long temp[] = {69, 68, 68, 68, 67, 68, 68, 68, 68, 69, 69, 69, 70, 70, 71, 72, 72, 71, 70, 69, 69, 69, 69, 69, 68};   
unsigned lighting = 0;
int sensorValue = 0;
 void setup()  
 {  
  pinMode(DHTPin, INPUT);
  dht.begin();
  pinMode(A0, INPUT);
  Serial.begin(9600); 
  randomSeed(now());
  //pinMode(3, OUTPUT);
  //pinMode(4, OUTPUT);
  //pinMode(6, OUTPUT);
  //analogWrite(3, 0);
  //analogWrite(5, 0);
  //analogWrite(6, 0);

  delay(5000); 
 }  
 void loop()  
 {  
   int humidity = dht.readHumidity(); /* Get humidity value */
  int temperature = dht.readTemperature();
  
   Serial.print(temp[hour()] + 0.01*random(100));
   lighting = Serial.parseInt()*255*0.1;
   led_out(lighting);
   sensorValue = analogRead(A0);
   Serial.println(sensorValue);

   delay(5000);
 }

 void led_out(unsigned lighting){
    //analogWrite(3, lighting);
    //analogWrite(5, lighting);
    analogWrite(6, lighting);
    Serial.print(",");  
    Serial.print(lighting);
    Serial.print(",");  

 }
