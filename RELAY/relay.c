#include <reg51.h>

sbit RELAY = P3^0;

void ms_delay(unsigned int time);

void main(void){
	while (1){
		RELAY = 1;
		ms_delay(5000);
		RELAY = 0;
		ms_delay(5000);
	}
}

void ms_delay(unsigned int time){
	unsigned int i, j;
	
	for (i = 0; i < time; i++){
		for (j = 0; j < 113; j++);
	}
}