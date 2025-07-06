# NB! gnu arm toolchain must already be in system path.
#
# Please select your processor-derivative below, the available choices are:
#  STM32F10X_LD     STM32F10X_LD: STM32 Low density devices
#  STM32F10X_LD_VL  STM32F10X_LD_VL: STM32 Low density Value Line devices
#  STM32F10X_MD     STM32F10X_MD: STM32 Medium density devices
#  STM32F10X_MD_VL  STM32F10X_MD_VL: STM32 Medium density Value Line devices
#  STM32F10X_HD     STM32F10X_HD: STM32 High density devices
#  STM32F10X_HD_VL  STM32F10X_HD_VL: STM32 High density value line devices
#  STM32F10X_XL     STM32F10X_XL: STM32 XL-density devices
#  STM32F10X_CL     STM32F10X_CL: STM32 Connectivity line devices
#
# - Low-density devices are STM32F101xx, STM32F102xx and STM32F103xx microcontrollers
#   where the Flash memory density ranges between 16 and 32 Kbytes.
# - Low-density value line devices are STM32F100xx microcontrollers where the Flash
#   memory density ranges between 16 and 32 Kbytes.
# - Medium-density devices are STM32F101xx, STM32F102xx and STM32F103xx microcontrollers
#   where the Flash memory density ranges between 64 and 128 Kbytes.
# - Medium-density value line devices are STM32F100xx microcontrollers where the 
#   Flash memory density ranges between 64 and 128 Kbytes.   
# - High-density devices are STM32F101xx and STM32F103xx microcontrollers where
#   the Flash memory density ranges between 256 and 512 Kbytes.
# - High-density value line devices are STM32F100xx microcontrollers where the 
#   Flash memory density ranges between 256 and 512 Kbytes.   
# - XL-density devices are STM32F101xx and STM32F103xx microcontrollers where
#   the Flash memory density ranges between 512 and 1024 Kbytes.
# - Connectivity line devices are STM32F105xx and STM32F107xx microcontrollers.


# Scons -c or --clean - this command use for the the clean build file 
# this instruction follow the programme builder 
# 1 . Program('hello_world.c')

# you can give the target name 
#Program('excutable' , 'hello_world.c')
#Decider('content-timestamp')

# note this will try to understand later 
#def decide_if_changed(dependency, target, prev_ni, repo_node=None):
# if dependency.get_timestamp() != prev_ni.timestamp:
#    dep = str(dependency)
#    tgt = str(target)
#    if specific_part_of_file_has_changed(dep, tgt):
#        return True
# return False
#Decider(decide_if_changed)


# 2 . compile the multiple file  with the particular target name 
#Program('target_name' , ['file1.c' , 'File2.c' ,])

# 3. compile with different target name with multiple file 
# Program('target_nameone' ,'file name')
# Program('target_nametwo' ,'file name')

# 4.  you can write the some differnet way 
# common_sourc  =['file1.c' , 'file2.c']
#Program('target_name' , common_source + ['file_name ])

# 5. now same or multiple file we can compile the different way by using the split function 
# common_sourc = split('file.c file2.c file3.c')
#Program('target_name' , common_sourc)

# 6. compile the multiple file the different way 
#src_files = Split("""main.c file1.c file2.c""")
#Program('program', src_files)

# 7. compile the code with keyword argument
#src_files = Split('main.c file1.c file2.c')
#Program(source=src_files, target='program')
#src_files = Split('main.c file1.c file2.c')
#Program(target='program', source=src_files)

# this Instruction follow the object builder
#Object('hello_world.c')



# 1. Building the my own libraries
# Library('foo', ['f1.c', 'f2.c', 'f3.c'])
# 2. we can build our souce code with object file also
# Library('foo', ['f1.c', 'f2.o', 'f3.c', 'f4.o'])


# 1. building our own shared libraries
# SharedLibrary('foo', ['f1.c', 'f2.c', 'f3.c'])

# 1. building our own staic libraries
# StaticLibrary('foo', ['f1.c', 'f2.c', 'f3.c'])


# 1. Linking with library your source file 
# Library('foo', ['f1.c', 'f2.c', 'f3.c'])
# Program('prog.c', LIBS=['foo', 'bar'], LIBPATH='.')


# 1. Finding Libraries in Sconstruct variable 
#Program('prog.c', LIBS = 'm', LIBPATH = ['/usr/lib', '/usr/local/lib'])

#LIBPATH = '/usr/lib:/usr/local/lib'



# builder method Return Lists of Target Nodes
# 1. if you want to create diffrent object file and letter we want to combined 
#Object('hello.c', CCFLAGS='-DHELLO')
#Object('goodbye.c', CCFLAGS='-DGOODBYE')



#Object('hello.c', CCFLAGS='-DHELLO')
#Object('goodbye.c', CCFLAGS='-DGOODBYE')
#Program(['hello.o', 'goodbye.o'])

