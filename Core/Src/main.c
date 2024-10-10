/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_gpio_init.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#define  DISP_7SEG			GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7
#define  SEG_A					GPIO_PIN_0
#define  SEG_B					GPIO_PIN_1
#define  SEG_C					GPIO_PIN_2
#define  SEG_D					GPIO_PIN_3
#define  SEG_E					GPIO_PIN_4
#define  SEG_F					GPIO_PIN_5
#define  SEG_G					GPIO_PIN_6
#define  SEG_PT					GPIO_PIN_7
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
static void USR_Selchar_7seg(uint8_t digit);
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
	uint8_t counter = 0;
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
  /* Init app1 */
	// USR_GPIO_Init();
	
	/* Init app2 */
	USR_GPIO_7Seg_Init();
	USR_GPIO_Pushes_init(GPIOC, GPIO_PIN_15, GPIO_PIN_14);
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		/* App1 */
		/*
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0))
		{
			HAL_Delay(5);
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13|GPIO_PIN_14);
		}
		*/
    
		/* App2 */
		
		//HAL_GPIO_TogglePin(GPIOA, DISP_7SEG);
		//HAL_Delay(1000);
		
		USR_Selchar_7seg(counter);
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15))
		{
			HAL_Delay(200);
			if(counter >= 0 && counter < 9){
				counter++;
			}
			else {
				counter = 0;
			}
		}
		else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14))
		{
			HAL_Delay(200);
			if(counter > 0 && counter <= 9){
				counter--;
			}
			else {
				counter = 9;
			}
		}

		/*
		HAL_Delay(1000);
		if(counter < 10)
		{
			counter++;
		} 
		else
		{
			counter = 0;
		}
		*/
		
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


static void USR_Selchar_7seg(uint8_t digit)
{
	switch(digit)
	{
		case 0:
			HAL_GPIO_WritePin(GPIOA, SEG_G | SEG_PT, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, SEG_A | SEG_D | SEG_E | SEG_F | SEG_G | SEG_PT, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, SEG_B | SEG_C, GPIO_PIN_RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, SEG_C | SEG_F | SEG_PT, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, SEG_A | SEG_B | SEG_D | SEG_E | SEG_G, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, SEG_E | SEG_F | SEG_PT, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, SEG_A | SEG_B | SEG_C | SEG_D | SEG_G, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOA, SEG_A | SEG_D | SEG_E | SEG_PT, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, SEG_B | SEG_C | SEG_F | SEG_G, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOA, SEG_B | SEG_E | SEG_PT, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, SEG_A | SEG_C | SEG_D | SEG_F | SEG_G, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOA, SEG_B | SEG_PT, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, SEG_A | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G, GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOA, SEG_D | SEG_E | SEG_F | SEG_G | SEG_PT, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, SEG_A | SEG_B | SEG_C, GPIO_PIN_RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOA, SEG_PT, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOA, SEG_E, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, SEG_A | SEG_B | SEG_C | SEG_D | SEG_F | SEG_G, GPIO_PIN_RESET);
			break;
		default:
			HAL_GPIO_WritePin(GPIOA, DISP_7SEG, GPIO_PIN_SET);
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
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC14 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
// static void 
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
