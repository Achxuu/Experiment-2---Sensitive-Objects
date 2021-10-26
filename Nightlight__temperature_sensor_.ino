
//Creation & Computation Experiment 2 - Sensitive Objects
//Project Name: "Changing Seasons Serenity Night Light" Part II
/*Part II of the project changes the colour of LEDs that is turned on depending on the temperature in the room. 
 * Based on: "Reading Temperature & Humidity on Nano 33 BLE Sense" from the public domain.
*/

#include <Arduino_HTS221.h>

//print only when values change by at least 1%
float old_temp = 0;
float old_hum = 0;


void setup() {
  Serial.begin(9600);
  while (!Serial);

  pinMode(12, OUTPUT); 
  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }
}

void loop() {

  //old_temp = analogRead(A0); // read and save value from PR
    
   // Serial.println(light); // print current light value
 float temperature = HTS.readTemperature();
  float humidity    = HTS.readHumidity();
{

  //Note that the temperature ranges below are set fairly high for experimentational/demonstration purposes. They ideally should be set to more 
  reasonable temperance in accordance with the temperature change of a common room as the season changes. This can be adjusted accordingly. 
  
    if(temperature > 31.01) { // If it is hot...
        Serial.println("hot");
        digitalWrite(13,LOW); //turn red/orange LEDs OFF
        digitalWrite(2,LOW); //turn blue LEDs OFF

          //Print values in serial monitor (even during the "hot" category):
         Serial.print("Temperature = ");
         Serial.print(temperature);
         Serial.println(" °C");
         
       }
    else if(temperature > 28 && temperature < 31) { // If it is mildly hot...
        Serial.println("mild");
        digitalWrite(13, HIGH); // turn red/orange LEDs ON
        digitalWrite(2,LOW);  // turn blue LEDs OFF

        //Print values in serial monitor (even during the "mild" category):
        Serial.print("Temperature = ");
        Serial.print(temperature);
        Serial.println(" °C");
       
    }
    else { // If it's cold...
        Serial.println("cold");
        digitalWrite(13,LOW); //turn red/orange LEDs OFF
        digitalWrite(2,HIGH); // Turn blue LEDs ON

        
  // read all the sensor values
  // check if the range values in temperature are bigger than 0,5 ºC
  // and if the range values in humidity are bigger than 1%
  if (abs(old_temp - temperature) >= 0.5 || abs(old_hum - humidity) >= 1 )
  {
    old_temp = temperature;
    old_hum = humidity;
    // print each of the sensor values
    Serial.print("Temperature = ");
    Serial.print(temperature);
    Serial.println(" °C");
    Serial.print("Humidity    = ");
    Serial.print(humidity);
    Serial.println(" %");
    Serial.println();
  }

  // print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity    = ");
  Serial.print(humidity);
  Serial.println(" %");

  // print an empty line
  Serial.println();

  // wait 1 second to print again
  delay(1000);
    }
    }
}

   
