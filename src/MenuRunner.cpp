#include "../include/MenuRunner.h"
#include "../include/Validators.h"

MenuRunner::MenuRunner(Output& out, Input& in)
    : output(out), input(in) {}

void MenuRunner::test() {
    InputDialog<std::string> title_dialog(output, input);

    std::string title;

    while(true) {
        title = title_dialog.dialog("Общее название идеи для компонентов");
        if (not_empty(title)) {
            break;
        }
        output.write_line("Ошибка: название не может быть пустым");
    }

    InputDialog<int> count_dialog(output, input);
    int elem;
    while (true) {
        elem = count_dialog.dialog("Сколько компонентов хотите добавить: ");
        if (positive(elem)) {
            break;
        }
        output.write_line("Ошибка: число должно быть положительным");
    }

    Menu user_menu(title, output, input);

    InputDialog<std::string> name_dialog(output, input);
    InputDialog<std::string> action_dialog(output, input);

    for (int i = 1; i <= elem; ++i) {
        std::string item_name;
        while (true) {
            item_name = name_dialog.dialog(std::format("Название {} компонента", i));
            if (not_empty(item_name)) {
                break;
            }
            output.write_line("Ошибка: название компонента не может быть пустым");
        }

        std::string action;
        while (true) {
            action = action_dialog.dialog(std::format("Название действия для {} компонента", i));
            if (not_empty(action)) {
                break;
            }
            output.write_line("Ошибка: действие не может быть пустым");
        }

        user_menu.add_item(item_name, [action, this]() {
            output.write_line(action);
        });
    }

    InputDialog<int> exit_choice_dialog(output, input);

    int exit_item;
    while (true) {
        exit_item = exit_choice_dialog.dialog("Для добавления элемента выхода напишите 1 (0 - пропустить)");
        if (exit_item == 0 || exit_item == 1) {
            break;
        }
        output.write_line("Ошибка: введите 0 или 1");
    }

    if (exit_item == 1) {
        std::string exit_name;
        while (true) {
            exit_name = name_dialog.dialog("Название компонента выхода");
            if (not_empty(exit_name)) {
                break;
            }
            output.write_line("Ошибка: название не может быть пустым");
        }
        user_menu.add_exit_item(exit_name);
    }

    InputDialog<int> run_choice_dialog(output, input);

    int run_menu;
    while (true) {
        run_menu = run_choice_dialog.dialog("Для тестирования меню напишите 1, для выхода - 0");
        if (run_menu == 0 || run_menu == 1) {
            break;
        }
        output.write_line("Ошибка: введите 0 или 1");
    }

    if (run_menu == 1) {
        user_menu.run();
    }
}
