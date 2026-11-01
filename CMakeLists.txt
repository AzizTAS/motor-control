cmake_minimum_required(VERSION 3.16)

project(motor-control LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Test)
qt_standard_project_setup(REQUIRES 6.10)

qt_add_executable(motor-control main.cpp
    motor.h motor.cpp
    pidcontroller.h pidcontroller.cpp
)

qt_add_qml_module(motor-control
    URI MotorControl
    QML_FILES Main.qml
)

target_link_libraries(motor-control PRIVATE Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS motor-control
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
# --- Unit tests ---

enable_testing()

add_executable(tst_pidcontroller
    tests/tst_pidcontroller.cpp
    pidcontroller.h pidcontroller.cpp
    motor.h motor.cpp
)
set_target_properties(tst_pidcontroller PROPERTIES AUTOMOC ON)
target_link_libraries(tst_pidcontroller PRIVATE Qt6::Test)
add_test(NAME tst_pidcontroller COMMAND tst_pidcontroller)