#include "Deleteuser.h"

void DeleteUser::run() {
    std::cout << "Логин: ";
    std::cin >> delete_user_name;

    if(!delete_user(delete_user_name)) {
        std::cerr << "Ошибка удаления пользователя из системы" << std::endl;
        return;
    }

    std::cout << "Пользователь '" << delete_user_name << "' был успешно удален из системы" << std::endl;
}
bool DeleteUser::delete_user(const std::string &name) {
    if(!std::filesystem::exists("Database.txt"))
        return false;

    std::ifstream delete_from{"Database.txt"};

    if(!delete_from.is_open()) {
        std::cerr << "Ошибка открытия файла" << std::endl;
        return false;
    }

    std::string find_other_name;
    std::vector<std::string> save_other_names_and_passwords;

    while(delete_from >> find_other_name) {
        if(find_other_name.substr(0,find_other_name.find(' ')) != name) {
            save_other_names_and_passwords.emplace_back(find_other_name);
        }
    }

    std::filesystem::remove("Database.txt");
    std::ofstream rewrite_to{"Database.txt",std::ios::app};

    if(!rewrite_to.is_open()) {
        std::cerr << "Ошибка открытия файла" << std::endl;
        return false;
    }

    for(auto& write_again : save_other_names_and_passwords) {
        rewrite_to << write_again << std::endl;
    }
    save_other_names_and_passwords.clear();
    rewrite_to.close();
    return true;
}
