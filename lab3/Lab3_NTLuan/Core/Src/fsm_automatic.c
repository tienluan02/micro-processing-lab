/*
 * fsm_automatic.c
 *
 *  Created on: May 7, 2024
 *      Author: NguyenTienLuan
 */
#ifndef SRC_FSM_AUTOMATIC_C_
#define SRC_FSM_AUTOMATIC_C_

#include "fsm_automatic.h"


void fsm_automatic_run(){

	switch(statusLed){
		case INIT:
			red_green();
			statusLed = RED_GREEN;
			setTimer0(TIME_NORMAL_GREEN*100);
			setTimer1(1);
			setTimer2(100);
			break;
		case RED_GREEN:
			red_green();
			if (timer0_flag == 1){
				statusLed = RED_YELLOW;
				count1 = TIME_NORMAL_YELLOW;
				count2 = TIME_NORMAL_YELLOW;
				setTimer0(TIME_NORMAL_YELLOW*100);
			}
			if (is_button_pressed(0) == 1){
					statusLed = MAN_RED;
					mode = 2;
					setTimer3(20);
					setTimer0(1000);
			}
			break;

		case RED_YELLOW:
			red_yellow();
			if (timer0_flag == 1){
				statusLed = GREEN_RED;
				count1 = TIME_NORMAL_GREEN;
				count2 = TIME_NORMAL_RED;
				setTimer0(TIME_NORMAL_GREEN*100);
			}
			break;
			if (is_button_pressed(0) == 1){
					statusLed = MAN_RED;
					mode = 2;
					setTimer3(20);
					setTimer0(1000);
			}
		case GREEN_RED:
			green_red();
			if (timer0_flag == 1){
				statusLed = YELLOW_RED;
				count1 = TIME_NORMAL_YELLOW;
				count2= TIME_NORMAL_YELLOW;
				setTimer0(TIME_NORMAL_YELLOW*100);
			}
			if (is_button_pressed(0) == 1){
					statusLed = MAN_GREEN;
					mode = 2;
					setTimer3(20);
					setTimer0(1000);
			}
			break;

		case YELLOW_RED:
			yellow_red();
			if (timer0_flag == 1){
				statusLed = RED_GREEN;
				count1 = TIME_NORMAL_RED;
				count2 = TIME_NORMAL_GREEN;
				setTimer0(TIME_NORMAL_GREEN*100);
			}
			if (is_button_pressed(0) == 1){
					statusLed = MAN_YELLOW;
					mode = 2;
					setTimer3(20);
					setTimer0(1000);
			}
			break;
		default:
			break;
	}
	// decrease time each second
	if (timer2_flag == 1){
		count1--;
		count2--;
		setTimer2(100);
	}
	// display 7seg
	if (timer1_flag == 1){
		  handle7SEG();
		  setTimer1(1);
	 }


}
void handle7SEG(){
	switch (mode){
		case 1:
			update7SEG();
			break;
		default:
			update7SEG_2(countMan1);
			break;
	}
}
#endif /* SRC_FSM_AUTOMATIC_C_ */
