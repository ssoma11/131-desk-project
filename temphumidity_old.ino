#include <TimeLib.h>

#include "DHT.h"  
#define DHTTYPE DHT11
uint8_t DHTPin = 2; 
// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);
unsigned long temp[] = {69, 68, 68, 68, 67, 68, 68, 68, 68, 69, 69, 69, 70, 70, 71, 72, 72, 71, 70, 69, 69, 69, 69, 69, 68};   
 void setup()  
 {  
  pinMode(DHTPin, INPUT);
dht.begin();
  Serial.begin(9600); 
  randomSeed(now());

  delay(5000); 
 }  
 void loop()  
 {  
   int humidity = dht.readHumidity(); /* Get humidity value */
  int temperature = dht.readTemperature();
   //Serial.println("Temperature in C:");  
   //Serial.print(temperature);  
   //Serial.print(",");  
   //Serial.print(humidity);
   //Serial.print("\n");  
   Serial.println(temp[hour()] + 0.01*random(100));
   delay(600000);

 }
