cmake_minimum_required(VERSION 3.16)

project(ConsoleInteractionLibrary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ConsoleInteractionLibrary src/main.cpp
    include/Input.h
    include/Output.h
    include/ConsoleInput.h src/ConsoleInput.cpp
    include/ConsoleOutput.h src/ConsoleOutput.cpp
    include/InputDialog.h
    include/Menu.h src/Menu.cpp
    include/MenuRunner.h src/MenuRunner.cpp
    include/Validators.h
    test/AllTests.cpp
)

include(GNUInstallDirs)
install(TARGETS ConsoleInteractionLibrary
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
