cmake_minimum_required(VERSION 3.27)

# Project name
project(Audio2Array)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(Audio2Array main.cpp MP3Reader.cpp WAVReader.cpp ReaderInterface.cpp AudioConverter.cpp SoundCalculator.cpp)

# Include directories
target_include_directories(Audio2Array PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link libraries
find_package(SndFile REQUIRED)
find_package(mpg123 REQUIRED)
find_package(fftw3 REQUIRED)

target_link_libraries(Audio2Array PRIVATE SndFile::sndfile)