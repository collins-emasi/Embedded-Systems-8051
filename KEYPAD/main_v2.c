#include <reg51.h>

// LCD Connection
sbit RS = P3^2;		// RS Pin connected to Pin 3.2
sbit RW = P3^3;		// RW Pin connected to Pin 3.3
sbit E 	= P3^4;		// E Pin connected to Pin 3.4

// Keypad Connection
sbit C4 = P1^0;
sbit C3 = P1^1;
sbit C2 = P1^2;
sbit C1 = P1^3;
sbit R4 = P1^4;
sbit R3 = P1^5;
sbit R2 = P1^6;
sbit R1 = P1^7;

void ms_delay(unsigned int time);
void send_command(unsigned int command_value);
void send_data(unsigned int data_value);
void lcd_print(unsigned char * word);
void lcd_init(void);
void start_calculator(void);
void clear_lcd(void);
void keypad_input(void);
char row_finder(unsigned int col);
unsigned int get_sign(void);

char eqn[];

void main(){
	unsigned int i = 0;
	char ch;
	start_calculator();
	
	while (1){
		ch = keypad_input();
		if (ch != NULL){
			eqn[i] = ch;
			i++;
		}
	}
}

void solve_eqn(void){
	unsigned int sign, fpart, lpart, result;
	sign = get_sign();
	fpart = get_fpart();
	lpart = get_lpart();
	
	if (sign == NULL){ return NULL;)}
	else if (sign == 1){	// Summation
		result = fpart + lpart;
	} else if (sign == 2){	// Division
		result = fpart / lpart;
	} else if (sign == 3){	// Multiplication
		result = fpart * lpart;
	} else if (sign == 4){	// Subtraction
		result = fpart - lpart;
	}
}

unsigned int get_lpart(void){
	unsigned int lpart[;
	
}

unsigned int get_sign(){
	unsigned int i = 0;
	unsigned int sign = NULL;
	
	while (eqn[i] != '\0'){
		if (eqn[i] == '+') sign = 1;
		if (eqn[i] == '/') sign = 2;
		if (eqn[i] == 'x') sign = 3;
		if (eqn[i] == '-') sign = 4;
		
		i++;
	}
	
	return sign;
}

void start_calculator(void){
	lcd_init();
	lcd_print("Mini Calculator");
	ms_delay(1500);
	clear_lcd();
}

char keypad_input(void){
	char eqn = NULL;
	C1 = C2 = C3 = C4 = 1;
	R1 = R2 = R3 = R4 = 0;
	
	if (C1 == 0) {
		eqn = row_finder(1);
	} else if (C2 == 0) {
		eqn = row_finder(2);
	} else if (C3 == 0) {
		eqn = row_finder(3);
	} else if (C4 == 0) {
		eqn = row_finder(4);
	}
	
	return eqn	
}

char row_finder(unsigned int col){
	R1 = R2 = R3 = R4 = 1;
	C1 = C2 = C3 = C4 = 0;
	
	if (col == 1){
		if(R1==0) {send_data('7'); return '7';}
		if(R2==0) {send_data('4'); return '4';}
		if(R3==0) {send_data('1'); return '1';}
		if(R4==0) clear_lcd();
	} else if (col == 2){
		if(R1==0) {send_data('8'); return '8';}
		if(R2==0) {send_data('5'); return '5';}
		if(R3==0) {send_data('2'); return '2';}
		if(R4==0) {send_data('0'); return '0';}
	} else if (col == 3){
		if(R1==0) {send_data('9'); return '9';}
		if(R2==0) {send_data('6'); return '6';}
		if(R3==0) {send_data('3'); return '3';}
		if(R4==0) solve_eqn();
	} else if (col == 4){
		if(R1==0) {send_data('/'); return '/';}
		if(R2==0) {send_data('x'); return 'x';}
		if(R3==0) {send_data('-'); return '-';}
		if(R4==0) {send_data('+'); return '+';}
	}
	
	ms_delay(100);
}

void clear_lcd(){
	send_command(0x01);
	ms_delay(1);
	send_command(0x80);
}

void lcd_init(){
	send_command(0x38);		// Use 2 lines and 5x7 matrix LCD
	ms_delay(1);
	send_command(0x0F);		// Turn Display On and cursor blinking
	ms_delay(1);
	send_command(0x01);		// Clear Screen
	ms_delay(1);
	send_command(0x80);		// Bring cursor to position 1 of line 1
	ms_delay(1);
}

void lcd_print(unsigned char * word){
	unsigned int i = 0;
	
	while (word[i] != '\0'){
		send_data(word[i]);
		ms_delay(1);
		i++;
	}
}

void send_command(unsigned int command_value){
	P2 = command_value;
	RW = 0;
	RS = 0;
	E = 1;
	ms_delay(10);
	E = 0;
}

void send_data(unsigned int data_value){
	P2 = data_value;
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