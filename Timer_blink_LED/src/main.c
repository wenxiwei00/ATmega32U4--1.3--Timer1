/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include "MEAM_general.h"  // includes the resources included in the MEAM_general.h file
#define COMPARVALUE 50000  //when prescaler=8, the timer should count to 50000 for 20 Hz LED blinking


int main(void) 
{ 
    
    _clockdivide(0); //set the clock speed to 16Mhz

    DDRB |= 0x08; //set port B3 as output
    TCCR3B = 0x02; //set clock of counter equal to 2MHz (scaler=8)
    while(1){
        if(TCNT3 > COMPARVALUE){
            toggle(PORTB,3);
            TCNT3 = 0;
        }
    }
    return 0;

}

