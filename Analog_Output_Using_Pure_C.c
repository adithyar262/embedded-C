// Post: "Analog I/O - Analog Output using Pure C"
// Author: Adithya Rajeev

/*
                              Analog Output
 Demonstrates Analog Output by controlling the speed of a DC Motor connected
 to Analog Pin A0 with a delay of 1 second.
  
*/

#include <avr/io.h>
#include <util/delay.h>

//Main funtion, sets pin A0 as output and runs the infinite loop.
int main(){
  DDRC|=_BV(DDC0);

  //Infinite loop to control speed of motor
  while(1){
    PORTC|=_BV(PC0);
    _delay_ms(1000);
    PORTC&=~_BV(PC0);
    _delay_ms(1000);
  }
  return 0;
}
