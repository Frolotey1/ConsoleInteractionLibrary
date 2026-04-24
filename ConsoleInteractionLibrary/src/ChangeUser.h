#ifndef CHANGEUSER_H
#define CHANGEUSER_H
#include "Input.h"

struct ChangeUser final : public InputForChangeUser {
    std::string change_user_name;
    std::string change_user_password;
    std::string new_name;
    std::string new_password;
    void run() override;
    std::pair<std::string, std::string> get_from_database_and_change(const std::string& name, const std::string& password);
};

#endif // CHANGEUSER_H
