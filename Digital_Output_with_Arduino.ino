// Post: "Digital I/O - Digital Output using Arduino"
// Author: Adithya Rajeev

/*
                          Digital Output
 Demonstrates Digital Output by switching ON and OFF an LED connected
 to Digital Pin 12 with a delay of 1 second.
 
*/

const int kLED = 12;

//Sets up Pin 12 as OUTPUT
void setup(){
  pinMode(kLED, OUTPUT);
}

//Infinite Loop to toggle the state of the LED
void loop(){
  digitalWrite(kLED, HIGH);
  delay(1000);
  digitalWrite(kLED, LOW);
  delay(1000);
}
