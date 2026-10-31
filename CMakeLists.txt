cmake_minimum_required(VERSION 3.16)

project(motor-control LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(motor-control main.cpp
    motor.h motor.cpp
    pidcontroller.h pidcontroller.cpp
)

include(GNUInstallDirs)
install(TARGETS motor-control
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
# --- Unit tests ---
find_package(Qt6 REQUIRED COMPONENTS Test)
enable_testing()

add_executable(tst_pidcontroller
    tests/tst_pidcontroller.cpp
    pidcontroller.h pidcontroller.cpp
    motor.h motor.cpp
)
set_target_properties(tst_pidcontroller PROPERTIES AUTOMOC ON)
target_link_libraries(tst_pidcontroller PRIVATE Qt6::Test)
add_test(NAME tst_pidcontroller COMMAND tst_pidcontroller)