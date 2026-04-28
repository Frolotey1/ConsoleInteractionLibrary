#include "Registration.h"

void Registration::run() {
    while (true) {
        std::cout << "Логин: ";
        std::getline(std::cin, registration_name);
        std::cout << "Пароль: ";
        std::getline(std::cin, registration_password);

        if (check_data(registration_name, registration_password)) {
            break;
        }
        std::cerr << "Ошибка валидации\n";
    }

    write_to_database(registration_name, registration_password);
    std::cout << "Регистрация прошла успешно\n";
}

bool Registration::check_data(const std::string& get_name, const std::string& get_password) {
    if (get_name.empty() || get_password.empty()) {
        std::cerr << "Ошибка: логин и пароль не могут быть пустыми" << std::endl;
        return false;
    }

    for (char c : get_name) {
        if (!std::isalnum(static_cast<unsigned char>(c))) {
            std::cerr << "Логин должен содержать только буквы и цифры" << std::endl;
            return false;
        }
    }

    int special_count = 0;
    for (char c : get_password) {
        if (std::ispunct(static_cast<unsigned char>(c))) {
            special_count++;
        }
    }

    if (special_count < 3) {
        std::cerr << "Пароль должен содержать не менее 3 специальных символов (! @ # и т.д.)" << std::endl;
        return false;
    }

    if (get_password.length() < 6) {
        std::cerr << "Пароль должен содержать не менее 6 символов" << std::endl;
        return false;
    }

    return true;
}
void Registration::write_to_database(const std::string& get_name, const std::string& get_password) {
    std::ofstream write_data{"Database.txt", std::ios::app};

    if (!write_data.is_open()) {
        std::cerr << "Ошибка записи данных в базу" << std::endl;
        return;
    }

    write_data << get_name << " " << get_password << std::endl;
}
