/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  * STM32F103C6
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define Disp1_On	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET)
#define Disp1_Off	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET)
#define Disp2_On	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET)
#define Disp2_Off	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET)
#define Disp3_On	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET)
#define Disp3_Off	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET)
#define Disp4_On	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET)
#define Disp4_Off	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET)
#define Column1_On  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET)
#define Column1_Off HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET)
#define Column2_On  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET)
#define Column2_Off HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET)
#define Column3_On  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, SET)
#define Column3_Off HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET)
#define Row1_On  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == 1
#define Row2_On  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 1
#define Row3_On  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2) == 1
#define Row4_On  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
char Numero = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void Display_Send(char data);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  Column1_On;
	  if(Row1_On){Display_Send(1);}
	  if(Row2_On){Display_Send(4);}
	  if(Row3_On){Display_Send(7);}
	  if(Row4_On){Display_Send(10);}
	  Column1_Off;

	  Column2_On;
	  if(Row1_On){Display_Send(2);}
	  if(Row2_On){Display_Send(5);}
	  if(Row3_On){Display_Send(8);}
	  if(Row4_On){Display_Send(0);}
	  Column2_Off;

	  Column3_On;
	  if(Row1_On){Display_Send(3);}
	  if(Row2_On){Display_Send(6);}
	  if(Row3_On){Display_Send(9);}
	  if(Row4_On){Display_Send(11);}
	  Column3_Off;


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA2 PA4 PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_4|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PA8 PA10 PA12 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void Display_Send(char data)
{
	switch(data){
	case 0: {Disp1_Off; Disp2_Off; Disp3_Off; Disp4_Off;}
			break;
	case 1: {Disp1_On; Disp2_Off; Disp3_Off; Disp4_Off;}
			break;
	case 2: {Disp1_Off; Disp2_On; Disp3_Off; Disp4_Off;}
			break;
	case 3: {Disp1_On; Disp2_On; Disp3_Off; Disp4_Off;}
			break;
	case 4: {Disp1_Off; Disp2_Off; Disp3_On; Disp4_Off;}
			break;
	case 5: {Disp1_On; Disp2_Off; Disp3_On; Disp4_Off;}
			break;
	case 6: {Disp1_Off; Disp2_On; Disp3_On; Disp4_Off;}
			break;
	case 7: {Disp1_On; Disp2_On; Disp3_On; Disp4_Off;}
			break;
	case 8: {Disp1_Off; Disp2_Off; Disp3_Off; Disp4_On;}
			break;
	case 9: {Disp1_On; Disp2_Off; Disp3_Off; Disp4_On;}
			break;
	case 10: {Disp1_Off; Disp2_On; Disp3_Off; Disp4_On;}
			break;
	case 11: {Disp1_Off; Disp2_On; Disp3_On; Disp4_On;}
			break;


	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
