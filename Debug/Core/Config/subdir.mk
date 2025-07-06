################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Config/SEGGER_SYSVIEW_Config_FreeRTOS.c 

C_DEPS += \
./Core/Config/SEGGER_SYSVIEW_Config_FreeRTOS.d 

OBJS += \
./Core/Config/SEGGER_SYSVIEW_Config_FreeRTOS.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Config/%.o Core/Config/%.su Core/Config/%.cyclo: ../Core/Config/%.c Core/Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../SEGGER_RTT/Config -I../SEGGER_RTT/SEGGER -I../SEGGER_RTT/SEGGER_OS -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/org/Source/include -I../Middlewares/Third_Party/FreeRTOS/org/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Config

clean-Core-2f-Config:
	-$(RM) ./Core/Config/SEGGER_SYSVIEW_Config_FreeRTOS.cyclo ./Core/Config/SEGGER_SYSVIEW_Config_FreeRTOS.d ./Core/Config/SEGGER_SYSVIEW_Config_FreeRTOS.o ./Core/Config/SEGGER_SYSVIEW_Config_FreeRTOS.su

.PHONY: clean-Core-2f-Config

