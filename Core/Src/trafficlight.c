/*
 * trafficlight.c
 *
 *  Created on: Oct 29, 2022
 *      Author: nguye
 */
#include"trafficlight.h"
void turnOffAllTrafficLight(){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
	HAL_GPIO_WritePin(ORANGE_PORT, ORANGE_PIN, SET);
}
void turnOnAllTrafficLight(){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);
}
void turnOnRed(int value){
	switch(value){
	case TOP_BOTTOM:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
		break;
	case LEFT_RIGHT:
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
		break;
	default:
		break;
	}
}
void turnOnYellow(int value){
	switch(value){
	case TOP_BOTTOM:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
		break;
	case LEFT_RIGHT:
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
		break;
	default:
		break;
	}
}
void turnOnGreen(int value){
	switch(value){
	case TOP_BOTTOM:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);
		break;
	case LEFT_RIGHT:
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);
		break;
	default:
		break;
	}
}
void trafficLightProcessing(uint8_t status, int greenTime){
	if(REDTIME==0 && GREENTIME==0 && YELLOWTIME==0){
		return;
	}
	if(status%2==0){
		turnOnRed(TOP_BOTTOM);
		if(greenTime>0) turnOnGreen(LEFT_RIGHT);
		else turnOnYellow(LEFT_RIGHT);
	}
	else{
		turnOnRed(LEFT_RIGHT);
		if(greenTime>0) turnOnGreen(TOP_BOTTOM);
		else turnOnYellow(TOP_BOTTOM);
	}
}
void blinkLedForEachMode(int mode){
	switch(mode){
	case SECOND_MODE:
		HAL_GPIO_TogglePin(RED_1_PORT, RED_1_PIN);
		HAL_GPIO_TogglePin(RED_2_PORT, RED_2_PIN);
		break;
	case THIRD_MODE:
		HAL_GPIO_TogglePin(YELLOW_1_PORT, YELLOW_1_PIN);
		HAL_GPIO_TogglePin(YELLOW_2_PORT, YELLOW_2_PIN);
		break;
	case FOURTH_MODE:
		HAL_GPIO_TogglePin(GREEN_1_PORT, GREEN_1_PIN);
		HAL_GPIO_TogglePin(GREEN_2_PORT, GREEN_2_PIN);
		break;
	default:
		break;
	}
}
