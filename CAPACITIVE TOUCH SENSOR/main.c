#include <reg51.h>

sbit RELAY = P1^0;
sbit TOUCH = P1^1;

void delay(unsigned int time);

void main(){
	RELAY = 0;
	TOUCH = 0;
	
	while (1){
		if (TOUCH == 1){
			delay(15);
			
			if (TOUCH == 1){
				RELAY = !RELAY;
				delay(30);
			}
		}
	}
}

void delay(unsigned int time){
	unsigned int i, j;
	for (i = 0; i < time; i++){
		for (j = 0; j < 113; j++);
	}
}