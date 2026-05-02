#ifndef CONSOLEINPUT_H
#define CONSOLEINPUT_H
#include "Input.h"

class ConsoleInput : public Input {
public:
    std::string read_line() override;
};

#endif
