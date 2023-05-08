/*
 * softwaretimer.h
 *
 *  Created on: Oct 30, 2022
 *      Author: nguye
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_
#include "main.h"
#define TIME_CYCLE 10
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;
extern int timer5_flag;
void setTimer1(uint16_t duration);
void setTimer2(uint16_t duration);
void setTimer3(uint16_t duration);
void setTimer4(uint16_t duration);
void setTimer5(uint16_t duration);
void timerRun();


#endif /* INC_SOFTWARETIMER_H_ */
