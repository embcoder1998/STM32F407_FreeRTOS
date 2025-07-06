/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : flash_application.h
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

/*Block Name Block base addresses Size
Main memory
Sector 0 0x0800 0000 - 0x0800 3FFF 16 Kbytes
Sector 1 0x0800 4000 - 0x0800 7FFF 16 Kbytes
Sector 2 0x0800 8000 - 0x0800 BFFF 16 Kbytes
Sector 3 0x0800 C000 - 0x0800 FFFF 16 Kbytes
Sector 4 0x0801 0000 - 0x0801 FFFF 64 Kbytes
Sector 5 0x0802 0000 - 0x0803 FFFF 128 Kbytes
Sector 6 0x0804 0000 - 0x0805 FFFF 128 Kbytes
.
.
Sector 11 0x080E 0000 - 0x080F FFFF 128 Kbytes
System memory 0x1FFF 0000 - 0x1FFF 77FF 30 Kbytes
OTP area 0x1FFF 7800 - 0x1FFF 7A0F 528 bytes
Option bytes 0x1FFF C000 - 0x1FFF C00F 18*/
#ifndef FLASH_APPLICATION_H
#define FLASH_APPLICATION_H

/**********************Including the Header file**************************/

#include "stdio.h"
#include "string.h"
/*********************8function Prototype of flash memory***********************/

#define WRITE_READ_FLASH_SECTOR_ELEVEN_STAR_ADDRESS    0x080E0000U
#define WRITE_READ_FLASH_SECTOR_ELEVEN_END_ADDRESS     0x080FFFFF
/* the some important process to follow to write the data in the flash
 * 1. start the page address
 * 2. decide the data type
 * 3. first flash should be the unlock by using the function unlock
 * 4. base on the number of words and start the page address , it will calcuated the number of the pages required to stroe that data into
 * 5. no of sector required to erase and the new data will be written in them
 * flash will be locked again
 */
/******************8 this is the important instruction to write the data in the flash************/


// wtite the data in the flash memory
uint32_t Flash_Write_Data (uint32_t, uint32_t *, uint16_t);

// read the data from the flash memory
void Flash_Read_Data (uint32_t, uint32_t *, uint16_t);

//testing code of the flash memory
void testing_flash_data();
#endif
