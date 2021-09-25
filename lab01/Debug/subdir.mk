################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Playlist.cpp \
../PlaylistTest.cpp \
../Song.cpp \
../SongTest.cpp \
../main.cpp 

OBJS += \
./Playlist.o \
./PlaylistTest.o \
./Song.o \
./SongTest.o \
./main.o 

CPP_DEPS += \
./Playlist.d \
./PlaylistTest.d \
./Song.d \
./SongTest.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


