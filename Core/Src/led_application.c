/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : led_application.h
  * @brief          : Header for led_application.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */


/****************User Instruction LED*******************************************
1.   LED3 ---> Orange LED
2.   LED4 ---> Green LED
3.   LED5 ---> Red LED
4.   LED6 ----> Blue LED
****************************User Instruction LED End***************************/


/* including header file */
#include "main.h"
#include "led_application.h"



// Orange LED Defination
void orangeLed(void){

	LL_GPIO_SetOutputPin(GPIOD , LED3_Pin);

	LL_mDelay(1000);

	LL_GPIO_ResetOutputPin(GPIOD , LED3_Pin);

	LL_mDelay(1000);
}

void orangeLedToggling(void){

	LL_GPIO_TogglePin(GPIOD,LED3_Pin);
}

// Green LED defination
void greenLed(void){

	LL_GPIO_SetOutputPin(GPIOD , LED4_Pin);

	LL_mDelay(1000);

	LL_GPIO_ResetOutputPin(GPIOD , LED4_Pin);

	LL_mDelay(1000);
}

// red LED defination
void redLed(void){

	LL_GPIO_SetOutputPin(GPIOD , LED5_Pin);

	LL_mDelay(1000);

	LL_GPIO_ResetOutputPin(GPIOD ,LED5_Pin);

	LL_mDelay(1000);
}

// blue LED Defination
void blueLed(void){

	LL_GPIO_SetOutputPin(GPIOD ,LED6_Pin);

	LL_mDelay(1000);

	LL_GPIO_ResetOutputPin(GPIOD , LED6_Pin);

	LL_mDelay(1000);
}


// Orange LED Defination
void orangeLedSetBlinkTime(uint32_t _delay_time){

	LL_GPIO_SetOutputPin(GPIOD , LED3_Pin);

	LL_mDelay(_delay_time);

	LL_GPIO_ResetOutputPin(GPIOD , LED3_Pin);

	LL_mDelay(_delay_time);
}



// Green LED defination
void greenLedSetBlinkTime(uint32_t _delay_time){

	LL_GPIO_SetOutputPin(GPIOD , LED4_Pin);

	LL_mDelay(_delay_time);

	LL_GPIO_ResetOutputPin(GPIOD , LED4_Pin);

	LL_mDelay(_delay_time);
}

// red LED defination
void redLedSetBlinkTime(uint32_t _delay_time){

	LL_GPIO_SetOutputPin(GPIOD , LED5_Pin);

	LL_mDelay(_delay_time);

	LL_GPIO_ResetOutputPin(GPIOD ,LED5_Pin);

	LL_mDelay(_delay_time);
}

// blue LED Defination
void blueLedSetBlinkTime(uint32_t _delay_time){

	LL_GPIO_SetOutputPin(GPIOD ,LED6_Pin);

	LL_mDelay(_delay_time);

	LL_GPIO_ResetOutputPin(GPIOD , LED6_Pin);

	LL_mDelay(_delay_time);
}

