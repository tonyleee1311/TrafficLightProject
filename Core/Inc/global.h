/*
 * global.h
 *
 *  Created on: Oct 31, 2022
 *      Author: nguye
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include"main.h"
#include"PortPin.h"
#include"softwaretimer.h"
#include"button.h"
#include"trafficlight.h"
#include"sevensegment.h"
#include"fsm_mode.h"
#define MINIMUM_TWO_DIGITS_NUMBER 10
#define MAXIMUM_TWO_DIGITS_NUMBER 99
#define ONE_SECOND 1000
#define HALF_SECOND 500
#define HUNDRED_MILLISECOND 50
#define INIT 0
#define FIRST_MODE 1
#define SECOND_MODE 2
#define THIRD_MODE 3
#define FOURTH_MODE 4
#define FIRST_BUTTON 0
#define SECOND_BUTTON 1
#define THIRD_BUTTON 2
#define FOURTH_BUTTON 3
extern int mode;
extern uint8_t statusOfTrafficLight;
extern int REDTIME, GREENTIME, YELLOWTIME;

#endif /* INC_GLOBAL_H_ */
