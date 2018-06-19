// Post: "Counter using Pure C"
// Author: Adithya Rajeev

/*
                               Counter
 Demonstrates the functioning of a Counter with Prescalar = 256 and Interrupt.
 The LED connected to Pin A0 glows for the entire clock cycle and turns off 
 for 0.5 seconds every time Interrupt Service Routine(ISR) is called.
 
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
  
//Function for initialization of timer, interrupt
void initialize() {
  TCCR2B |= (1 << CS22)|(1 << CS21);  //Setting prescaler = 256
  TCNT2 = 0;
  TIMSK2 |= (1 << TOIE2);             // enable overflow interrupt
  sei();                              // enable global interrupts
}

//ISR called on overflows, toggles the LED state
ISR(TIMER2_OVF_vect) {
  PORTC ^= (1 << 0);  // toggles the led
  TCNT2 = 0;          // reset counter
  _delay_ms(500);
}

//Main function, Sets A0 as output and calls initialize() 
int main(void) {
  DDRC |= (1 << 0);
  initialize();  //Calls function to initialize the timer and set prescalar
  
  while(1) continue;
  return 0;
}
