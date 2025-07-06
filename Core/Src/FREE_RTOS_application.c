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
#include "stdio.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "FREE_RTOS_application.h"
#include "SEGGER_application.h"
#include "led_application.h"



// Here the declare all the handle those passing when task is created
/*
* all four task will be created to most of the senario
* this is the genric task that will never changed all process excuted the from this task
* Intialli this task handle intilize by the NULL value
*/
static xTaskHandle taskHandleOne =   NULL;
static xTaskHandle taskHandleTwo =   NULL;
static xTaskHandle taskHandleThree = NULL;
static xTaskHandle taskHandleFour =  NULL;


// creating the all task
void callingTaskCreation(void){

	BaseType_t xReturned;

	// create task one
    /* Create the task, storing the handle. */
    xReturned = xTaskCreate(
    				userTaskOne,                    /* Function that implements the task. */
                    "TASK1",                        /* Text name for the task. */
					configMINIMAL_STACK_SIZE,       /* Stack size in words, not bytes. */
                    ( void * ) TASK_ONE_PARAMETER,  /* Parameter passed into the task. */
					(configMAX_PRIORITIES - 3),     /* Priority at which the task is created. */
                    &taskHandleOne );               /* Used to pass out the created task's handle. */
 /*
// after creation if you want to delete the task then you can delete the task
    if( xReturned == pdPASS )
    {
         The task was created. Use the task's handle to delete the task.
        vTaskDelete( xHandle );
    }
*/

    //if task is not created the through the falut that we can check as run time
    configASSERT(xReturned == pdPASS);

    // create the second task
    /* Create the task, storing the handle. */
    xReturned = xTaskCreate(
    				userTaskTwo,                    /* Function that implements the task. */
                    "TASK2",                        /* Text name for the task. */
					configMINIMAL_STACK_SIZE,       /* Stack size in words, not bytes. */
                    ( void * ) TASK_TWO_PARAMETER,  /* Parameter passed into the task. */
					(configMAX_PRIORITIES - 4),     /* Priority at which the task is created. */
                    &taskHandleTwo );               /* Used to pass out the created task's handle. */

    //if task is not created the through the falut that we can check as run time
    configASSERT(xReturned == pdPASS);

    // created the third task
    /* Create the task, storing the handle. */
    xReturned = xTaskCreate(
    				userTaskThree,                    /* Function that implements the task. */
                    "TASK3",                        /* Text name for the task. */
					configMINIMAL_STACK_SIZE,       /* Stack size in words, not bytes. */
                    ( void * ) TASK_THREE_PARAMETER,  /* Parameter passed into the task. */
					(configMAX_PRIORITIES - 5),     /* Priority at which the task is created. */
                    &taskHandleThree );               /* Used to pass out the created task's handle. */

    //if task is not created the through the falut that we can check as run time
    configASSERT(xReturned == pdPASS);

    // created the fourth task
    /* Create the task, storing the handle. */
    xReturned = xTaskCreate(
    				userTaskFour,                    /* Function that implements the task. */
                    "TASK4",                        /* Text name for the task. */
					configMINIMAL_STACK_SIZE,       /* Stack size in words, not bytes. */
                    ( void * ) TASK_FOUR_PARAMETER,  /* Parameter passed into the task. */
					(configMAX_PRIORITIES - 6),     /* Priority at which the task is created. */
                    &taskHandleFour);               /* Used to pass out the created task's handle. */

    //if task is not created the through the falut that we can check as run time
    configASSERT(xReturned == pdPASS);
}




