#include <reg52.h>

#define 	ON				0x0FF
#define 	OFF				0x00
#define 	LED_PIN		P1

void ms_delay(unsigned int time);

// Main function
void main(){
	while (1){
		LED_PIN = ON;
		ms_delay(1000);
		LED_PIN = OFF;
		ms_delay(1000);
	}
}

// Function to implement the sleep functionality
void ms_delay(unsigned int time){
	unsigned int i, j;
	
	for (i = 0; i < time; i++){
		for (j = 0; j < 113; j++);
	}
}