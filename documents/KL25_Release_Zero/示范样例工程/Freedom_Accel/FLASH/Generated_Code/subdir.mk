################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/Cpu.c" \
"../Generated_Code/GPIO1.c" \
"../Generated_Code/I2C2.c" \
"../Generated_Code/LED1.c" \
"../Generated_Code/LED2.c" \
"../Generated_Code/LED3.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/GPIO1.c \
../Generated_Code/I2C2.c \
../Generated_Code/LED1.c \
../Generated_Code/LED2.c \
../Generated_Code/LED3.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/GPIO1.o \
./Generated_Code/I2C2.o \
./Generated_Code/LED1.o \
./Generated_Code/LED2.o \
./Generated_Code/LED3.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/Vectors.o \

OBJS_QUOTED += \
"./Generated_Code/Cpu.o" \
"./Generated_Code/GPIO1.o" \
"./Generated_Code/I2C2.o" \
"./Generated_Code/LED1.o" \
"./Generated_Code/LED2.o" \
"./Generated_Code/LED3.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/Vectors.o" \

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/GPIO1.d \
./Generated_Code/I2C2.d \
./Generated_Code/LED1.d \
./Generated_Code/LED2.d \
./Generated_Code/LED3.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/Vectors.d \

OBJS_OS_FORMAT += \
./Generated_Code/Cpu.o \
./Generated_Code/GPIO1.o \
./Generated_Code/I2C2.o \
./Generated_Code/LED1.o \
./Generated_Code/LED2.o \
./Generated_Code/LED3.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/Vectors.o \

C_DEPS_QUOTED += \
"./Generated_Code/Cpu.d" \
"./Generated_Code/GPIO1.d" \
"./Generated_Code/I2C2.d" \
"./Generated_Code/LED1.d" \
"./Generated_Code/LED2.d" \
"./Generated_Code/LED3.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/Vectors.d" \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" -nostdinc -I"$(ProjDirPath)/Project_Headers" -I"$(ProjDirPath)/Project_Settings/Startup_Code" -I"$(MCUToolsBaseDirEnv)/ARM_GCC_Support/ewl/EWL_C/include" -I"$(MCUToolsBaseDirEnv)/ARM_GCC_Support/ewl/EWL_Runtime/include" -I"$(ProjDirPath)/Generated_Code" -I"$(ProjDirPath)/Sources" -I"$(MCUToolsBaseDirEnv)/ProcessorExpert/lib/Kinetis/iofiles" -I"$(MCUToolsBaseDirEnv)/ProcessorExpert/lib/Kinetis/pdd/inc" -O0 -ffunction-sections -fdata-sections -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"$@"
	@echo 'Finished building: $<'
	@echo ' '


