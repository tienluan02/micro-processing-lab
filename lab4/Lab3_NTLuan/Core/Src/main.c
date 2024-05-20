/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "global.h"
#include <stdio.h>

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;
volatile uint32_t tick_count = 0;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void print_time_10ms(void);
void print_time_500ms(void);
uint32_t get_time(void);

/* Main program body ---------------------------------------------------------*/
int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_TIM2_Init();

  /* Initialize all configured peripherals */
  HAL_TIM_Base_Start_IT(&htim2);

  /* Register tasks with the scheduler */
  SCH_Add_Task(print_time_10ms, 10, 10);   // Print time every 10ms
  SCH_Add_Task(print_time_500ms, 500, 500); // Print time every 500ms

  /* Infinite loop */
  while (1)
  {
    SCH_Dispatch_Tasks();
  }
}

/* TIM2 Initialization Function ----------------------------------------------*/
static void MX_TIM2_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
}

/* GPIO Initialization Function ----------------------------------------------*/
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /* Configure GPIO pins */
  // Your existing GPIO initialization code

}

/* Timer callback function ---------------------------------------------------*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM2)
  {
    tick_count++;
    SCH_Update();
  }
}

/* Print the current timestamp every 10ms ------------------------------------*/
void print_time_10ms(void)
{
  printf("10ms Tick: %lu\n", get_time());
}

/* Print the current timestamp every 500ms -----------------------------------*/
void print_time_500ms(void)
{
  printf("500ms Tick: %lu\n", get_time());
}

/* Get the current time in ms ------------------------------------------------*/
uint32_t get_time(void)
{
  return tick_count * 10; // Each tick is 10ms
}

/* Error Handler Function ----------------------------------------------------*/
void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}

/* Additional Code for Full Assert -------------------------------------------*/
#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
  // User can add his own implementation to report the file name and line number
}
#endif
