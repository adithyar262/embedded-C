// Post: "TIMER 2 with Prescalar and Interrupts using Arduino"
// Author: Adithya Rajeev

/*
              Timer 2 with Prescalars and Interrupts
              
Demonstrates the functioning of Timer 2 with Prescalar = 1024 and Interrupt.
The Interrupt Service Routine (ISR) is called on on every overflow. 
An LED connected to PC0(A0) that glows with a frequency of 100Hz.

*/


#include <avr/io.h>
#include <avr/interrupt.h>
 
int LED_pin = 2;

//Setting up the Timer, Precsalars and Interrupts
void setup() {
  pinMode(LED_pin, OUTPUT);
 
  // Initialization of Timer2
  cli();                    // disable global interrupts
  TCCR2A = 0;                       
  TCCR2B = 0;                       
  OCR1A = 156;              // Setting compare match register to desired timer count
  TCCR2B |= (1 << WGM12);   // turn on CTC mode:
    
  // Set CS20 and CS22 bits for 1024 prescaler:
  TCCR2B |= (1 << CS20);
  TCCR2B |= (1 << CS22);
  TIMSK2 |= (1 << OCIE2A);  // Enabling timer compare interrupt
  sei();                    // Enabling global interrupts
}

//Infinite loop
void loop() {
}

//ISR called on overflows, toggles LED state
ISR(TIMER2_COMPA_vect) {
  digitalWrite(LED_pin, !digitalRead(LED_pin));
}
