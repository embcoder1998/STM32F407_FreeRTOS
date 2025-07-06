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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LED_APPLICATION_H
#define __LED_APPLICATION_H


#include "stdio.h"

// different delay standard macro define

#define _DELEAY_ONE_MS        1000
#define _DELAY_TEN_MS         _DELEAY_ONE_MS * 10
#define _DELAY_HUNDRED_MS     _DELAY_TEN_MS * 10
#define _DELAY_ONE_S          _DELAY_HUNDRED_MS * 10



// Function Declrration
void orangeLed(void);
void greenLed(void);
void redLed(void);
void blueLed(void);
void orangeLedToggling(void);

// base on the different led time delay
void orangeLedSetBlinkTime(uint32_t);
void greenLedSetBlinkTime(uint32_t);
void redLedSetBlinkTime(uint32_t);
void blueLedSetBlinkTime(uint32_t);



#endif   //__LED_APPLICATION_H
