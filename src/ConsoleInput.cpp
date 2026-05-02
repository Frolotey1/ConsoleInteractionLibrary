#include "../include/ConsoleInput.h"

std::string ConsoleInput::read_line() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}
