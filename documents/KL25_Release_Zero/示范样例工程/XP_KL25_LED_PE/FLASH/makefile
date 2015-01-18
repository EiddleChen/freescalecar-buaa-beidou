################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 33
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(GNU_Make_Install_DirEnv)/rm -rf"

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Sources/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Generated_Code/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
XP_KL25_LED_PE.elf \

EXECUTABLES_QUOTED += \
"XP_KL25_LED_PE.elf" \

EXECUTABLES_OS_FORMAT += \
XP_KL25_LED_PE.elf \

SECONDARY_FLASH += \
XP_KL25_LED_PE.hex \

SECONDARY_FLASH_QUOTED += \
"XP_KL25_LED_PE.hex" \

SECONDARY_FLASH_OS_FORMAT += \
XP_KL25_LED_PE.hex \


# All Target
all: XP_KL25_LED_PE.elf secondary-outputs

# Tool invocations
XP_KL25_LED_PE.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #34 $@'
	@echo 'Invoking: ARM Ltd Windows GCC C Linker'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" $(OBJS_QUOTED) $(USER_OBJS_QUOTED) $(LIBS_QUOTED) -T"$(ProjDirPath)/Project_Settings/Linker_Files/ProcessorExpert.ld" -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -L"$(MCUToolsBaseDirEnv)/ARM_GCC_Support/ewl/lib/armv6-m" -Xlinker --undefined=__pformatter_ -Xlinker --defsym=__pformatter=__pformatter_ -Xlinker --start-group -Xlinker -lc -lm -lgcc -luart -lrt -Xlinker --end-group -Wl,-Map,XP_KL25_LED_PE.map -n -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"XP_KL25_LED_PE.elf"
	@echo 'Finished building target: $@'
	@echo ' '

XP_KL25_LED_PE.hex: XP_KL25_LED_PE.elf
	@echo 'Executing target #35 $@'
	@echo 'Invoking: ARM Ltd Windows GNU Create Flash Image'
	"$(ARMSourceryDirEnv)/arm-none-eabi-objcopy"  -O srec XP_KL25_LED_PE.elf "XP_KL25_LED_PE.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(S_DEPS_QUOTED) $(SECONDARY_FLASH_QUOTED) "./*/*.o" "./*/*/*.o"  $(S_UPPER_DEPS_QUOTED) $(ASM_DEPS_QUOTED) $(ASM_UPPER_DEPS_QUOTED) $(SX_DEPS_QUOTED) $(EXECUTABLES_QUOTED) "./*/*.d" "./*/*/*.d"  $(ProjDirPath)/FLASH/XP_KL25_LED_PE.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
