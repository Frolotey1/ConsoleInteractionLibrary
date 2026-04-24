#ifndef MENU_H
#define MENU_H
#include "Libraries.h"

class Menu {
    std::string _title;
    bool running;
    std::vector<std::pair<std::string,std::function<void()>>> items;
public:
    Menu();
    explicit Menu(const std::string& title);
    void add_item(const std::string& name, std::function<void()> action);
    void add_exit_item(const std::string& name);
    void run();
    void exit();
};

#endif // MENU_H
