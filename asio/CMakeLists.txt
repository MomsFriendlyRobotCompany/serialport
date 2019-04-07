
cmake_minimum_required(VERSION 3.10)
project(serialport)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "-------------------------------------")
message(STATUS "  Project: ${PROJECT_NAME}")
message(STATUS "  C++ ${CMAKE_CXX_STANDARD}")
message(STATUS "-------------------------------------")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_library(serialio SerialPort.cpp)
add_executable(serial-test main.cpp)

find_package(Boost REQUIRED system)
find_package(Threads REQUIRED)

message(STATUS ">> ${Boost_INCLUDE_DIRS}")

target_link_libraries(serial-test ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} serialio)
