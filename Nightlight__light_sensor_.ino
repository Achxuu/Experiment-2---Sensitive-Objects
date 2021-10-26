//Creation & Computation Experiment 2 - Sensitive Objects
//Project Name: "Changing Seasons Serenity Night Light" Part I
/*Part I of the project changes the brightness of the project (turns more LEDs on) as the room gets darker. 
*/

int light = 0; // stores the light value

void setup() {
    Serial.begin(9600); 
    pinMode(12, OUTPUT); 
    pinMode(11, OUTPUT);
}

void loop() {
    
    light = analogRead(A0); // read and save value from the sensor
    
    Serial.println(light); // print light value in serial monitor
 
    if(light > 650) { // When it is bright
        Serial.println("Day time");
        digitalWrite(12,LOW); //turn yellow LEDs off
        digitalWrite(11,LOW); // turn white LEDs off
    }
    else if(light > 350 && light < 649.5) { // When it is fairly dark
       Serial.println("Evening time");
       digitalWrite(12, HIGH); // turn yellow LEDs on
       digitalWrite(11,LOW);  // turn white LEDs off
    }
    else { // When it is really dark
        Serial.println("Night time");
        digitalWrite(12,HIGH); // turn yellow LEDs om
        digitalWrite(11,HIGH); // turn white LEDs on
    }
    delay(1000); 
}
