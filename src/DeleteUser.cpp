#include "DeleteUser.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

void DeleteUser::run() {
    std::cout << "Логин: ";
    std::cin >> delete_user_name;

    if (!delete_user(delete_user_name)) {
        std::cerr << "Ошибка удаления пользователя из системы" << std::endl;
        return;
    }

    std::cout << "Пользователь '" << delete_user_name << "' был успешно удален из системы" << std::endl;
}

bool DeleteUser::delete_user(const std::string &name) {
    if (!std::filesystem::exists("Database.txt"))
        return false;

    std::ifstream read_file{"Database.txt"};

    if (!read_file.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения" << std::endl;
        return false;
    }

    std::vector<std::string> keep_lines;
    std::string line;
    bool found = false;

    while (std::getline(read_file, line)) {
        std::size_t space_pos = line.find(' ');
        if (space_pos != std::string::npos) {
            std::string current_name = line.substr(0, space_pos);
            if (current_name == name) {
                found = true;
            } else {
                keep_lines.push_back(line);
            }
        }
    }
    read_file.close();

    if (!found) {
        return false;
    }

    std::filesystem::remove("Database.txt");

    if (!keep_lines.empty()) {
        std::ofstream write_file{"Database.txt"};
        if (!write_file.is_open()) {
            std::cerr << "Ошибка открытия файла для записи" << std::endl;
            return false;
        }

        for (const auto& saved_line : keep_lines) {
            write_file << saved_line << std::endl;
        }
        write_file.close();
    }

    return true;
}
