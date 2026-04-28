#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "Input.h"

class Registration final : public InputForRegistration {
    MenuRunner menu_runner;
    std::string registration_name;
    std::string registration_password;
public:
    void run() override;
    bool check_data(const std::string& get_name, const std::string& get_password);
    void write_to_database(const std::string& get_name, const std::string& get_password) override;
};

#endif // REGISTRATION_H
