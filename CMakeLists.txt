cmake_minimum_required(VERSION 3.16)

project(motor-control LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(motor-control main.cpp
    motor.h motor.cpp)

include(GNUInstallDirs)
install(TARGETS motor-control
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
