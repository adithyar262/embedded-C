// Post: "Analog I/O - Analog Input using Arduino"
// Author: Adithya Rajeev

/*
                              Analog Input
  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().
   
*/

int sensorPin = A0;    
int ledPin = 13;      
int sensorValue = 0;            //Variable to store the value coming from the sensor

// declare the ledPin as an OUTPUT
  
void setup() {
  pinMode(ledPin, OUTPUT);
}

// Infinite loop to check potentiometer value and change LED Duty Cycle

void loop() {
  sensorValue = analogRead(sensorPin);
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
}
