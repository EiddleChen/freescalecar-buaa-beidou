################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/MMA8451.c" \
"../Sources/ProcessorExpert.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/MMA8451.c \
../Sources/ProcessorExpert.c \

OBJS += \
./Sources/Events.o \
./Sources/MMA8451.o \
./Sources/ProcessorExpert.o \

OBJS_QUOTED += \
"./Sources/Events.o" \
"./Sources/MMA8451.o" \
"./Sources/ProcessorExpert.o" \

C_DEPS += \
./Sources/Events.d \
./Sources/MMA8451.d \
./Sources/ProcessorExpert.d \

OBJS_OS_FORMAT += \
./Sources/Events.o \
./Sources/MMA8451.o \
./Sources/ProcessorExpert.o \

C_DEPS_QUOTED += \
"./Sources/Events.d" \
"./Sources/MMA8451.d" \
"./Sources/ProcessorExpert.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" -nostdinc -I"$(ProjDirPath)/Project_Headers" -I"$(ProjDirPath)/Project_Settings/Startup_Code" -I"$(MCUToolsBaseDirEnv)/ARM_GCC_Support/ewl/EWL_C/include" -I"$(MCUToolsBaseDirEnv)/ARM_GCC_Support/ewl/EWL_Runtime/include" -I"$(ProjDirPath)/Generated_Code" -I"$(ProjDirPath)/Sources" -I"$(MCUToolsBaseDirEnv)/ProcessorExpert/lib/Kinetis/iofiles" -I"$(MCUToolsBaseDirEnv)/ProcessorExpert/lib/Kinetis/pdd/inc" -O0 -ffunction-sections -fdata-sections -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"$@"
	@echo 'Finished building: $<'
	@echo ' '


