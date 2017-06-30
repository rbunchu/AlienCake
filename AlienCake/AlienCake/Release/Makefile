################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../include \
../src


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../sketch.cpp \
../src/LedBlinker.cpp \
../src/LengthSensor.cpp \
../src/MotorDriver.cpp \
../src/MotorizedPole.cpp \
../src/Mp3Player.cpp \
../src/ReedSwitch.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
sketch.o \
src/LedBlinker.o \
src/LengthSensor.o \
src/MotorDriver.o \
src/MotorizedPole.o \
src/Mp3Player.o \
src/ReedSwitch.o

OBJS_AS_ARGS +=  \
sketch.o \
src/LedBlinker.o \
src/LengthSensor.o \
src/MotorDriver.o \
src/MotorizedPole.o \
src/Mp3Player.o \
src/ReedSwitch.o

C_DEPS +=  \
sketch.d \
src/LedBlinker.d \
src/LengthSensor.d \
src/MotorDriver.d \
src/MotorizedPole.d \
src/Mp3Player.d \
src/ReedSwitch.d

C_DEPS_AS_ARGS +=  \
sketch.d \
src/LedBlinker.d \
src/LengthSensor.d \
src/MotorDriver.d \
src/MotorizedPole.d \
src/Mp3Player.d \
src/ReedSwitch.d

OUTPUT_FILE_PATH +=AlienCake.elf

OUTPUT_FILE_PATH_AS_ARGS +=AlienCake.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+=  \
C:/Users/Bunchu/Documents/Atmel\ Studio/7.0/AlienCake/AlienCake/ArduinoCore/Release/libArduinoCore.a

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler















./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)F:\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DNDEBUG -DF_CPU=16000000L -DARDUINO=10801 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x0043 -DUSB_MANUFACTURER="\"Arduino LLC\""  -I"F:\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"..\\..\ArduinoCore\include\core" -I"..\\..\ArduinoCore\include\variants\standard" -I"..\\include" -I"../../ArduinoCore/include/libraries/DFPlayerMiniMp3/include" -I"../../ArduinoCore/include/libraries/SoftwareSerial/src" -I"../../ArduinoCore/include/libraries/AccelStepper/include"  -Os -fno-threadsafe-statics -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -w -mmcu=atmega328p -B "F:\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega328p" -c -std=gnu++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/%.o: ../src/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)F:\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DNDEBUG -DF_CPU=16000000L -DARDUINO=10801 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x0043 -DUSB_MANUFACTURER="\"Arduino LLC\""  -I"F:\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include" -I"..\\..\ArduinoCore\include\core" -I"..\\..\ArduinoCore\include\variants\standard" -I"..\\include" -I"../../ArduinoCore/include/libraries/DFPlayerMiniMp3/include" -I"../../ArduinoCore/include/libraries/SoftwareSerial/src" -I"../../ArduinoCore/include/libraries/AccelStepper/include"  -Os -fno-threadsafe-statics -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -w -mmcu=atmega328p -B "F:\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega328p" -c -std=gnu++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 5.4.0
	$(QUOTE)F:\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="AlienCake.map" -Wl,--start-group -Wl,-lm -Wl,-lArduinoCore  -Wl,--end-group -Wl,-L"C:\Users\Bunchu\Documents\Atmel Studio\7.0\AlienCake\AlienCake\ArduinoCore\Release"  -Wl,--gc-sections -mmcu=atmega328p -B "F:\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega328p" -Os  
	@echo Finished building target: $@
	"F:\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "AlienCake.elf" "AlienCake.hex"
	"F:\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "AlienCake.elf" "AlienCake.eep" || exit 0
	"F:\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "AlienCake.elf" > "AlienCake.lss"
	"F:\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "AlienCake.elf" "AlienCake.srec"
	"F:\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "AlienCake.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "AlienCake.elf" "AlienCake.a" "AlienCake.hex" "AlienCake.lss" "AlienCake.eep" "AlienCake.map" "AlienCake.srec" "AlienCake.usersignatures"
	