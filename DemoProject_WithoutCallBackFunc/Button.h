/*
 * Button.h
 *
 *  Created on: Sep 2, 2023
 *      Author: Dell
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include "lstd.h"

extern u8_t Button1_PressedFlag;
extern u8_t Button2_PressedFlag;
extern u8_t RedLedState;


void ButtonInitializations(void);
void Application_PortFCallBackFunc(void);
void ReadButtonState(void);

#endif /* BUTTON_H_ */
