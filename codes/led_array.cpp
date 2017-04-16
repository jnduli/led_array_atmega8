#include "leds.h"
const int nos = 100;
int main ()
{
   Leds leds; 
   //leds.lightAllLEDs();
   while (1){
       for (int i= 0; i<nos; i++ )
           leds.drawCharacter(leds.H);
       for (int i= 0; i<nos; i++ )
           leds.drawCharacter(leds.A);
       for (int i= 0; i<nos; i++ )
           leds.drawCharacter(leds.P);
       for (int i= 0; i<nos; i++ )
           leds.drawCharacter(leds.Y);
       for (int i= 0; i<nos; i++ )
           leds.drawCharacter(leds.E);
       for (int i= 0; i<nos; i++ )
           leds.drawCharacter(leds.S);
       for (int i= 0; i<nos; i++ )
           leds.drawCharacter(leds.T);
       for (int i= 0; i<nos; i++ )
           leds.drawCharacter(leds.R);
       for (int i= 0; i<nos; i++ )
           leds.drawCharacter(leds.H);
   }
}
