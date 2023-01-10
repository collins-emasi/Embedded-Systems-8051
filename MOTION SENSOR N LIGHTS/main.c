#include <reg51.h>

sbit MOTION_SENSOR	= P0^0;
sbit LED		 	= P1^0;

void ms_delay(unsigned int time);

void main(){
	P1 = 0;
	ms_delay(3000);
	
	while (1){
		if (MOTION_SENSOR == 1){
			LED = 0;
		} else {
			LED = 1;
		}
	}
}

void ms_delay(unsigned int time){
	unsigned int i, j;
	
	for (i = 0; i < time; i++){
		for (j = 0; j < 113; j++);
	}
}