#include "Authorization.h"

void Authorization::run() {
    std::cout << "Логин: ";
    std::cin >> authorization_name;
    std::cout << "Пароль: ";
    std::cin >> authorization_password;

    auto [db_name, db_password] = get_from_database(authorization_name, authorization_password);

    if (db_name.empty() || db_password.empty()) {
        std::cerr << "Вход в аккаунт прошел безуспешно" << std::endl;
        return;
    }

    if (authorization_name == db_name && authorization_password == db_password) {
        std::cout << "Добро пожаловать, " << authorization_name << "!" << std::endl;
    } else {
        std::cerr << "Неверное имя пользователя или пароль" << std::endl;
    }
    menu_runner.test();
}

std::pair<std::string, std::string> Authorization::get_from_database(const std::string& name, const std::string& password) {
    std::ifstream read_data{"Database.txt"};

    if (!read_data.is_open()) {
        std::cerr << "Ошибка: не удалось открыть базу данных" << std::endl;
        return {"", ""};
    }

    std::string db_name, db_password;

    while (read_data >> db_name >> db_password) {
        if (db_name == name && db_password == password) {
            return {db_name, db_password};
        }
    }

    std::cerr << "Неверное имя пользователя или пароль" << std::endl;
    return {"", ""};
}
