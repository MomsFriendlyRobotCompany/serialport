
cmake_minimum_required(VERSION 3.10)
project(serialport)

set(CMAKE_CXX_STANDARD 17)
add_library(serialio SerialPort.cpp)
add_executable(serial-test main.cpp)

find_package(Boost REQUIRED system)
find_package(Threads REQUIRED)
target_link_libraries(serial-test ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} serialio)
