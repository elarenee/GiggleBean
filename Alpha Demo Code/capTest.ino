#include <CapacitiveSensor.h>
 
  CapacitiveSensor   cs_3_2 = CapacitiveSensor(3,2);
  CapacitiveSensor   cs_24_26 = CapacitiveSensor(24,26); 
  CapacitiveSensor   cs_8_9 = CapacitiveSensor(8,9); 
  
  int ledPinB = 8;                                 //Blue LED
  int ledPinG = 12;                                //Green LED
  int ledPinR = 11;                                //Red LED
   
  void setup()                    
  {
     cs_3_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
     cs_24_26.set_CS_AutocaL_Millis(0xFFFFFFFF);
     cs_8_9.set_CS_AutocaL_Millis(0xFFFFFFFF);
     Serial.begin(9600);
     pinMode(ledPinB, OUTPUT);
     pinMode(ledPinG, OUTPUT);
     pinMode(ledPinR, OUTPUT);
  }
   
  void loop()                    
  {
      long totalB =  cs_3_2.capacitiveSensor(10);
      long totalG =  cs_24_26.capacitiveSensor(10);
      long totalR =  cs_8_9.capacitiveSensor(10);

      Serial.println(totalB);                       //Send all data as serial output
      Serial.println(totalG);
      Serial.println(totalR);                                
      
   
      if (totalB == 0){
        digitalWrite(ledPinB, HIGH);                //Turn on LED
      }else
        digitalWrite(ledPinB, LOW);                 //Turn off LED
      
      if (totalG == 0){
        digitalWrite(ledPinG, HIGH);
      }else
        digitalWrite(ledPinG, LOW);
        
     if (totalR > 0){
        digitalWrite(ledPinR, HIGH);
      }else
        digitalWrite(ledPinR, LOW);
  }

