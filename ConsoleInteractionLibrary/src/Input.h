#ifndef INPUT_H
#define INPUT_H
#include "MenuRunner.h"

class InputForRegistration {
    std::string name;
    std::string password;
public:
    virtual ~InputForRegistration();
    virtual void run() = 0;
    virtual void write_to_database(const std::string& get_name, const std::string& get_password) = 0;
};

class InputForAuthorization {
public:
    virtual ~InputForAuthorization();
    virtual void run() = 0;
    virtual std::pair<std::string,std::string> get_from_database(const std::string& name, const std::string& password) = 0;
};

class InputForChangeUser {
public:
    virtual ~InputForChangeUser();
    virtual void run() = 0;
    virtual std::pair<std::string,std::string> get_from_database_and_change(const std::string& name, const std::string& password) = 0;
};

class InputForDeleteUser {
public:
    virtual ~InputForDeleteUser();
    virtual void run() = 0;
    virtual bool delete_user(const std::string& name) = 0;
};

#endif // INPUT_H
