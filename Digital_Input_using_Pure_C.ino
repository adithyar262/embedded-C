// Post: "Digital I/O - Digital Input using Pure C"
// Author: Adithya Rajeev

/*
                          Digital Input
 Demonstrates Digital Input by switching ON and OFF an LED connected
 to Digital Pin 13 whenever the Push Button connected to Digital Pin 2
 is pressed.
 
*/

#include <avr/io.h>
#include <util/delay.h>

//Main function to set Pin 13 as Output and Pin 2 as Input

int main ()
	{
      DDRB|=_BV(DDB5); 
      DDRD &= ~_BV(DDD2);
      PORTD |= _BV(PD2);

      // Infinite loop to check button state and toggle LED
      
	  while (1) {
      	if (PIND & PORTD)
          PORTB &= ~_BV(PB5);
        else
          PORTB |= _BV(PB5);
      	}
      return 0;
    }
