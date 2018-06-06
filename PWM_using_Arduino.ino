// Post: "Pulse Width Modulation(PWM) using Pure C"
// Author: Adithya Rajeev

/*
                          Pulse Width Modulation
 Demonstrates Pulse Width Modulation by first slowly increasing the brightness
 of an LED connected to PWM pin 9 and then slowly decreasing the brightnes of 
 the LED.
 
*/

int ledPin = 9;    

//Nothing happens in setup

void setup() {
  
}

//Infinite loop to slowly increase and decrease the LED brightness

void loop() {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {    
    analogWrite(ledPin, fadeValue);
    delay(30);
  }

  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin, fadeValue);
    delay(30);
  }
}
