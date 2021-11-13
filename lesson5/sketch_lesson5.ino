/* Подключение датчика CJMCU8118 к Arduino UNO
 * VCC -> 3.3V
 * GND -> GND
 * SCL -> A5
 * SDA -> A4
 * WAK -> GND
 */

#include <Wire.h>
#include <Adafruit_CCS811.h>
#include <ClosedCube_HDC1080.h>

Adafruit_CCS811 ccs;
ClosedCube_HDC1080 hdc1080;

void setup()
  {
    Serial.begin(9600);
    Serial.println("HDC1080 TEST");
    Serial.println("CCS811 TEST");
    hdc1080.begin(0x40);
      
    if(!ccs.begin())
       {
          Serial.println("Couldn't find sensor!");
          while (1);
       }
    while(!ccs.available());
      
  }

void loop()
  {  
    if(ccs.available())
      {
        if(!ccs.readData())
          { 
            
            Serial.print("Temp: ");
            Serial.print(hdc1080.readTemperature());
            Serial.print("^C, Hum: ");
            Serial.print(hdc1080.readHumidity());
            Serial.println("%");
            //Serial.println("\n");
            Serial.print(__DATE__);
            Serial.print(", ");
            Serial.print(__TIME__);
            Serial.print(" -> ");  
            Serial.print("CO2: ");
            Serial.print(ccs.geteCO2());
            Serial.print("ppm, TVOC: ");
            Serial.print(ccs.getTVOC());
            Serial.print("ppb, ");
          }
        else
          {
            Serial.println("ERROR!");
            while(1);
          }
      }
    delay(1000);  // Задержка 1 с
  }
