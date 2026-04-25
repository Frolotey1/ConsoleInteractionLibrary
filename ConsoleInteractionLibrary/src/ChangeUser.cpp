#include "ChangeUser.h"

void ChangeUser::run() {
    std::cout << "Логин: ";
    std::cin >> change_user_name;
    std::cout << "Пароль: ";
    std::cin >> change_user_password;

    std::cout << "Новый логин: ";
    std::cin >> new_name;
    std::cout << "Новый пароль: ";
    std::cin >> new_password;

    auto [old_name, old_password] = get_from_database_and_change(change_user_name, change_user_password);

    if (old_name.empty() || old_password.empty()) {
        std::cerr << "Ошибка данных" << std::endl;
        return;
    }

    std::cout << "Данные пользователя '" << change_user_name << "' успешно изменены на '"
              << new_name << "'" << std::endl;
}

std::pair<std::string, std::string> ChangeUser::get_from_database_and_change(
    const std::string& name, const std::string& password) {

    std::ifstream read_data{"Database.txt"};

    if (!read_data.is_open()) {
        std::cerr << "Ошибка: не удалось открыть базу данных для чтения" << std::endl;
        return {"",""};
    }

    std::vector<std::pair<std::string, std::string>> users;
    std::string db_name, db_password;

    while (read_data >> db_name >> db_password) {
        users.push_back({db_name, db_password});
    }

    read_data.close();

    bool found = false;

    for (auto& [stored_name, stored_password] : users) {
        if (stored_name == name && stored_password == password) {
            stored_name = new_name;
            stored_password = new_password;
            found = true;
            break;
        }
    }

    if (!found) {
        return {"",""};
    }

    std::ofstream write_data{"Database.txt"};
    if (!write_data.is_open()) {
        std::cerr << "Ошибка: не удалось открыть базу данных для записи" << std::endl;
        return {"",""};
    }

    for (const auto& [stored_name, stored_password] : users) {
        write_data << stored_name << " " << stored_password << std::endl;
    }

    return {name, password};
}
