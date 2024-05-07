/*
 * control_led.c
 *
 *  Created on: May 7, 2024
 *      Author: NguyenTienLuan
 */

#include "control_led.h"
#include "global.h"

int index_led = 0;

void red_green(){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);

	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
}
void red_yellow(){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);

	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);
}
void green_red(){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);

	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);
}
void yellow_red(){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);

	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);
}
void green_green(){
	HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);

	HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port,LED_GREEN_2_Pin );
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, RESET);

}
void red_red(){
	HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);

	HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);

}
void yellow_yellow(){
	HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);


	HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port,LED_YELLOW_2_Pin );
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port,LED_RED_2_Pin , RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);
}
void update7SEG (){

	switch (index_led)
		  {
			  case 0:
				  HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT_1_GPIO_Port, DIGIT_1_Pin, GPIO_PIN_SET);
				  display7SEG(count1 / 10);
				  index_led = 1;
				  break;
			  case 1:
				  HAL_GPIO_WritePin(DIGIT_1_GPIO_Port, DIGIT_1_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT_2_GPIO_Port, DIGIT_2_Pin, GPIO_PIN_SET);
				  display7SEG(count1 % 10);
				  index_led = 2;
				  break;
			  case 2:
				  HAL_GPIO_WritePin(DIGIT_2_GPIO_Port, DIGIT_2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT_3_GPIO_Port, DIGIT_3_Pin, GPIO_PIN_SET);
				  display7SEG(count2 / 10);
				  index_led = 3;
				  break;
			  case 3:
				  HAL_GPIO_WritePin(DIGIT_3_GPIO_Port,DIGIT_3_Pin , GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT_4_GPIO_Port,DIGIT_4_Pin, GPIO_PIN_SET);
				  display7SEG(count2 % 10);
				  index_led = 4;
				  break;
			  case 4:
				  HAL_GPIO_WritePin(DIGIT_4_GPIO_Port,DIGIT_4_Pin , GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(MODE_GPIO_Port,MODE_Pin, GPIO_PIN_SET);
				  display7SEG(mode);
				  index_led = 0;
				  break;
		  }

}
void update7SEG_2 (int num){

	switch (index_led)
		  {
			  case 0:
				  HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT_1_GPIO_Port, DIGIT_1_Pin, GPIO_PIN_SET);
				  display7SEG(num / 10);
				  index_led = 1;
				  break;
			  case 1:
				  HAL_GPIO_WritePin(DIGIT_1_GPIO_Port, DIGIT_1_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT_2_GPIO_Port, DIGIT_2_Pin, GPIO_PIN_SET);
				  display7SEG(num % 10);
				  index_led = 2;
				  break;
			  case 2:
				  HAL_GPIO_WritePin(DIGIT_2_GPIO_Port, DIGIT_2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT_3_GPIO_Port, DIGIT_3_Pin, GPIO_PIN_SET);
				  display7SEG(num / 10);
				  index_led = 3;
				  break;
			  case 3:
				  HAL_GPIO_WritePin(DIGIT_3_GPIO_Port,DIGIT_3_Pin , GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT_4_GPIO_Port,DIGIT_4_Pin, GPIO_PIN_SET);
				  display7SEG(num % 10);
				  index_led = 4;
				  break;
			  case 4:
				  HAL_GPIO_WritePin(DIGIT_4_GPIO_Port,DIGIT_4_Pin , GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(MODE_GPIO_Port,MODE_Pin, GPIO_PIN_SET);
				  display7SEG(mode);
				  index_led = 0;
				  break;
		  }

}
void display7SEG(int k){
	switch (k){
	case 0:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_B_Pin|LED_C_Pin|LED_D_Pin
		                          |LED_E_Pin|LED_F_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA, LED_G_Pin, GPIO_PIN_SET);
		break;
	case 1:
		  HAL_GPIO_WritePin(GPIOA, LED_B_Pin|LED_C_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_D_Pin
		                          |LED_E_Pin|LED_F_Pin|LED_G_Pin, GPIO_PIN_SET);
		break;
	case 2:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_B_Pin | LED_D_Pin
		                          |LED_E_Pin|LED_G_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA,LED_C_Pin|LED_F_Pin, GPIO_PIN_SET);
		break;
	case 3:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_B_Pin|LED_C_Pin|LED_D_Pin
		                          |LED_G_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOA, LED_E_Pin|LED_F_Pin, GPIO_PIN_SET);
		break;
	case 4:
		  HAL_GPIO_WritePin(GPIOA, LED_B_Pin|LED_C_Pin |LED_F_Pin|LED_G_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_D_Pin|LED_E_Pin, GPIO_PIN_SET);
		break;
	case 5:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_C_Pin|LED_D_Pin
		                          |LED_F_Pin|LED_G_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA,LED_B_Pin|LED_E_Pin, GPIO_PIN_SET);
		break;
	case 6:
		  HAL_GPIO_WritePin(GPIOA,LED_B_Pin, GPIO_PIN_SET);

		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_C_Pin|LED_D_Pin
		                          |LED_E_Pin|LED_F_Pin|LED_G_Pin, GPIO_PIN_RESET);

		break;
	case 7:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_B_Pin|LED_C_Pin , GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA, LED_D_Pin |LED_E_Pin|LED_F_Pin|LED_G_Pin, GPIO_PIN_SET);
		break;
	case 8:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_B_Pin|LED_C_Pin|LED_D_Pin
		                          |LED_E_Pin|LED_F_Pin|LED_G_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_B_Pin|LED_C_Pin|LED_D_Pin
		                          |LED_F_Pin|LED_G_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA, LED_E_Pin, GPIO_PIN_SET);
		break;
	default:
		break;
	}
}
