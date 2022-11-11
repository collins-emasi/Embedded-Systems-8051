#include <reg52.h>

sbit count_T0 = P3^4;		// Define the Pin 3.4 as count_T0

void main(void){
	TMOD = 0x06;			// Initialize the Counter 0 in mode 2 (8 bit mode)
	count_T0 = 1;			// Configure Pin 3.4 as input pin
	
	while (1){
		TH0 = 0x00;
		TL0 = 0x00;
		
		TR0 = 1;			// Turn on the counter
		
		while (!TF0){		// Wait until there is an overflow
			P1 = TL0;		// Get the output of TF0 at Port P1
		}
		TF0 = 0;			// Reset the overflow bit to LOW
		TR0 = 0;			// Turn off the counter
	}
}