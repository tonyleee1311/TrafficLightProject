/*
 * fsm_mode.c
 *
 *  Created on: Nov 1, 2022
 *      Author: nguye
 */


#include"fsm_mode.h"
static uint8_t index_led=0;
static uint8_t increaseTimeDuration=0;
void fsmModeRun(){
	switch(mode){
	case INIT:
		if(timer1_flag==1){
			mode=FIRST_MODE;
			setTimer1(ONE_SECOND/NUMBER_OF_SEVEN_SEG_LED);
			setTimer2(ONE_SECOND);
			setTimeForTrafficLight();
			statusOfTrafficLight=0;
			index_led=0;
			turnOffAllTrafficLight();
		}
		break;
	case FIRST_MODE:
		if(timer1_flag==1){
			updateLedBuffer(statusOfTrafficLight);
			update7SEG(index_led);
			index_led++;
			if(index_led==NUMBER_OF_SEVEN_SEG_LED) index_led=0;
			trafficLightProcessing(statusOfTrafficLight, greenTime);
			setTimer1(ONE_SECOND/NUMBER_OF_SEVEN_SEG_LED);
		}
		if(timer2_flag==1){
	  		redTime--;
	  		greenTime--;
	  		if(greenTime<0) yellowTime--;
	  		if(redTime==0){
	  			setTimeForTrafficLight();
	  			statusOfTrafficLight++;
	  		  }
	  		setTimer2(ONE_SECOND);
	  	  }
		if(timer5_flag==1){
			mode=SECOND_MODE;
			setTimer1(ONE_SECOND/NUMBER_OF_SEVEN_SEG_LED);
			setTimer2(HUNDRED_MILLISECOND);
			statusOfTrafficLight=0;
			setTimeForTrafficLight();
			index_led=0;
			turnOffAllTrafficLight();
			timer5_flag=0;
		}
		if(isButtonPressed(FIRST_BUTTON)) setTimer5(HUNDRED_MILLISECOND);
		break;
	case SECOND_MODE:
		if(timer1_flag==1){
			updateTimeDurationLedBuffer(mode, REDTIME+increaseTimeDuration);
			update7SEG(index_led);
			index_led++;
			if(index_led==NUMBER_OF_SEVEN_SEG_LED) index_led=0;
			setTimer1(ONE_SECOND/NUMBER_OF_SEVEN_SEG_LED);
		}
		if(timer2_flag==1){
			blinkLedForEachMode(mode);
			setTimer2(HALF_SECOND);
		}
		if(timer3_flag==1){
			if(increaseTimeDuration<MINIMUM_TWO_DIGITS_NUMBER) increaseTimeDuration++;
			timer3_flag=0;
		}
		if(timer4_flag==1){
			REDTIME+=increaseTimeDuration;
			increaseTimeDuration=0;
			timer4_flag=0;
			HAL_GPIO_WritePin(ORANGE_PORT, ORANGE_PIN, RESET);
		}
		if(timer5_flag==1){
			mode=THIRD_MODE;
			setTimer1(ONE_SECOND/NUMBER_OF_SEVEN_SEG_LED);
			setTimer2(HUNDRED_MILLISECOND);
			index_led=0;
			increaseTimeDuration=0;
			turnOffAllTrafficLight();
			timer5_flag=0;
		}
		if(isButtonPressed(SECOND_BUTTON)) setTimer3(HUNDRED_MILLISECOND);
		if(isButtonPressed(THIRD_BUTTON)) setTimer4(HUNDRED_MILLISECOND);
		if(isButtonPressed(FIRST_BUTTON)) setTimer5(HUNDRED_MILLISECOND);
		break;
	case THIRD_MODE:
		if(timer1_flag==1){
			updateTimeDurationLedBuffer(mode, YELLOWTIME+increaseTimeDuration);
			update7SEG(index_led);
			index_led++;
			if(index_led==NUMBER_OF_SEVEN_SEG_LED) index_led=0;
			setTimer1(ONE_SECOND/NUMBER_OF_SEVEN_SEG_LED);
		}
		if(timer2_flag==1){
			blinkLedForEachMode(mode);
			setTimer2(HALF_SECOND);
		}
		if(timer3_flag==1){
			if(increaseTimeDuration<MINIMUM_TWO_DIGITS_NUMBER) increaseTimeDuration++;
			timer3_flag=0;
		}
		if(timer4_flag==1){
			YELLOWTIME+=increaseTimeDuration;
			increaseTimeDuration=0;
			timer4_flag=0;
			HAL_GPIO_WritePin(ORANGE_PORT, ORANGE_PIN, RESET);
		}
		if(timer5_flag==1){
			mode=FOURTH_MODE;
			setTimer1(ONE_SECOND/NUMBER_OF_SEVEN_SEG_LED);
			setTimer2(HUNDRED_MILLISECOND);
			index_led=0;
			increaseTimeDuration=0;
			turnOffAllTrafficLight();
			timer5_flag=0;
		}
		if(isButtonPressed(SECOND_BUTTON)) setTimer3(HUNDRED_MILLISECOND);
		if(isButtonPressed(THIRD_BUTTON)) setTimer4(HUNDRED_MILLISECOND);
		if(isButtonPressed(FIRST_BUTTON)) setTimer5(HUNDRED_MILLISECOND);
		break;
	case FOURTH_MODE:
		if(timer1_flag==1){
			updateTimeDurationLedBuffer(mode, GREENTIME+increaseTimeDuration);
			update7SEG(index_led);
			index_led++;
			if(index_led==NUMBER_OF_SEVEN_SEG_LED) index_led=0;
			setTimer1(ONE_SECOND/NUMBER_OF_SEVEN_SEG_LED);
		}
		if(timer2_flag==1){
			blinkLedForEachMode(mode);
			setTimer2(HALF_SECOND);
		}
		if(timer3_flag==1){
			if(increaseTimeDuration<MINIMUM_TWO_DIGITS_NUMBER) increaseTimeDuration++;
			timer3_flag=0;
		}
		if(timer4_flag==1){
			GREENTIME+=increaseTimeDuration;
			increaseTimeDuration=0;
			timer4_flag=0;
			HAL_GPIO_WritePin(ORANGE_PORT, ORANGE_PIN, RESET);
		}
		if(timer5_flag==1){
			mode=INIT;
			setTimer1(HUNDRED_MILLISECOND);
			timer5_flag=0;
		}
		if(isButtonPressed(SECOND_BUTTON)) setTimer3(HUNDRED_MILLISECOND);
		if(isButtonPressed(THIRD_BUTTON)) setTimer4(HUNDRED_MILLISECOND);
		if(isButtonPressed(FIRST_BUTTON)) setTimer5(HUNDRED_MILLISECOND);
		break;
	default:
		break;
	}
}
