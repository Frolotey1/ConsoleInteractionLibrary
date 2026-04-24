#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H
#include "Authorization.h"
#include "Registration.h"
#include "ChangeUser.h"
#include "Deletepath.h"
#include "Deleteuser.h"

class LoginSystem {
public:
    void launch();
private:
    void registration_button();
    void authorization_button();
    void change_user_button();
    void delete_user_button();
    void exit_button();
};

#endif // LOGINSYSTEM_H
