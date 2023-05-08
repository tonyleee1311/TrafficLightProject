/*
 * button.h
 *
 *  Created on: Oct 31, 2022
 *      Author: nguye
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include"main.h"
#include"global.h"
#define NO_OF_BUTTONS 3
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET
void buttonReading();
int isButtonPressed(int index);


#endif /* INC_BUTTON_H_ */
