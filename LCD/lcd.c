#include <reg52.h>

// Define some LCD Commands
#define		CLEAR		0x01		// Clears the display and returns the cursor to the home position
#define		DP_ON_OFF	0x0E		// Turns display ON/OFF or cursor
#define		LIN_MAT		0x38		// 2 Lines and 5x7 matrix
#define 	FIRST_LINE	0x80		// Force cursor on 1st line
#define		SEC_LINE	0xC0		// Force cursor on 2nd line

// Define the Control Pins
sbit RS = P2^0;
sbit RW = P2^1;
sbit E 	= P2^2;

// Function prototypes
void send_command(unsigned int command_value);
void send_data(unsigned int data_value);
void ms_delay(unsigned int time);

void main(void){
	// LCD Init
	// 2 Lines and 5x7 matrix
	send_command(LIN_MAT);
	
	// Display on Cursor blink
	send_command(DP_ON_OFF);
	
	// Clear display Screen
	send_command(CLEAR);
	
	while (1){
		send_command(FIRST_LINE);
		send_data('D');
		send_data('A');
		send_data('Y');
		send_data(' ');
		send_data('1');
		send_data(' ');
		send_data('O');
		send_data('F');
		
		send_command(SEC_LINE);
		
		send_data('#');
		send_data('1');
		send_data('0');
		send_data('0');
		send_data('D');
		send_data('a');
		send_data('y');
		send_data('s');
		send_data('O');
		send_data('f');
		send_data('C');
		send_data('o');
		send_data('d');
		send_data('e');
	}
}

void send_command(unsigned int command_value){
	P1 = command_value;
	RW = 0;
	RS = 0;
	E = 1;
	ms_delay(10);
	E = 0;
}

void send_data(unsigned int data_value){
	P1 = data_value;
	RW = 0;
	RS = 1;
	E = 1;
	ms_delay(10);
	E = 0;
}

void ms_delay(unsigned int time){
	unsigned int i, j;
	
	for (i = 0; i < time; i++){
		for (j = 0; j < 113; j++);
	}
}