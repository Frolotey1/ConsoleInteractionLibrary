cmake_minimum_required(VERSION 3.16)

project(ConsoleInteractionLibrary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ConsoleInteractionLibrary src/main.cpp
    src/Authorization.h src/Authorization.cpp
    src/Input.h src/Input.cpp
    src/Libraries.h
    src/Registration.h src/Registration.cpp
    src/Loginsystem.h src/Loginsystem.cpp
    src/ChangeUser.h src/ChangeUser.cpp
    src/DeletePath.h src/DeletePath.cpp
    src/DeleteUser.h src/DeleteUser.cpp
    src/Menu.h src/Menu.cpp
    src/MenuRunner.h src/MenuRunner.cpp
    test/AllTests.cpp
)
target_include_directories(ConsoleInteractionLibrary PRIVATE src)

include(GNUInstallDirs)
install(TARGETS ConsoleInteractionLibrary
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
