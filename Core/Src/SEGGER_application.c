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


// including the header file

#include "stdio.h"
#include "string.h"
#include "SEGGER_application.h"


// defination of the function
void SEEGER_RTTInit(void){

	// this is the SEGGER in upbuffer initilize
	SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_SKIP);

	// testing the data
	SEGGER_RTT_printf(0,".........Hello FREE RTOS Embedded World...............\r\n");
}

void UserPrintf(const char *userBuffer){

	// this is the going to the proint the data on the console
	SEGGER_RTT_printf(0,"%s\r\n",&userBuffer[0]);
}

void SEGGER_RTTReadChar(void){

	char input;
	int size;
	size= SEGGER_RTT_Read(0, &input, 1u);
	if(size > 0){

		 SEGGER_RTT_printf(0,"%c",input);
	}

}
