################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../SEGGER_RTT/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

C_SRCS += \
../SEGGER_RTT/SEGGER/SEGGER_RTT.c \
/Users/apple/Downloads/RTT-master/Syscalls/SEGGER_RTT_Syscalls_GCC.c \
../SEGGER_RTT/SEGGER/SEGGER_RTT_printf.c \
../SEGGER_RTT/SEGGER/SEGGER_SYSVIEW.c 

C_DEPS += \
./SEGGER_RTT/SEGGER/SEGGER_RTT.d \
./SEGGER_RTT/SEGGER/SEGGER_RTT_Syscalls_GCC.d \
./SEGGER_RTT/SEGGER/SEGGER_RTT_printf.d \
./SEGGER_RTT/SEGGER/SEGGER_SYSVIEW.d 

OBJS += \
./SEGGER_RTT/SEGGER/SEGGER_RTT.o \
./SEGGER_RTT/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./SEGGER_RTT/SEGGER/SEGGER_RTT_Syscalls_GCC.o \
./SEGGER_RTT/SEGGER/SEGGER_RTT_printf.o \
./SEGGER_RTT/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./SEGGER_RTT/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 


# Each subdirectory must supply rules for building sources it contributes
SEGGER_RTT/SEGGER/%.o SEGGER_RTT/SEGGER/%.su SEGGER_RTT/SEGGER/%.cyclo: ../SEGGER_RTT/SEGGER/%.c SEGGER_RTT/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../SEGGER_RTT/Config -I"/Users/apple/STM32CubeIDE/workspace_1.18.1/Embedded_Practise/SEGGER_RTT/SEGGER" -I"/Users/apple/STM32CubeIDE/workspace_1.18.1/Embedded_Practise/SEGGER_RTT/SEGGER_OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SEGGER_RTT/SEGGER/%.o: ../SEGGER_RTT/SEGGER/%.S SEGGER_RTT/SEGGER/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
SEGGER_RTT/SEGGER/SEGGER_RTT_Syscalls_GCC.o: /Users/apple/Downloads/RTT-master/Syscalls/SEGGER_RTT_Syscalls_GCC.c SEGGER_RTT/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../SEGGER_RTT/Config -I"/Users/apple/STM32CubeIDE/workspace_1.18.1/Embedded_Practise/SEGGER_RTT/SEGGER" -I"/Users/apple/STM32CubeIDE/workspace_1.18.1/Embedded_Practise/SEGGER_RTT/SEGGER_OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SEGGER_RTT-2f-SEGGER

clean-SEGGER_RTT-2f-SEGGER:
	-$(RM) ./SEGGER_RTT/SEGGER/SEGGER_RTT.cyclo ./SEGGER_RTT/SEGGER/SEGGER_RTT.d ./SEGGER_RTT/SEGGER/SEGGER_RTT.o ./SEGGER_RTT/SEGGER/SEGGER_RTT.su ./SEGGER_RTT/SEGGER/SEGGER_RTT_ASM_ARMv7M.d ./SEGGER_RTT/SEGGER/SEGGER_RTT_ASM_ARMv7M.o ./SEGGER_RTT/SEGGER/SEGGER_RTT_Syscalls_GCC.cyclo ./SEGGER_RTT/SEGGER/SEGGER_RTT_Syscalls_GCC.d ./SEGGER_RTT/SEGGER/SEGGER_RTT_Syscalls_GCC.o ./SEGGER_RTT/SEGGER/SEGGER_RTT_Syscalls_GCC.su ./SEGGER_RTT/SEGGER/SEGGER_RTT_printf.cyclo ./SEGGER_RTT/SEGGER/SEGGER_RTT_printf.d ./SEGGER_RTT/SEGGER/SEGGER_RTT_printf.o ./SEGGER_RTT/SEGGER/SEGGER_RTT_printf.su ./SEGGER_RTT/SEGGER/SEGGER_SYSVIEW.cyclo ./SEGGER_RTT/SEGGER/SEGGER_SYSVIEW.d ./SEGGER_RTT/SEGGER/SEGGER_SYSVIEW.o ./SEGGER_RTT/SEGGER/SEGGER_SYSVIEW.su

.PHONY: clean-SEGGER_RTT-2f-SEGGER

