/*
 * softwaretimer.c
 *
 *  Created on: Oct 30, 2022
 *      Author: nguye
 */
#include"softwaretimer.h"
uint16_t timer1_counter=0;
uint16_t timer2_counter=0;
uint16_t timer3_counter=0;
uint16_t timer4_counter=0;
uint16_t timer5_counter=0;
int timer1_flag=0;
int timer2_flag=0;
int timer3_flag=0;
int timer4_flag=0;
int timer5_flag=0;
//timer1 for 7LED
void setTimer1(uint16_t duration){
	timer1_counter=(duration/TIME_CYCLE);
	timer1_flag=0;
}
//timer2 for trafficlight
void setTimer2(uint16_t duration){
	timer2_counter=(duration/TIME_CYCLE)+2;
	timer2_flag=0;
}
//increaseTimDuration
void setTimer3(uint16_t duration){
	timer3_counter=(duration/TIME_CYCLE);
	timer3_flag=0;
}
//timer for assign value to red, yellow, green
void setTimer4(uint16_t duration){
	timer4_counter=(duration/TIME_CYCLE);
	timer4_flag=0;
}
void setTimer5(uint16_t duration){
	timer5_counter=(duration/TIME_CYCLE);
	timer5_flag=0;
}
void timerRun(){
	if(timer1_counter>0){
		timer1_counter--;
		if(timer1_counter==0){
			timer1_flag=1;
		}
	}
	if(timer2_counter>0){
		timer2_counter--;
		if(timer2_counter==0){
			timer2_flag=1;
		}
	}
	if(timer3_counter>0){
		timer3_counter--;
		if(timer3_counter==0){
			timer3_flag=1;
		}
	}
	if(timer4_counter>0){
		timer4_counter--;
		if(timer4_counter==0){
			timer4_flag=1;
		}
	}
	if(timer5_counter>0){
		timer5_counter--;
		if(timer5_counter==0){
			timer5_flag=1;
		}
	}
}


