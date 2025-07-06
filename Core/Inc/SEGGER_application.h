/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : SEGGER_application.h
  * @brief          : Header for flash_application.c file.
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

#ifndef SEGGER_APPLICATION_H
#define SEGGER_APPLICATION_H

#include "led_application.h"
#include "SEGGER_RTT.h"
// function prototype


// this is the intilize funciton
void SEEGER_RTTInit(void);

// this function able to read the data as char at a time
void EGGER_RTTReadChar(void);

// create my own user Print function
void UserPrintf(const char *userBuffer);











#endif
