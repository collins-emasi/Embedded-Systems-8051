#include <reg52.h>

#define 	LED_ON		0xFF
#define 	LED_OFF		0x00

void ms_delay();
void delay(unsigned int ms_time);

void main(void){
	TMOD = 0x01;		// Timer mode 1, 16 bit mode
	
	while (1){
		P1 = LED_ON;
		delay(1000);
		P1 = LED_OFF;
		delay(1000);
	}
}

void delay(unsigned int ms_time){
	unsigned int i;
	
	for (i = 0; i < (ms_time/5); i++){
		ms_delay();
	}
}

/*
	The ms_delay() funtion below generates a delay of 5ms
*/
void ms_delay(){
	// Maximum count in MODE 1 is 65536
	// To get count for 5ms delay = (5ms / 1.085us) x 1 count = 4608 counts
	
	TH0 = 0x0EE; 	// Give Register TH EE
	TL0 = 0x00;		// Give Register TL 00
	
	TR0 = 1;		// Turning on the timer by giving logic HIGH to TR bit
	
	while (!TF0);	// Wait until there is an overflow in the RF overflow bit
	
	TR0 = 0;		// After overflow, Turn off the timer
	TF0 = 0;		// Reset the Timer Overflow bit to 0
}