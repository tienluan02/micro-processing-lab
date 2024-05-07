/*
 * button.c
 *
 *  Created on: May 7, 2024
 *      Author: NguyenTienLuan
 */

#include "button.h"
#define TIME_FOR_LONG_KEY 25
#define TIME_FOR_PRESS_KEY 200
#define NUM_BUTTONS 3

int KeyReg0[NUM_BUTTONS] = { SET };
int KeyReg1[NUM_BUTTONS] = { SET };
int KeyReg2[NUM_BUTTONS] = { SET };
int KeyReg3[NUM_BUTTONS] = { SET };

int TimeOutForKeyPress = TIME_FOR_PRESS_KEY;
int TimeOutForLongKeyPress = TIME_FOR_LONG_KEY;

int button_flag[NUM_BUTTONS] = { RESET };
int button_flag_1s[NUM_BUTTONS] = { RESET };

int long_button_flag = 0;

int is_button_pressed(int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index) {
	//TODO
	button_flag[index] = 1;

}
int is_long_button_flag() {
	if (long_button_flag == 1) {
		long_button_flag = 0;
		return 1;
	}
	return 0;
}
//int is_button_pressed_1s(int index){
//	if(button_flag_1s[index] == 1){
//		button_flag_1s[index] = 0;
//		return 1;
//	}
//	return 0;
//}
void getKeyInput() {
	for (int i = 0; i < 3; i++) {
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		switch (i) {
		case 0:
			KeyReg0[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
			break;
		case 1:
			KeyReg0[i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
			break;
		case 2:
			KeyReg0[i] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);
			break;
		default:
			break;
		}
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if (KeyReg2[i] != KeyReg3[i]) {
				KeyReg3[i] = KeyReg2[i];

				if (KeyReg3[i] == PRESSED_STATE) {
					subKeyProcess(i);
				}
			} else {
				TimeOutForKeyPress--;

				if (TimeOutForKeyPress == 0) {
					if (KeyReg2[i] == PRESSED_STATE) {
						TimeOutForKeyPress = TIME_FOR_PRESS_KEY;
						button_flag_1s[i] = 1;

					}
				}
				if ((button_flag_1s[i] == 1)) {
					TimeOutForLongKeyPress--;

					if (TimeOutForLongKeyPress == 0) {
						long_button_flag = 1;
						TimeOutForLongKeyPress = TIME_FOR_LONG_KEY;
					}
				}

			}
		} else {
			button_flag_1s[i] = 0;
			TimeOutForKeyPress = TIME_FOR_PRESS_KEY;
		}
	}
}
