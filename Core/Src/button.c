/*
 * button.c
 *
 *  Created on: Oct 31, 2022
 *      Author: nguye
 */
#include"button.h"
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS]={BUTTON_IS_RELEASED,BUTTON_IS_RELEASED,BUTTON_IS_RELEASED};
static GPIO_PinState debouncebuttonBuffer1[NO_OF_BUTTONS]={BUTTON_IS_RELEASED,BUTTON_IS_RELEASED,BUTTON_IS_RELEASED};
static GPIO_PinState debouncebuttonBuffer2[NO_OF_BUTTONS]={BUTTON_IS_RELEASED,BUTTON_IS_RELEASED,BUTTON_IS_RELEASED};
GPIO_TypeDef* buttonPort[NO_OF_BUTTONS]={BUTTON1_PORT,BUTTON2_PORT,BUTTON3_PORT};
uint16_t buttonPin[NO_OF_BUTTONS]={BUTTON1_PIN,BUTTON2_PIN, BUTTON3_PIN};
void buttonReading(){
	for(int i=0;i<NO_OF_BUTTONS;i++){
		debouncebuttonBuffer1[i]=debouncebuttonBuffer2[i];
		debouncebuttonBuffer2[i]=HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);
		if(debouncebuttonBuffer2[i]==debouncebuttonBuffer1[i]){
			buttonBuffer[i]=debouncebuttonBuffer2[i];
		}
	}
}
int isButtonPressed(int index){
	if(index>NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index]==BUTTON_IS_PRESSED);
}
