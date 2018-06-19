// Post: "Digital I/O - Digital Input using Arduino"
// Author: Adithya Rajeev

/*
                          Digital Input
 Demonstrates Digital Input by switching ON and OFF an LED connected
 to Digital Pin 13 whenever the Push Button connected to Digital Pin 2
 is pressed.
 
*/

const int kButtonPin = 2;     
const int kLEDPin =  13;      

// variable for reading the pushbutton status
int button_state = 0;         

//Function to set Pin 13 as Output and Pin 2 as Input.
void setup() {
  pinMode(kLEDPin, OUTPUT);
  pinMode(kButtonPin, INPUT);
}

// Infinite loop to check button state and toggle LED
void loop() {
  button_state = digitalRead(kButtonPin);
  
  //Checks button state and toggles LED state accordingly
  if (button_state == HIGH) {
    digitalWrite(kLEDPin, HIGH);
  } else {
    digitalWrite(kLEDPin, LOW);
  }
}
