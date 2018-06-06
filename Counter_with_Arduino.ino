// Post: "Counter using Arduino"
// Author: Adithya Rajeev

/*
                               Counter
 Demonstrates the functioning of a Counter with Prescalar = 64 and Interrupt.
 The LED connected to Pin A0 glows for the entire clock cycle and turns off 
 for 0.5 seconds every time Interrupt Service Routine(ISR) is called.
 
*/

bool state=1;

//Sets up Timer and Interrupt

void setup() {
  pinMode(13,OUTPUT);
    
  TCCR0A=(1<<WGM01);                //Sets in CTC mode   
  OCR0A=0xF9;                       //Value for ORC0A for 1ms 
  TIMSK0|=(1<<OCIE0A);   
  sei();
  TCCR0B|=(1<<CS01);                //Sets the prescalar as 64
  TCCR0B|=(1<<CS00); 
}

// Assigns state value to pin 13

void loop() {
 digitalWrite(13,state);
}

//ISR called on overflows

ISR(TIMER0_COMPA_vect){   
  digitalWrite(13,LOW);
  delay(500);
  digitalWrite(13,state); 
}

