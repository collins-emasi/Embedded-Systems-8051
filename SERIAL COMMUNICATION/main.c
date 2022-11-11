#include <reg52.h>

void transmit(char * word);				// Tx Function prototype: Takes in an array of word
void receive();							// Rx Function prototype: 

void main(void){
	TMOD = 0x20;						// Set timer1 mode 2
	SCON = 0x50;						// Set mode 1 (8-bit UART) and REN Enabled
	TH1 = 0x0FD;						// Set baud rate 9600. Calculated as TH1 = (256 - (28800/baud rate))H
	TR1 = 1;							// Turn on the timer.
	
	transmit("DAY 4 of #100DaysOfCode");// Transmit message
	
	while (1){
		receive();						// Start Receiving
	}
}

void transmit(char * word){
	unsigned int i = 0;
	
	while (word[i] != '\0'){			// Check to see we are not at end of the array
		SBUF = word[i];					// Load the ASCII Value to SBUF Register
		while (!TI);					// Monitor the TI bit of the SCON Register. It is 1 when Tx is complete
		TI = 0;							// Manually reset the TI Flag to LOW
		i++;
	}
}

void receive(){
	while (!RI);						// Wait for Receiver Interrupt flag to be set. meaning Tx is complete
	P1 = SBUF;							// Copy contents of the SBUF Register to the P1 port
	RI = 0;								// Manually reset the RI Flag
}