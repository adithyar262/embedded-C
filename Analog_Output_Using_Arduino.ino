// Post: "Analog I/O - Analog Output using Arduino"
// Author: Adithya Rajeev

/*
                              Analog Output
 Demonstrates Analog Output by connecting the speed of a DC Motor connected
 to Analog Pin A0 with a delay of 1 second.
  
*/

//Nothing happens in the setup

void setup()
{
 }

//Infinite loop to control speed of motor

void loop()
{
  for(int i=0;i<=255;i+=10){
    analogWrite(A0,i);
  }
  for(int j=255;j>=0;j-=10){
    analogWrite(A0,j);
  }
}
