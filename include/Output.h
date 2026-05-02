#ifndef OUTPUT_H
#define OUTPUT_H
#include <iostream>
#include <string>

class Output {
public:
    virtual ~Output() = default;
    virtual void write(const std::string& context = "") = 0;
    virtual void write_line(const std::string& context = "") = 0;
};

#endif
