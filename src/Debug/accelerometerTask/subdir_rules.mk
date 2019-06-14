################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
accelerometerTask/accelerometerTask.obj: ../accelerometerTask/accelerometerTask.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.12.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -O2 --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.12.0.STS/lib" --include_path="/Users/Katrine/ti/tirex-content/TivaWare_C_Series-2.1.3.156" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.12.0.STS/include" --include_path="/Users/Katrine/Dropbox/ROBTEK/6. semester/Bachelor/Eksempelkode" --include_path="/Users/Katrine/Dropbox/ROBTEK/6. semester/Bachelor/Eksempelkode/Bachelor" --include_path="/Users/Katrine/ti/tirex-content/TivaWare_C_Series-2.1.3.156/examples/boards/ek-tm4c123gxl" --include_path="/Users/Katrine/ti/tirex-content/TivaWare_C_Series-2.1.3.156/third_party" --include_path="/Users/Katrine/ti/tirex-content/TivaWare_C_Series-2.1.3.156/third_party/FreeRTOS/Source/include" --include_path="/Users/Katrine/ti/tirex-content/TivaWare_C_Series-2.1.3.156/third_party/FreeRTOS" --include_path="/Users/Katrine/ti/tirex-content/TivaWare_C_Series-2.1.3.156/third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F" --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --ual --preproc_with_compile --preproc_dependency="accelerometerTask/accelerometerTask.d" --obj_directory="accelerometerTask" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


