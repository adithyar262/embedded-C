// Post: "Analog I/O - Analog Input using Arduino"
// Author: Adithya Rajeev

/*
                              Analog Input
  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().
   
*/

int sensor_pin = A0;
int LED_pin = 13;  

//Variable to store the value coming from the sensor.
int sensor_value = 0;

// declares LED_pin as an OUTPUT
void setup() {
  pinMode(LED_pin, OUTPUT);
}

// Infinite loop to check potentiometer value and change LED Duty Cycle
void loop() {
  sensor_value = analogRead(sensor_pin);
  digitalWrite(LED_pin, HIGH);
  delay(sensor_value);
  digitalWrite(LED_pin, LOW);
  delay(sensor_value);
}
