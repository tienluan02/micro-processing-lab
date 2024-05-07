/*
 * fsm_manual.c
 *
 *  Created on: May 7, 2024
 *      Author: NguyenTienLuan
 */

#include "fsm_manual.h"
#include "global.h"



void fsm_manual_run(){



	switch(statusLed){
		case MAN_RED:
			if (timer3_flag == 1){
				red_red();
				setTimer3(20);
			}
//			red_green();

			if (timer0_flag == 1 ){
				statusLed = GREEN_RED;
				count1 = TIME_NORMAL_GREEN;
				count2 = TIME_NORMAL_RED;
				setTimer1(TIME_NORMAL_GREEN);
				mode = 1;
			}
			if ((is_long_button_flag() == 1)){
				countMan1++;
			}
			if (is_button_pressed(0) == 1){
				statusLed = MAN_YELLOW;
				countMan1 = TIME_NORMAL_YELLOW;
				mode = 3;
				setTimer0(10000);
			}
			if (is_button_pressed(1) == 1){
				countMan1 = countMan1 + 1;
			}
			if (is_button_pressed(2) == 1){
				statusLed = RED_GREEN;
				mode = 1;
				TIME_NORMAL_RED = countMan1;
				TIME_NORMAL_GREEN = countMan1 * 70/100;
				TIME_NORMAL_YELLOW = TIME_NORMAL_RED - TIME_NORMAL_GREEN;

				count1 = TIME_NORMAL_RED;
				count2 = TIME_NORMAL_GREEN;
				setTimer0(TIME_NORMAL_GREEN*100);

			}
			break;
		case MAN_YELLOW:
//			yellow_red();
			if (timer3_flag == 1){
				yellow_yellow();
				setTimer3(20);
			}
			if (timer0_flag == 1 ){
				statusLed = YELLOW_RED;
				count1 = TIME_NORMAL_YELLOW;
				count2 = TIME_NORMAL_RED;
				setTimer1(TIME_NORMAL_YELLOW);
			}
			if (is_button_pressed(0) == 1){
				statusLed = MAN_GREEN;
				countMan1 = TIME_NORMAL_GREEN;
				mode = 4;
				setTimer0(10000);
			}
			if (is_button_pressed(1) == 1){
				countMan1 = countMan1 + 1;
			}
			if ((is_long_button_flag() == 1)){
				countMan1++;
			}
			if (is_button_pressed(2) == 1){
				statusLed = YELLOW_RED;
				mode = 1;
				TIME_NORMAL_YELLOW = countMan1;
				TIME_NORMAL_RED = countMan1 /0.3;
				TIME_NORMAL_GREEN = TIME_NORMAL_RED - TIME_NORMAL_YELLOW;

				count1 = TIME_NORMAL_YELLOW;
				count2 = TIME_NORMAL_RED;
				setTimer0(TIME_NORMAL_YELLOW*100);

			}
			break;
		case MAN_GREEN:
//			green_red();
			if (timer3_flag == 1){
				green_green();
				setTimer3(20);
			}
			if (timer0_flag == 1 ){
				statusLed = GREEN_RED;
				count1 = TIME_NORMAL_GREEN;
				count2 = TIME_NORMAL_RED;
				setTimer1(TIME_NORMAL_GREEN);
			}
			if (is_button_pressed(0) == 1){
				statusLed = MAN_RED;
				countMan1 = TIME_NORMAL_RED;
				mode = 2;
				setTimer0(10000);
			}
			if (is_button_pressed(1) == 1){
				countMan1 = countMan1 + 1;
			}
			if ((is_long_button_flag() == 1)){
				countMan1++;
			}
			if (is_button_pressed(2) == 1){
				statusLed = GREEN_RED;
				mode = 1;
				TIME_NORMAL_GREEN = countMan1;
				TIME_NORMAL_RED = countMan1/0.7;
				TIME_NORMAL_YELLOW = TIME_NORMAL_RED - TIME_NORMAL_GREEN;

				count1 = TIME_NORMAL_GREEN;
				count2 = TIME_NORMAL_RED;
				setTimer0(TIME_NORMAL_GREEN*100);

			}
			break;
		default:
			break;
	}
}
