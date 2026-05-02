#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H
#include "Output.h"

class ConsoleOutput : public Output {
public:
    void write(const std::string& context = "") override;
    void write_line(const std::string& context = "") override;
};

#endif
