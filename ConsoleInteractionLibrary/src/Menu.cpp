#include "Menu.h"

Menu::Menu() = default;
Menu::Menu(const std::string& title) : _title(title) {}
void Menu::add_item(const std::string& name, std::function<void()> action) {
    items.push_back({name, action});
}
void Menu::add_exit_item(const std::string& name) {
    items.push_back({name, [this]() { running = false; }});
}
void Menu::run() {
    running = true;
    while (running) {
        std::cout << std::setw(60) << std::right << _title << std::endl;
        for (std::size_t i = 0; i < items.size(); ++i) {
            std::cout << (i + 1) << ") " << items[i].first << '\n';
        }

        std::cout << "Выберите опцию: ";
        std::size_t choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice >= 1 && choice <= items.size())
            items[choice - 1].second();
        else
            std::cerr << "Неверный выбор" << std::endl;

    }
}
void Menu::exit() {
    running = false;
}
