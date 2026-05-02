#ifndef MENURUNNER_H
#define MENURUNNER_H
#include "Menu.h"
#include "Output.h"
#include "Input.h"
#include "InputDialog.h"
#include <string>
#include <format>

class MenuRunner {
    Output& output;
    Input& input;
public:
    MenuRunner(Output& out, Input& in);
    void test();
};

#endif
