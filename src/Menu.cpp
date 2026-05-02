#include "../include/Menu.h"

Menu::Menu(const std::string& title, Output& out, Input& in)
    : title(title), output(out), input(in), running(true) {}

void Menu::add_item(const std::string& name, std::function<void()> action) {
    items.push_back({name, action});
}
void Menu::add_exit_item(const std::string& name) {
    items.push_back({name, [this]() { running = false; }});
}
void Menu::run() {
    running = true;
    while (running) {
        output.write_line("\t\t" + title);

        for (std::size_t i = 0; i < items.size(); ++i) {
            output.write_line(std::format("{}) {}",i + 1,items[i].first));
        }

        output.write("Выберите опцию: ");
        std::size_t choice = std::stoi(input.read_line());

        if (choice >= 1 && choice <= items.size()) {
            items[choice - 1].second();
        } else {
            output.write_line("Неверный выбор");
        }
    }
}

void Menu::exit() {
    running = false;
}
