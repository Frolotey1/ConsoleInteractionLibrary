#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <string>

class Input {
public:
    virtual ~Input() = default;
    virtual std::string read_line() = 0;
};

#endif // INPUT_H
