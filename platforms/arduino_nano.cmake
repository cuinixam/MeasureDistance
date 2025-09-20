# CMake toolchain file for Arduino Nano ATmega328P

# Set the system name and processor
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)

# Specify the cross compiler
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_ASM_COMPILER avr-gcc)
set(CMAKE_AR avr-gcc-ar)
set(CMAKE_RANLIB avr-gcc-ranlib)
set(CMAKE_OBJCOPY avr-objcopy)

# Set executable suffix to .elf for AVR targets
set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_CXX ".elf")

# MCU configuration
set(MCU atmega328p)
set(F_CPU 16000000L)

# Arduino specific definitions
add_definitions(
    -DPLATFORMIO=60118
    -DARDUINO_AVR_NANO
    -DF_CPU=${F_CPU}
    -DARDUINO_ARCH_AVR
    -DARDUINO=10808
)

# Compiler flags for C
set(CMAKE_C_FLAGS "-std=gnu11 -fno-fat-lto-objects -mmcu=${MCU} -Os -Wall -ffunction-sections -fdata-sections -flto")

# Compiler flags for C++
set(CMAKE_CXX_FLAGS "-fno-exceptions -fno-threadsafe-statics -fpermissive -std=gnu++11 -mmcu=${MCU} -Os -Wall -ffunction-sections -fdata-sections -flto")

# Assembler flags
set(CMAKE_ASM_FLAGS "-mmcu=${MCU} -x assembler-with-cpp")

# Linker flags
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${MCU} -Os -Wl,--gc-sections -flto -fuse-linker-plugin -lm")
