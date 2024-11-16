cmake_minimum_required(VERSION 3.10)
project(CPlusApplication)

set(CMAKE_CXX_STANDARD 17)

# Find the CppRestSDK package
find_package(cpprest REQUIRED)

# Find the OpenCV package
find_package(OpenCV REQUIRED)

include_directories(${cpprest_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS} include)

add_executable(CPlusApplication 
    src/main.cpp 
    src/api_controller.cpp 
    src/camera.cpp 
    src/utils.cpp
    src/services/capture_service.cpp
)

target_link_libraries(CPlusApplication ${cpprest_LIBRARIES} ${OpenCV_LIBS})
