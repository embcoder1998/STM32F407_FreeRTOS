################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SEGGER_RTT/Config/SEGGER_SYSVIEW_Config_FreeRTOS.c 

C_DEPS += \
./SEGGER_RTT/Config/SEGGER_SYSVIEW_Config_FreeRTOS.d 

OBJS += \
./SEGGER_RTT/Config/SEGGER_SYSVIEW_Config_FreeRTOS.o 


# Each subdirectory must supply rules for building sources it contributes
SEGGER_RTT/Config/%.o SEGGER_RTT/Config/%.su SEGGER_RTT/Config/%.cyclo: ../SEGGER_RTT/Config/%.c SEGGER_RTT/Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../SEGGER_RTT/Config -I"/Users/apple/STM32CubeIDE/workspace_1.18.1/Embedded_Practise/SEGGER_RTT/SEGGER" -I"/Users/apple/STM32CubeIDE/workspace_1.18.1/Embedded_Practise/SEGGER_RTT/SEGGER_OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SEGGER_RTT-2f-Config

clean-SEGGER_RTT-2f-Config:
	-$(RM) ./SEGGER_RTT/Config/SEGGER_SYSVIEW_Config_FreeRTOS.cyclo ./SEGGER_RTT/Config/SEGGER_SYSVIEW_Config_FreeRTOS.d ./SEGGER_RTT/Config/SEGGER_SYSVIEW_Config_FreeRTOS.o ./SEGGER_RTT/Config/SEGGER_SYSVIEW_Config_FreeRTOS.su

.PHONY: clean-SEGGER_RTT-2f-Config

