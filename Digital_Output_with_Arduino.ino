// Post: "Digital I/O - Digital Output using Arduino"
// Author: Adithya Rajeev

/*
                          Digital Output
 Demonstrates Digital Output by switching ON and OFF an LED connected
 to Digital Pin 12 with a delay of 1 second.
 
*/

const int LED = 12;

//Sets up Pin 12 as OUTPUT

void setup()
{
  pinMode(LED, OUTPUT);
}

//Infinite Loop to toggle the state of the LED
void loop()
{
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}
