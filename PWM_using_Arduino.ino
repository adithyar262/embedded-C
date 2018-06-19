// Post: "Pulse Width Modulation(PWM) using Pure C"
// Author: Adithya Rajeev

/*
                          Pulse Width Modulation
 Demonstrates Pulse Width Modulation by first slowly increasing the brightness
 of an LED connected to PWM pin 9 and then slowly decreasing the brightnes of 
 the LED.
 
*/

int LED_pin = 9;    

//Variable to control LED brightness
int fade_value;

//Nothing happens in setup
void setup() {
  pinMode(LED_pin,OUTPUT);
}

//Infinite loop to slowly increase and decrease the LED brightness
void loop() {
  for (fade_value = 0 ; fade_value <= 255; fade_value += 5) {    
    analogWrite(LED_pin, fade_value);
    delay(30);
  }

  for (fade_value = 255 ; fade_value >= 0; fade_value -= 5) {
    analogWrite(LED_pin, fade_value);
    delay(30);
  }
}
