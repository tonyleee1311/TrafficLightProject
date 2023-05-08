/*
 * trafficlight.h
 *
 *  Created on: Oct 29, 2022
 *      Author: nguye
 */

#ifndef INC_TRAFFICLIGHT_H_
#define INC_TRAFFICLIGHT_H_
#include "global.h"
#define TOP_BOTTOM 4
#define LEFT_RIGHT 1
void turnOffAllTrafficLight();
void turnOnAllTrafficLight();
void turnOnRed(int);
void turnOnYellow(int);
void turnOnGreen(int);
void trafficLightProcessing(uint8_t status, int greenTime);
void blinkLedForEachMode(int mode);
#endif /* INC_TRAFFICLIGHT_H_ */
