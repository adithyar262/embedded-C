// Post: "Pulse Width Modulation(PWM) using Pure C"
// Author: Adithya Rajeev

/*
                          Pulse Width Modulation
 Demonstrates Fast Pulse Width Modulation by slowly increasing the brightness
 of an LED connected to PWM pin 6 and slowly decreasing the brightnes of 
 the LED connected to Pin 6.
 
 LED connected to Pin D5(pin 5) increases gradually in brightness
 LED connected to Pin D6(pin 6) decreases gradually in brightness
 
*/


#include <avr/io.h>
#include <util/delay.h>

//Sets up PWN Mode and Timers

int main ()
{
  TCCR0A |= _BV(WGM01) | _BV(WGM00);                //Fast PWM mode
  
  //Inverting mode drives the output low while the counter is greater than OCRNx.
  
  TCCR0A |= _BV(COM0A1) | _BV(COM0A0);              //Inverting fade down mode
  
  //Non-inverting mode drives the output high while the counter is greater than OCRNx.
  
  TCCR0A |= _BV(COM0B1);                            //Non Inverting fade up mode

  //Reset all the timers and comparators
  
  OCR0A = 0;
  OCR0B = 0;
  TCNT0 = 0;
  TCCR0B |= _BV(CS00);
  DDRD |= _BV(PORTD5) | _BV(PORTD6);

  //Infinite loop to gradually vary the LED brightness
  
  while (1){
    OCR0A++;
    OCR0B++;
    _delay_ms(20);
  }
  return 0;
}
