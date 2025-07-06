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

/*****************Function defination from here******************/
#include "main.h"
#include "flash_application.h"


uint32_t Flash_Write_Data (uint32_t StartSectorAddress, uint32_t *userData, uint16_t numberOfWords)
{
	static FLASH_EraseInitTypeDef EraseInitStruct;
	uint32_t SECTORError;
	int dataIndex=0;

	/* Unlock the Flash to enable the flash control register access *************/
	HAL_FLASH_Unlock();

	/* Erase the user Flash area */
	/* Get the number of sector to erase from 1st sector */
	/* only one sector i am using *****************
	uint32_t StartSector = GetSector(StartSectorAddress);
	uint32_t EndSectorAddress = StartSectorAddress + numberofwords*4;
	uint32_t EndSector = GetSector(EndSectorAddress);
	***********/
	uint32_t StartSector = (uint32_t)(FLASH_SECTOR_11);
	uint32_t EndSector = (uint32_t)(FLASH_SECTOR_11);

	/* Fill EraseInit structure*/
	EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
	EraseInitStruct.Sector        = StartSector;
	EraseInitStruct.NbSectors     = (EndSector - StartSector) + 1;

	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR );
	/* Note: If an erase operation in Flash memory also concerns data in the data or instruction cache,
	you have to make sure that these data are rewritten before they are accessed during code
	execution. If this cannot be done safely, it is recommended to flush the caches by setting the
	DCRST and ICRST bits in the FLASH_CR register. */
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK)
	{
		return HAL_FLASH_GetError ();
	}

	/* Program the user Flash area word by word
	(area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/
	while (dataIndex<numberOfWords)
	{
		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, StartSectorAddress, userData[dataIndex]) == HAL_OK)
		{
			StartSectorAddress += 4;  // use StartPageAddress += 2 for half word and 8 for double word
			dataIndex++;
		}
		else
		{
			/* Error occurred while writing data in Flash memory*/
			return HAL_FLASH_GetError ();
		}
	}

	/* Lock the Flash to disable the flash control register access (recommended
	to protect the FLASH memory against possible unwanted operation) *********/
	HAL_FLASH_Lock();

	return 0;
}



void Flash_Read_Data (uint32_t startSectorAddress, uint32_t *userRxBuf, uint16_t numberOfWords)
{
	while (1)
	{
		*userRxBuf = *(uint32_t *)(startSectorAddress);;
		startSectorAddress += 4;
		userRxBuf++;
		if (!(numberOfWords--)) break;
	}
}



void testing_flash_data()
{

	char *data = "hello FLASH from ControllerTech\
	This is a test to see how many words can we work with";
	uint32_t data2[] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9};
	uint32_t Rx_Data[30];
	//char string[100];
	//int number = 123;
	//float val = 123.456;
	//float RxVal;
	Flash_Write_Data((uint32_t)WRITE_READ_FLASH_SECTOR_ELEVEN_STAR_ADDRESS , (uint32_t *)data2, 9);
	Flash_Read_Data(WRITE_READ_FLASH_SECTOR_ELEVEN_STAR_ADDRESS , Rx_Data, 10);
	int numofwords = (strlen(data)/4)+((strlen(data)%4)!=0);
	Flash_Write_Data(WRITE_READ_FLASH_SECTOR_ELEVEN_STAR_ADDRESS , (uint32_t *)data, numofwords);
	Flash_Read_Data(WRITE_READ_FLASH_SECTOR_ELEVEN_STAR_ADDRESS , Rx_Data, numofwords);
	//Convert_To_Str(Rx_Data, string);
	//Flash_Write_NUM(0x0800C100, number);
	//RxVal = Flash_Read_NUM(0x0800C100);
	////Flash_Write_NUM(0x0800D100, val);
	//RxVal = Flash_Read_NUM(0x0800D100);
}