/* First Task to be created. */
void userTaskOne( void * pvParameters )
{
    /* The parameter value is expected to be 1 as 1 is passed in the
       pvParameters value in the call to xTaskCreate() below. */
	configASSERT( ( ( uint32_t ) pvParameters ) ==(uint32_t) (TASK_ONE_PARAMETER ));

	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS(1);

	/* The xLastWakeTime variable needs to be initialized with the current tick
	count. Note that this is the only time the variable is written to explicitly.
	After this assignment, xLastWakeTime is updated automatically internally within
	vTaskDelayUntil(). */
	xLastWakeTime = xTaskGetTickCount() - 1;


    for( ;; )
    {
    	/* This task should execute every 50 milliseconds. Time is measured
    	in ticks. The pdMS_TO_TICKS macro is used to convert milliseconds
    	into ticks. xLastWakeTime is automatically updated within vTaskDelayUntil()
    	so is not explicitly updated by the task. */
    	vTaskDelayUntil( &xLastWakeTime, xPeriod );
        /* Task code goes here. */
    	UserPrintf("Task One is running......");
    }
}


/* Second Task to be created. */
void userTaskTwo( void * pvParameters )
{
    /* The parameter value is expected to be 1 as 1 is passed in the
       pvParameters value in the call to xTaskCreate() below. */

    configASSERT( ( ( uint32_t ) pvParameters ) == (uint32_t)(TASK_TWO_PARAMETER) );

	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS(2);

	/* The xLastWakeTime variable needs to be initialized with the current tick
	count. Note that this is the only time the variable is written to explicitly.
	After this assignment, xLastWakeTime is updated automatically internally within
	vTaskDelayUntil(). */
	xLastWakeTime = xTaskGetTickCount() - 2;

    for( ;; )
    {
    	/* This task should execute every 50 milliseconds. Time is measured
    	in ticks. The pdMS_TO_TICKS macro is used to convert milliseconds
    	into ticks. xLastWakeTime is automatically updated within vTaskDelayUntil()
    	so is not explicitly updated by the task. */
    	vTaskDelayUntil( &xLastWakeTime, xPeriod );

        /* Task code goes here. */
    	UserPrintf("Task Two is running......");
    }
}


/* third Task to be created. */
void userTaskThree( void * pvParameters )
{
    /* The parameter value is expected to be 1 as 1 is passed in the
       pvParameters value in the call to xTaskCreate() below. */

    configASSERT( ( ( uint32_t ) pvParameters ) == (uint32_t)(TASK_THREE_PARAMETER) );

	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS(4);

	/* The xLastWakeTime variable needs to be initialized with the current tick
	count. Note that this is the only time the variable is written to explicitly.
	After this assignment, xLastWakeTime is updated automatically internally within
	vTaskDelayUntil(). */
	xLastWakeTime = xTaskGetTickCount() - 4;

    for( ;; )
    {
    	/* This task should execute every 50 milliseconds. Time is measured
    	in ticks. The pdMS_TO_TICKS macro is used to convert milliseconds
    	into ticks. xLastWakeTime is automatically updated within vTaskDelayUntil()
    	so is not explicitly updated by the task. */
    	vTaskDelayUntil( &xLastWakeTime, xPeriod );

        /* Task code goes here. */
    	UserPrintf("Task Three is running......");
    }
}



/* fourth Task to be created. */
void userTaskFour( void * pvParameters )
{
    /* The parameter value is expected to be 1 as 1 is passed in the
       pvParameters value in the call to xTaskCreate() below. */

    configASSERT( ( ( uint32_t ) pvParameters ) ==(uint32_t) (TASK_FOUR_PARAMETER) );

	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS(8);

	/* The xLastWakeTime variable needs to be initialized with the current tick
	count. Note that this is the only time the variable is written to explicitly.
	After this assignment, xLastWakeTime is updated automatically internally within
	vTaskDelayUntil(). */
	xLastWakeTime = xTaskGetTickCount() - 8;

    for( ;; )
    {
    	/* This task should execute every 50 milliseconds. Time is measured
    	in ticks. The pdMS_TO_TICKS macro is used to convert milliseconds
    	into ticks. xLastWakeTime is automatically updated within vTaskDelayUntil()
    	so is not explicitly updated by the task. */
    	vTaskDelayUntil( &xLastWakeTime, xPeriod );

    	UserPrintf("Task Four is running......");
        /* Task code goes here. */
    }
}


void vApplicationIdleHook( void )
{
  // Your code here
	UserPrintf("Task Idle is running......");
	orangeLedToggling();
}
