#include "Loginsystem.h"

void LoginSystem::launch() {

    LoginSystem login_system;
    std::size_t choice;

    while(true) {
        std::cout << std::setw(60) << std::right << "Система входа" << std::endl;
        std::cout << "1) Регистрация\n2) Авторизация\n3) Изменить данные пользователя\n4) Удалить данные пользователя\n5) Выход" << std::endl;
        std::cin >> choice;
        std::cin.ignore();

        switch(choice) {
        case 1:
            login_system.registration_button();
            break;
        case 2:
            login_system.authorization_button();
            break;
        case 3:
            login_system.change_user_button();
            break;
        case 4:
            login_system.delete_user_button();
            break;
        case 5:
            login_system.exit_button();
            break;
        default:
            std::cerr << "Опция не найдена" << std::endl;
            break;
        }
    }
}

void LoginSystem::registration_button() {
    Registration registration;
    registration.run();
}
void LoginSystem::authorization_button() {
    Authorization authorization;
    authorization.run();
}
void LoginSystem::change_user_button() {
    ChangeUser change_user;
    change_user.run();
}
void LoginSystem::delete_user_button() {
    DeleteUser delete_user;
    delete_user.run();
}
void LoginSystem::exit_button() {
    DeletePath delete_path;
    delete_path.run("Database.txt");
    exit(0);
}
