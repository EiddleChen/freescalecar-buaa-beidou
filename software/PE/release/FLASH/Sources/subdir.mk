################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/CCD.c" \
"../Sources/Correction.c" \
"../Sources/Events.c" \
"../Sources/MMA8451.c" \
"../Sources/Motor.c" \
"../Sources/Processing.c" \
"../Sources/ProcessorExpert.c" \
"../Sources/Servo.c" \
"../Sources/Stand_Up.c" \
"../Sources/sa_mtb.c" \

C_SRCS += \
../Sources/CCD.c \
../Sources/Correction.c \
../Sources/Events.c \
../Sources/MMA8451.c \
../Sources/Motor.c \
../Sources/Processing.c \
../Sources/ProcessorExpert.c \
../Sources/Servo.c \
../Sources/Stand_Up.c \
../Sources/sa_mtb.c \

OBJS += \
./Sources/CCD_c.obj \
./Sources/Correction_c.obj \
./Sources/Events_c.obj \
./Sources/MMA8451_c.obj \
./Sources/Motor_c.obj \
./Sources/Processing_c.obj \
./Sources/ProcessorExpert_c.obj \
./Sources/Servo_c.obj \
./Sources/Stand_Up_c.obj \
./Sources/sa_mtb_c.obj \

C_DEPS += \
./Sources/CCD.d \
./Sources/Correction.d \
./Sources/Events.d \
./Sources/MMA8451.d \
./Sources/Motor.d \
./Sources/Processing.d \
./Sources/ProcessorExpert.d \
./Sources/Servo.d \
./Sources/Stand_Up.d \
./Sources/sa_mtb.d \

OBJS_QUOTED += \
"./Sources/CCD_c.obj" \
"./Sources/Correction_c.obj" \
"./Sources/Events_c.obj" \
"./Sources/MMA8451_c.obj" \
"./Sources/Motor_c.obj" \
"./Sources/Processing_c.obj" \
"./Sources/ProcessorExpert_c.obj" \
"./Sources/Servo_c.obj" \
"./Sources/Stand_Up_c.obj" \
"./Sources/sa_mtb_c.obj" \

C_DEPS_QUOTED += \
"./Sources/CCD.d" \
"./Sources/Correction.d" \
"./Sources/Events.d" \
"./Sources/MMA8451.d" \
"./Sources/Motor.d" \
"./Sources/Processing.d" \
"./Sources/ProcessorExpert.d" \
"./Sources/Servo.d" \
"./Sources/Stand_Up.d" \
"./Sources/sa_mtb.d" \

OBJS_OS_FORMAT += \
./Sources/CCD_c.obj \
./Sources/Correction_c.obj \
./Sources/Events_c.obj \
./Sources/MMA8451_c.obj \
./Sources/Motor_c.obj \
./Sources/Processing_c.obj \
./Sources/ProcessorExpert_c.obj \
./Sources/Servo_c.obj \
./Sources/Stand_Up_c.obj \
./Sources/sa_mtb_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/CCD_c.obj: ../Sources/CCD.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/CCD.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/CCD_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Correction_c.obj: ../Sources/Correction.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Correction.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Correction_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Events.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Events_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/MMA8451_c.obj: ../Sources/MMA8451.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/MMA8451.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/MMA8451_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Motor_c.obj: ../Sources/Motor.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Motor.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Motor_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Processing_c.obj: ../Sources/Processing.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Processing.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Processing_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/ProcessorExpert_c.obj: ../Sources/ProcessorExpert.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/ProcessorExpert.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/ProcessorExpert_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Servo_c.obj: ../Sources/Servo.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Servo.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Servo_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Stand_Up_c.obj: ../Sources/Stand_Up.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Stand_Up.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Stand_Up_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb_c.obj: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/sa_mtb_c.obj"
	@echo 'Finished building: $<'
	@echo ' '


