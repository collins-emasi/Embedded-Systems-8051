#include <reg51.h>

/*
RS pin of 16*2 lcd is connected to P3.7
RW pin of 16*2 lcd is connected to P3.6 and 
EN pin of 16*2 lcd is connected to P3.5.
Data pins are connected to port 1 of 8051 microcontroller.
*/

sbit RS = P3^7;
sbit RW = P3^6;
sbit EN = P3^5;

void send_command(unsigned char command_value);
void send_data(unsigned char data_value);
void ms_delay(unsigned int time);
void lcd_print(unsigned char * word);
void init_timer();
void init_lcd();
void printline(char * word);

char rx_data(void);

void main(){
	char input[12];
	unsigned int count;
	
	init_timer();
	init_lcd();
	
	lcd_print("RFID Card Number:");

	while (1){
		count = 0;
		send_command(0xC2);
		
		while (count < 12){
			input[count] = rx_data();
			count++;
		}
		
		lcd_print(input);
		printline(input);
		
		ms_delay(100);
	}
	
}

void lcd_print(unsigned char * word){
	unsigned int i = 0;
	
	while (word[i] != '\0'){
		send_data(word[i]);
		ms_delay(1);
		i++;
	}
}

void printline(char * word){
	unsigned int i = 0;
	
	while (word[i] != '\0'){			// Check to see we are not at end of the array
		SBUF = word[i];					// Load the ASCII Value to SBUF Register
		while (!TI);					// Monitor the TI bit of the SCON Register. It is 1 when Tx is complete
		TI = 0;							// Manually reset the TI Flag to LOW
		i++;
	}
}

char rx_data(void){
	char rxdata;
	
	while (!RI);			// Wait for Receiver Interrupt flag to be set. meaning Tx is complete
	RI = 0;					// Manually reset the RI Flag
	rxdata = SBUF;			// Copy contents of the SBUF Register to the P1 port
	return rxdata;
}

void init_timer(){
	TMOD = 0x20;			// Set Timer 1 mode 2
	SCON = 0x50;			// set mode 1 (8-bit UART) and REN Enabled
	TH1  = 0x0FD;			// Set Baud rate 9600
	TR1  = 1;				// Turn on the timer
}

void send_command(unsigned char command_value){
	P1 = command_value;
	RW = 0;
	RS = 0;
	EN = 1;
	ms_delay(10);
	EN = 0;
}

void send_data(unsigned char data_value){
	P1 = data_value;
	RW = 0;
	RS = 1;
	EN = 1;
	ms_delay(10);
	EN = 0;
}

void init_lcd(){
	/*
	
	*/
	unsigned int i;
	unsigned char cmds[5] = {0x38, 0x01, 0x06, 0x0c, 0x80};
	
	for (i = 0; i < 5; i++){
		send_command(cmds[i]);
		ms_delay(1);
	}
}

void ms_delay(unsigned int time){
	unsigned int i, j;
	
	for (i = 0; i < time; i++){
		for (j = 0; j < 113; j++);
	}
}	