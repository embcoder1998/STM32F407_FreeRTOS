/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : FREE_RTOS_application.h
  * @brief          : Header for FREE_RTOS_application.c file.
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

#ifndef FREE_RTOS_APPLICATION_H
#define FREE_RTOS_APPLICATION_H

/***************************************** Macro Defination******************************************************/
// first task parameter
#define TASK_ONE_PARAMETER         1

// second task parameter
#define TASK_TWO_PARAMETER         2

// third task parameter
#define TASK_THREE_PARAMETER       3

// fourth task parameter
#define TASK_FOUR_PARAMETER        4

/******************************************** END *************************************************************/

//creating the all task
void callingTaskCreation(void);

// first user task function
void userTaskOne (void *);

// second user task function
void userTaskTwo (void *);

// third user task function
void userTaskThree (void *);

// fourth user task function
void userTaskFour (void *);


















#endif
