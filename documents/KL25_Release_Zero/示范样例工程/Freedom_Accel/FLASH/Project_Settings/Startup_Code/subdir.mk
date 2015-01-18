################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Project_Settings/Startup_Code/__arm_end.c" \
"../Project_Settings/Startup_Code/__arm_start.c" \

C_SRCS += \
../Project_Settings/Startup_Code/__arm_end.c \
../Project_Settings/Startup_Code/__arm_start.c \

OBJS += \
./Project_Settings/Startup_Code/__arm_end.o \
./Project_Settings/Startup_Code/__arm_start.o \

OBJS_QUOTED += \
"./Project_Settings/Startup_Code/__arm_end.o" \
"./Project_Settings/Startup_Code/__arm_start.o" \

C_DEPS += \
./Project_Settings/Startup_Code/__arm_end.d \
./Project_Settings/Startup_Code/__arm_start.d \

OBJS_OS_FORMAT += \
./Project_Settings/Startup_Code/__arm_end.o \
./Project_Settings/Startup_Code/__arm_start.o \

C_DEPS_QUOTED += \
"./Project_Settings/Startup_Code/__arm_end.d" \
"./Project_Settings/Startup_Code/__arm_start.d" \


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/Startup_Code/%.o: ../Project_Settings/Startup_Code/%.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" -nostdinc -I"$(ProjDirPath)/Project_Headers" -I"$(ProjDirPath)/Project_Settings/Startup_Code" -I"$(MCUToolsBaseDirEnv)/ARM_GCC_Support/ewl/EWL_C/include" -I"$(MCUToolsBaseDirEnv)/ARM_GCC_Support/ewl/EWL_Runtime/include" -I"$(ProjDirPath)/Generated_Code" -I"$(ProjDirPath)/Sources" -I"$(MCUToolsBaseDirEnv)/ProcessorExpert/lib/Kinetis/iofiles" -I"$(MCUToolsBaseDirEnv)/ProcessorExpert/lib/Kinetis/pdd/inc" -O0 -ffunction-sections -fdata-sections -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"$@"
	@echo 'Finished building: $<'
	@echo ' '


