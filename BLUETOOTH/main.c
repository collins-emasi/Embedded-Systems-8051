#include <reg51.h>

sbit LED = P1^0;

void UART_init();
char UART_rx();
void UART_tx(char * word);

void main(void){
	char data_in;
	UART_init();
	P1 = 0;
	LED = 0;
	
	while (1){
		data_in = UART_rx();
		if (data_in == '1'){
			LED = 1;
			UART_tx("LED ON ");
		} else if (data_in == '2'){
			LED = 0;
			UART_tx("LED OFF ");
		} else {
			UART_tx("Invalid option ");
		}
	}
}

void UART_init(){
	TMOD	= 0x20;						// Time 1, 8-bit auto reload mode
	TH1		= 0xFD;						// Set 9600 Baud rate
	SCON 	= 0x50;						// Mode 1 to enable reception
	TR1 	= 1;						// Start Timer 1
}

char UART_rx(){
	while (!RI);
	RI = 0;
	return SBUF;
}

void UART_tx(char * word){
	unsigned int i = 0;
	
	while (word[i] != '\0'){			// Check to see we are not at end of the array
		SBUF = word[i];					// Load the ASCII Value to SBUF Register
		while (!TI);					// Monitor the TI bit of the SCON Register. It is 1 when Tx is complete
		TI = 0;							// Manually reset the TI Flag to LOW
		i++;
	}
}