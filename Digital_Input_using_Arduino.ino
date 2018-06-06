// Post: "Digital I/O - Digital Input using Arduino"
// Author: Adithya Rajeev

/*
                          Digital Input
 Demonstrates Digital Input by switching ON and OFF an LED connected
 to Digital Pin 13 whenever the Push Button connected to Digital Pin 2
 is pressed.
 
*/

const int buttonPin = 2;     
const int ledPin =  13;      

int buttonState = 0;         // variable for reading the pushbutton status

//Function to set Pin 13 as Output and Pin 2 as Input
 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

// Infinite loop to check button state and toggle LED

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } 
  else {
    digitalWrite(ledPin, LOW);
  }
}