#hello_list = Object('hello.c', CCFLAGS='-DHELLO')
#goodbye_list = Object('goodbye.c', CCFLAGS='-DGOODBYE')
#Program(hello_list + goodbye_list)


# those are building the file and that file dont have any changes and this situation if you dont want to build then give 
# the command Scons -Q


# we have some flag you can get the set if you dont want to type each and every time 
# suppose i am giving the command Scons -Q
# if i want to set that flag $setenv SCONSFLAGS "-Q"
#import os
#num_cpu = int(os.environ.get('NUM_CPU', 2))
#SetOption('num_jobs', num_cpu)
#print("running with -j %s" % GetOption('num_jobs'))

# for window command shell you can set the flag 
# C:// set SCONSFLAGS "-Q"



#ENVIORMENT

PROCESSOR_DERIVATIVE = 'STM32G071RBTX'
import os
env = Environment(tools = ['gcc', 'gnulink'], ENV = os.environ)

env['AR'] = 'arm-none-eabi-ar'
env['AS'] = 'arm-none-eabi-as'
env['CC'] = 'arm-none-eabi-gcc'
env['CXX'] = 'arm-none-eabi-g++'
env['LINK'] = 'arm-none-eabi-g++'                # predefined is 'arm-none-eabi-gcc'
env['RANLIB'] = 'arm-none-eabi-ranlib'
env['OBJCOPY'] = 'arm-none-eabi-objcopy'
env['PROGSUFFIX'] = '.elf'

# C-defines
env.Append( CPPDEFINES = [
    PROCESSOR_DERIVATIVE,
    'USE_HAL_DRIVER',
    'STM32G071xx',
    'DEBUG',
])

# Include locations
env.Append( CPPPATH = [
    '#Core/Inc',
    '#Drivers/CMSIS/Include/',
    '#Drivers/CMSIS/Device/ST/STM32G0xx/Include',
    '#Drivers/STM32G0xx_HAL_Driver/Inc',
    '#Drivers/STM32G0xx_HAL_Driver/Inc/Legacy',
])

# Compiler flags
env.Append( CCFLAGS = [
    '-mcpu=cortex-m0plus',                                     # assign the m0 arm cortex
    '-mthumb',                                                 # follow the thumb instruction more performace to use "mram"
    '-O0', # Do not optimize-code (Level 0  -O2)               # optimization leve 0 t o-O2
    '-g',                                                      # Generate debug-information
    '-ffunction-sections',                                     # Remove un-used functions
    '-fdata-sections',                                         # Remove un-used data
    '-std=gnu11',                                              # up to gcc 11 standard follow
    '-fmessage-length=0',                                      # formate the error message 
    '-mthumb-interwork',                                       # support to calling between ARM and Thumb Instruction
    '-mlittle-endian',                                         # which endian its follow
    '-fno-exceptions',                                         # supported the exception handling
    '--specs=nano.specs',                                      # defines the system include path and library parameters to use newlib-nano
    '-Wall'                                                    # raised the warnning message
])


# Linker flags
env.Append( LINKFLAGS = [
    '-mthumb',                                                 # follow the thumb instruction more performace to use "mram"
    '-mcpu=cortex-m0plus',                                  
    '-specs=nosys.specs',                                      # defines the system include path and library parameters to use newlib-nano
    '-static',                                                 # flag forces the linker to accept only static libraries and not any shared libraries.
    '-Wl,-cref,-u,Reset_Handler',                              #
    '-Wl,-Map=main.map',
    '-Wl,--gc-sections',
    '-Wl,--defsym=malloc_getpagesize_P=0x80',
    '-Wl,--start-group',
    '-lc',
    '-lm',
    '-Wl,--end-group',
    '-specs=nano.specs',
    '-TSTM32G071RBTX_FLASH.ld',
]) 

startup_file_name = 'startup_' + PROCESSOR_DERIVATIVE.lower() + '.s'
# Source locations
source = [
        'Core/Src/main.c',
        'Core/Src/stm32g0xx_hal_msp.c',
        'Core/Src/stm32g0xx_it.c',
        'Core/Src/syscalls.c',
        'Core/Src/sysmem.c',
        'Core/Src/system_stm32g0xx.c',
        'Core/Startup/' + startup_file_name,
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_cortex.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_dma.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_dma_ex.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_exti.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_flash.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_flash_ex.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_gpio.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_pwr.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_pwr_ex.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_rcc.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_rcc_ex.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_tim.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_tim_ex.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_dma.c',
        'Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_rcc.c',
        
]

target = '#Debug/'

# build everything
prg = env.Program( target = target + 'Scons_Nucleo_GSeries_Demo_LedBlinkin', source = source )




# Note - file should be save like as --- SConstruct