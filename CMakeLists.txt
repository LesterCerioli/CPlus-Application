cmake_minimum_required(VERSION 3.10)
project(CapturePhoto)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Set the C and C++ compilers
set(CMAKE_C_COMPILER "cl.exe")
set(CMAKE_CXX_COMPILER "cl.exe")

# Add include directories
include_directories(include)

# Add source files
set(SOURCES src/main.cpp src/camera.cpp src/utils.cpp)

# Find OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(CapturePhoto ${SOURCES})

# Link OpenCV libraries
target_link_libraries(CapturePhoto ${OpenCV_LIBS})
