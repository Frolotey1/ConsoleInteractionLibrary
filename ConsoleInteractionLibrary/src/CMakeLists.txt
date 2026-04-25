cmake_minimum_required(VERSION 3.16)

project(ConsoleInteractionLibrary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ConsoleInteractionLibrary main.cpp
    Authorization.h Authorization.cpp
    Input.h Input.cpp
    Libraries.h
    Registration.h Registration.cpp
    Loginsystem.h Loginsystem.cpp
    ChangeUser.h ChangeUser.cpp
    Deletepath.h Deletepath.cpp
    Deleteuser.h Deleteuser.cpp
    Menu.h Menu.cpp
    MenuRunner.h MenuRunner.cpp
    test/AllTests.cpp
)

include(GNUInstallDirs)
install(TARGETS ConsoleInteractionLibrary
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
