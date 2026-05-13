#include "../include/ConsoleOutput.h"

void ConsoleOutput::write(const std::string& context) {
    std::cout << context;
}

void ConsoleOutput::write_line(const std::string& context) {
    std::cout << context << std::endl;
}
