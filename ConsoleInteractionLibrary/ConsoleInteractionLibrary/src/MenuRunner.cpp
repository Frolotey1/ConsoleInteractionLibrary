#include "MenuRunner.h"

void MenuRunner::test() {
    std::size_t count_elems = 1;
    std::size_t elem;
    std::string title;
    std::string item_name;
    std::string action;
    std::size_t exit_item;
    std::size_t run_menu;

    std::cout << "Общее название идеи для компонентов: ";
    std::cin >> title;

    Menu user_menu{title};

    std::cout << "Сколько компонентов хотите добавить: ";
    std::cin >> elem;

    while (count_elems < elem + 1) {
        std::cout << "Название " << count_elems << " компонента: ";
        std::cin >> item_name;
        std::cout << "Название действия для " << count_elems << " компонента: ";
        std::cin >> action;

        user_menu.add_item(item_name, [action]() {
            std::cout << action << std::endl;
        });

        count_elems++;
    }

    std::cout << "Для добавления элемента выхода из работы меню напишите 1: ";
    std::cin >> exit_item;

    if (exit_item == 1) {
        std::cout << "Название компонента выхода: ";
        std::cin >> item_name;
        user_menu.add_exit_item(item_name);
    }

    std::cout << "Для тестирования компонентов меню напишите 1 или 0 для заполнения еще компонентов: ";
    std::cin >> run_menu;

    if (run_menu == 1) {
        user_menu.run();
    }
}
