/*
 * sevensegment.c
 *
 *  Created on: Oct 29, 2022
 *      Author: nguye
 */
#include "sevensegment.h"
//variables
//variables
enum sevenSegOn{First,Second,Third,Fourth};
//enum sevenSegOn index_led=0;
uint8_t led_buffer [NUMBER_OF_SEVEN_SEG_LED];
uint8_t sevenSegmentCode[10]={0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
GPIO_TypeDef* sevenDataPort[NUMBER_OF_SEGMENTS]={PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F, PORT_G};
uint16_t sevenDataPin[NUMBER_OF_SEGMENTS]={PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G};
//static uint8_t status=0;
int redTime,greenTime,yellowTime;
void disableAllSevenSegment(){
	HAL_GPIO_WritePin(EN_0_PORT, EN_0_PIN, SET);
	HAL_GPIO_WritePin(EN_1_PORT, EN_1_PIN, SET);
	HAL_GPIO_WritePin(EN_2_PORT, EN_2_PIN, SET);
	HAL_GPIO_WritePin(EN_3_PORT, EN_3_PIN, SET);
}
void update7SEG(uint8_t index_led){
	switch(index_led){
	case First:
		disableAllSevenSegment();
		display7SEG(sevenSegmentCode[led_buffer[index_led]]);
		enableSevenSegmentPin(index_led);
		break;
	case Second:
		disableAllSevenSegment();
		display7SEG(sevenSegmentCode[led_buffer[index_led]]);
		enableSevenSegmentPin(index_led);
		break;
	case Third:
		disableAllSevenSegment();
		display7SEG(sevenSegmentCode[led_buffer[index_led]]);
		enableSevenSegmentPin(index_led);
		break;
	case Fourth:
		disableAllSevenSegment();
		display7SEG(sevenSegmentCode[led_buffer[index_led]]);
		enableSevenSegmentPin(index_led);
		break;
	default:
		break;
	}
}
void enableSevenSegmentPin(uint8_t ledIndex){
	switch(ledIndex){
	case First:
		HAL_GPIO_WritePin(EN_0_PORT, EN_0_PIN, RESET);
		break;
	case Second:
		HAL_GPIO_WritePin(EN_1_PORT, EN_1_PIN, RESET);
		break;
	case Third:
		HAL_GPIO_WritePin(EN_2_PORT, EN_2_PIN, RESET);
		break;
	case Fourth:
		HAL_GPIO_WritePin(EN_3_PORT, EN_3_PIN, RESET);
		break;
	}
}
void display7SEG(uint8_t number){
	for(uint8_t segmentIndex=0; segmentIndex< NUMBER_OF_SEGMENTS; segmentIndex++){
		HAL_GPIO_WritePin(sevenDataPort[segmentIndex], sevenDataPin[segmentIndex],
				(GPIO_PinState)(number>>segmentIndex)&(0x01));
	}
}
void updateLedBuffer(uint8_t status){
	if(REDTIME==0 && GREENTIME==0 &&YELLOWTIME==0){
		led_buffer[0]=0;
		led_buffer[1]=0;
		led_buffer[2]=0;
		led_buffer[3]=0;
		return;
	}
	if(status%2==0){
		//led0 & led1 are red
		led_buffer[0]= redTime/MINIMUM_TWO_DIGITS_NUMBER;
		led_buffer[1]=redTime%MINIMUM_TWO_DIGITS_NUMBER;
		//led2 & led3 are green and yellow
		if(greenTime>0){
			led_buffer[2]=greenTime/MINIMUM_TWO_DIGITS_NUMBER;
			led_buffer[3]=greenTime%MINIMUM_TWO_DIGITS_NUMBER;
		}
		else{
			led_buffer[2]=yellowTime/MINIMUM_TWO_DIGITS_NUMBER;
			led_buffer[3]=yellowTime%MINIMUM_TWO_DIGITS_NUMBER;
		}
	}
	else{
		//led2 & led3 are red
		//led0 & led1 are green and yellow
		led_buffer[2]= redTime/MINIMUM_TWO_DIGITS_NUMBER;
		led_buffer[3]=redTime%MINIMUM_TWO_DIGITS_NUMBER;
		//led2 & led3
		if(greenTime>0){
			led_buffer[0]=greenTime/MINIMUM_TWO_DIGITS_NUMBER;
			led_buffer[1]=greenTime%MINIMUM_TWO_DIGITS_NUMBER;
		}
		else{
			led_buffer[0]=yellowTime/MINIMUM_TWO_DIGITS_NUMBER;
			led_buffer[1]=yellowTime%MINIMUM_TWO_DIGITS_NUMBER;
		}
	}
}
void setTimeForTrafficLight(){
	redTime=REDTIME;
	greenTime=GREENTIME;
	yellowTime=YELLOWTIME;

}
void updateTimeDurationLedBuffer(int mode,int value){
	switch(mode){
	case SECOND_MODE:
		led_buffer[0]=value/MINIMUM_TWO_DIGITS_NUMBER;
		led_buffer[1]=value%MINIMUM_TWO_DIGITS_NUMBER;
		led_buffer[2]=mode/MINIMUM_TWO_DIGITS_NUMBER;
		led_buffer[3]=mode%MINIMUM_TWO_DIGITS_NUMBER;
		break;
	case THIRD_MODE:
		led_buffer[0]=value/MINIMUM_TWO_DIGITS_NUMBER;
		led_buffer[1]=value%MINIMUM_TWO_DIGITS_NUMBER;
		led_buffer[2]=mode/MINIMUM_TWO_DIGITS_NUMBER;
		led_buffer[3]=mode%MINIMUM_TWO_DIGITS_NUMBER;
		break;
	case FOURTH_MODE:
		led_buffer[0]=value/MINIMUM_TWO_DIGITS_NUMBER;
		led_buffer[1]=value%MINIMUM_TWO_DIGITS_NUMBER;
		led_buffer[2]=mode/MINIMUM_TWO_DIGITS_NUMBER;
		led_buffer[3]=mode%MINIMUM_TWO_DIGITS_NUMBER;
		break;
	default:
		break;
	}
}
