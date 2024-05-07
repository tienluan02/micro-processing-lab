/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_A_Pin GPIO_PIN_1
#define LED_A_GPIO_Port GPIOA
#define LED_B_Pin GPIO_PIN_2
#define LED_B_GPIO_Port GPIOA
#define LED_C_Pin GPIO_PIN_3
#define LED_C_GPIO_Port GPIOA
#define LED_D_Pin GPIO_PIN_4
#define LED_D_GPIO_Port GPIOA
#define LED_E_Pin GPIO_PIN_5
#define LED_E_GPIO_Port GPIOA
#define LED_F_Pin GPIO_PIN_6
#define LED_F_GPIO_Port GPIOA
#define LED_G_Pin GPIO_PIN_7
#define LED_G_GPIO_Port GPIOA
#define BUTTON_1_Pin GPIO_PIN_0
#define BUTTON_1_GPIO_Port GPIOB
#define BUTTON_2_Pin GPIO_PIN_1
#define BUTTON_2_GPIO_Port GPIOB
#define BUTTON_3_Pin GPIO_PIN_2
#define BUTTON_3_GPIO_Port GPIOB
#define DIGIT_1_Pin GPIO_PIN_8
#define DIGIT_1_GPIO_Port GPIOA
#define DIGIT_2_Pin GPIO_PIN_9
#define DIGIT_2_GPIO_Port GPIOA
#define DIGIT_3_Pin GPIO_PIN_10
#define DIGIT_3_GPIO_Port GPIOA
#define DIGIT_4_Pin GPIO_PIN_11
#define DIGIT_4_GPIO_Port GPIOA
#define LED_RED_1_Pin GPIO_PIN_12
#define LED_RED_1_GPIO_Port GPIOA
#define LED_YELLOW_1_Pin GPIO_PIN_13
#define LED_YELLOW_1_GPIO_Port GPIOA
#define LED_GREEN_1_Pin GPIO_PIN_14
#define LED_GREEN_1_GPIO_Port GPIOA
#define MODE_Pin GPIO_PIN_15
#define MODE_GPIO_Port GPIOA
#define LED_RED_2_Pin GPIO_PIN_5
#define LED_RED_2_GPIO_Port GPIOB
#define LED_YELLOW_2_Pin GPIO_PIN_6
#define LED_YELLOW_2_GPIO_Port GPIOB
#define LED_GREEN_2_Pin GPIO_PIN_7
#define LED_GREEN_2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
