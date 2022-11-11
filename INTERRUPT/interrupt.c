#include <reg51.h>						// Special Function Registers of 80C51 CPU

sbit SqWAVE = P1^3;						// Define Pin 1.3 as the output pin of square wave
sbit LED	= P1^4;						// Define Pin 1.4 as the LED Pin
sbit SW		= P3^2;						// Define pin 3.2 as the Switch Pin

void ms_delay(unsigned int time);		// Delay function prototype
void EINT_LED();						// External Interrupt func prototype

void main(){
	SW = 1;								// Initialize the switch pin as INPUT pin
	LED = 0;							// Initialize the LED Pin with LOW
	IT0 = 0;							// Initialize the Interrupt ast Level triggered, if edge triggered is desired, set 1
	IE = 0x81;							// Set the interrupt Enable Register as 81H to enable External Interrupt
	
	while (1){							// Generate a square wave
		SqWAVE = 1;						
		ms_delay(500);
		SqWAVE = 0;
		ms_delay(500);
	}
}

/*
void function_name (void) interrupt interrupt_number
The interrupt_number determines the interrupt vector address of the interrupt function
*/

void EINT_LED() interrupt 0 {			// By providing the "interrupt 0" keyword you make the function an ISR
	LED = ~LED;							// Complement the LED value
	ms_delay(500);
}

void ms_delay(unsigned int time){
	unsigned int i, j;
	
	for (i = 0; i < time; i++){
		for (j = 0; j < 113; j++);		// Delay for 1ms
	}
}