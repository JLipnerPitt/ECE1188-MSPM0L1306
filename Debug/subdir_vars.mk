################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
SYSCFG_SRCS += \
../empty.syscfg 

C_SRCS += \
../Motor_Simple.c \
../SysTick.c \
./ti_msp_dl_config.c \
C:/ti/mspm0_sdk_2_01_00_03/source/ti/devices/msp/m0p/startup_system_files/gcc/startup_mspm0l130x_gcc.c \
../main.c 

GEN_CMDS += \
./device_linker.lds 

GEN_FILES += \
./device_linker.lds \
./device.opt \
./ti_msp_dl_config.c 

C_DEPS += \
./Motor_Simple.d \
./SysTick.d \
./ti_msp_dl_config.d \
./startup_mspm0l130x_gcc.d \
./main.d 

GEN_OPTS += \
./device.opt 

OBJS += \
./Motor_Simple.o \
./SysTick.o \
./ti_msp_dl_config.o \
./startup_mspm0l130x_gcc.o \
./main.o 

GEN_MISC_FILES += \
./device.lds.genlibs \
./ti_msp_dl_config.h 

OBJS__QUOTED += \
"Motor_Simple.o" \
"SysTick.o" \
"ti_msp_dl_config.o" \
"startup_mspm0l130x_gcc.o" \
"main.o" 

GEN_MISC_FILES__QUOTED += \
"device.lds.genlibs" \
"ti_msp_dl_config.h" 

C_DEPS__QUOTED += \
"Motor_Simple.d" \
"SysTick.d" \
"ti_msp_dl_config.d" \
"startup_mspm0l130x_gcc.d" \
"main.d" 

GEN_FILES__QUOTED += \
"device_linker.lds" \
"device.opt" \
"ti_msp_dl_config.c" 

C_SRCS__QUOTED += \
"../Motor_Simple.c" \
"../SysTick.c" \
"./ti_msp_dl_config.c" \
"C:/ti/mspm0_sdk_2_01_00_03/source/ti/devices/msp/m0p/startup_system_files/gcc/startup_mspm0l130x_gcc.c" \
"../main.c" 

SYSCFG_SRCS__QUOTED += \
"../empty.syscfg" 


