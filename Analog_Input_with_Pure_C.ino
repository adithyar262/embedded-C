// Post: "Analog I/O - Analog Input using Pure C"
// Author: Adithya Rajeev

/*
                              Analog Input
  Demonstrates analog input by reading an analog value from a potentiometer on 
  Analog pin A0 and turning on and off a LED connected to digital pin 12.
  The LED glows when the analog value is greater that 512 and turns off when the 
  analog value is less than 512.
   
*/

#include <avr/io.h>

int adc_value;                                                 //Variable to store the value read from the ADC converter

//Sets up the ADC and prescalar

int main(){
    DDRB |= (1<<PB5);    
    ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));              //Setting Prescalar as 128
    ADMUX |= (1<<REFS0);
    ADMUX &= ~(1<<REFS1);                                      //Avcc(+5v) as voltage reference
    ADCSRB &= ~((1<<ADTS2)|(1<<ADTS1)|(1<<ADTS0));             //Setting ADC in free-running mode
    ADCSRA |= (1<<ADATE); 
    ADCSRA |= (1<<ADEN);                                       //Power up the ADC
    ADCSRA |= (1<<ADSC);                                       //Start converting

    // Infinite loop to check potentiometer value and toggle LED
     
    while(1){        
       adc_value = ADCW; 
       if(adc_value > 512){
          PORTB |= (1<<PB5);
       }
       else {
          PORTB &= ~(1<<PB5);  
       }
     }
    return 0;
 }
