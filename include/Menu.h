#ifndef MENU_H
#define MENU_H
#include "Output.h"
#include "Input.h"
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <format>

class Menu {
    std::string title;
    Output& output;
    Input& input;
    bool running;
    std::vector<std::pair<std::string, std::function<void()>>> items;
public:
    Menu(const std::string& title, Output& out, Input& in);

    void add_item(const std::string& name, std::function<void()> action);
    void add_exit_item(const std::string& name = "Выход");
    void run();
    void exit();
};

#endif
