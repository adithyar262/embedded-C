// Post: "TIMER 2 with Prescalar and Interrupts using Pure C"
// Author: Adithya Rajeev

/*
       Timer 2 with Prescalars and Interrupts

Demonstrates the functioning of Timer 2 with Prescalar = 256 and Interrupt.
The Interrupt Service Routine (ISR) is called on on every overflow. After 3 overflows,
the timers runs again and reaches when the count = 80.
An LED connected to PC0(A0) is used to show the output.

*/

#include <avr/io.h>
#include <avr/interrupt.h>

//Variable to count the number of overflows  
volatile uint8_t totaloverflow; 
  
//Initialization of the timer, interrupt and variable

void timer()
{
    TCCR2B |= (1 << CS22)|(1 << CS21);   //Setting prescaler = 256
    TCNT2 = 0;                           //Initialize counter
    TIMSK2 |= (1 << TOIE2);              //Enable overflow interrupt
    sei();                               //Enable global interrupts
    totaloverflow = 0;                   //Initializing overflow counter variable
}

//ISR called whenever TCNT0 overflows

ISR(TIMER2_OVF_vect)
{
    totaloverflow++;
}

// Main function, checks whether totaloverflow = 3 and resets the Timer

int main(void){
    DDRC |= (1 << 0);
    timer();
    while(1){
        if (totaloverflow >= 3){     //Checking if no. of overflows = 3
            if (TCNT2 >= 80){        //Checking if the timer count reaches 80
                PORTC ^= (1 << 0);   // toggles the led
                TCNT2 = 0;           // reset counter
                totaloverflow = 0;   // reset overflow counter
            }
        }
    }
}
