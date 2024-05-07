/*
 * button.h
 *
 *  Created on: May 7, 2024
 *  	Author: NguyenTienLuan
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

//extern int button1_flag;

//int isButtonPressed();

void getKeyInput();
int is_button_pressed ( int index );
int is_long_button_flag();

#endif /* INC_BUTTON_H_ */
