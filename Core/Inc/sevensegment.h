/*
 * sevensegment.h
 *
 *  Created on: Oct 29, 2022
 *      Author: nguye
 */

#ifndef INC_SEVENSEGMENT_H_
#define INC_SEVENSEGMENT_H_
#include"global.h"
//define
#define NUMBER_OF_SEVEN_SEG_LED 4
#define NUMBER_OF_SEGMENTS 7
#define TIME_PERIOD 10
#define TIME_TO_CHANGE_SEVEN_LED 1000
extern int redTime, greenTime, yellowTime;
//function
void updateLedBuffer(uint8_t);
void updateTimeDurationLedBuffer(int,int);
void display7SEG(uint8_t);
void enableSevenSegmentPin(uint8_t );
void disableAllSevenSegment();
void update7SEG(uint8_t );
void setTimeForTrafficLight();
#endif /* INC_SEVENSEGMENT_H_ */
