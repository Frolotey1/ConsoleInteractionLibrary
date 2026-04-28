#ifndef DELETEUSER_H
#define DELETEUSER_H
#include "Input.h"

struct DeleteUser final : public InputForDeleteUser {
    std::string delete_user_name;
    void run() override;
    bool delete_user(const std::string &name) override;
};

#endif // DELETEUSER_H
