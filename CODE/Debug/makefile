################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./tm4c123gh6pm_startup_ccs.obj" \
"./HAL/DC_motor/DC_motor.obj" \
"./HAL/LCD_Driver/LCD_Driver.obj" \
"./HAL/Sensors/Sensor.obj" \
"./HAL/ultraSonic/ultraSonic.obj" \
"./MCAL/Tiva_ADC/ADC.obj" \
"./MCAL/Tiva_DIO/Tiva_DIO.obj" \
"./MCAL/Tiva_GPTM_Timers/Tiva_GPTM_Timers.obj" \
"./MCAL/systick/systick.obj" \
"./scheduler/scheduler.obj" \
"../tm4c123gh6pm.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include HAL/DC_motor/subdir_vars.mk
-include HAL/LCD_Driver/subdir_vars.mk
-include HAL/Sensors/subdir_vars.mk
-include HAL/ultraSonic/subdir_vars.mk
-include MCAL/Tiva_ADC/subdir_vars.mk
-include MCAL/Tiva_DIO/subdir_vars.mk
-include MCAL/Tiva_GPTM_Timers/subdir_vars.mk
-include MCAL/systick/subdir_vars.mk
-include scheduler/subdir_vars.mk
-include subdir_rules.mk
-include HAL/DC_motor/subdir_rules.mk
-include HAL/LCD_Driver/subdir_rules.mk
-include HAL/Sensors/subdir_rules.mk
-include HAL/ultraSonic/subdir_rules.mk
-include MCAL/Tiva_ADC/subdir_rules.mk
-include MCAL/Tiva_DIO/subdir_rules.mk
-include MCAL/Tiva_GPTM_Timers/subdir_rules.mk
-include MCAL/systick/subdir_rules.mk
-include scheduler/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Autonomous_Car_RTOS.out \

EXE_OUTPUTS__QUOTED += \
"Autonomous_Car_RTOS.out" \

BIN_OUTPUTS += \
Autonomous_Car_RTOS.hex \

BIN_OUTPUTS__QUOTED += \
"Autonomous_Car_RTOS.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "Autonomous_Car_RTOS.out"

# Tool invocations
Autonomous_Car_RTOS.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"Autonomous_Car_RTOS.map" --heap_size=0 --stack_size=512 -i"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/lib" -i"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="Autonomous_Car_RTOS_linkInfo.xml" --rom_model -o "Autonomous_Car_RTOS.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

Autonomous_Car_RTOS.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armhex"  -o "Autonomous_Car_RTOS.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "tm4c123gh6pm_startup_ccs.obj" "HAL\DC_motor\DC_motor.obj" "HAL\LCD_Driver\LCD_Driver.obj" "HAL\Sensors\Sensor.obj" "HAL\ultraSonic\ultraSonic.obj" "MCAL\Tiva_ADC\ADC.obj" "MCAL\Tiva_DIO\Tiva_DIO.obj" "MCAL\Tiva_GPTM_Timers\Tiva_GPTM_Timers.obj" "MCAL\systick\systick.obj" "scheduler\scheduler.obj" 
	-$(RM) "main.d" "tm4c123gh6pm_startup_ccs.d" "HAL\DC_motor\DC_motor.d" "HAL\LCD_Driver\LCD_Driver.d" "HAL\Sensors\Sensor.d" "HAL\ultraSonic\ultraSonic.d" "MCAL\Tiva_ADC\ADC.d" "MCAL\Tiva_DIO\Tiva_DIO.d" "MCAL\Tiva_GPTM_Timers\Tiva_GPTM_Timers.d" "MCAL\systick\systick.d" "scheduler\scheduler.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

