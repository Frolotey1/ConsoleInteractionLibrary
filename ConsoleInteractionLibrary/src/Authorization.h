#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H
#include "Input.h"
class Authorization final : public InputForAuthorization {
    MenuRunner menu_runner;
    std::string authorization_name = "";
    std::string authorization_password = "";
public:
    void run() override;
    std::pair<std::string,std::string> get_from_database(const std::string& name, const std::string& password) override;
};

#endif // AUTHORIZATION_H
