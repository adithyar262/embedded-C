// Post: "Digital I/O - Digital Output using Pure C"
// Author: Adithya Rajeev

/*
                          Digital Output
 Demonstrates Digital Output by switching ON and OFF an LED connected
 to Digital Pin 12 with a delay of 1 second.

*/

#include <avr/io.h>
#include <util/delay.h>

//Main funciton, Sets Pin 12 as OUTPUT and runs
//the infinite loop, to toggle the state of the LED
int main(){
  DDRB|=_BV(DDB4);     // Setting Pin B4 as Output 
  
  //Infinite loop to toggle the LED state
  while(1){
    PORTB|=_BV(PB4);   //Turning ON the LED at PB4 for 1 sec
    _delay_ms(1000);
    PORTB&=~_BV(PB4);  //Turning ON the LED at PB4 for 1 sec
    _delay_ms(1000);
  }
  return 0;
}
    
