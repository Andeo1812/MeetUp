#pragma once  //  NOLINT

#include "User.hpp"

class DBUser {
 public:
    virtual int Registration(const User &user, std::string &new_user_id) const = 0;

    virtual int Authentication(const User &user) const = 0;

    virtual int GetId(const User &user, std::string &user_id) const = 0;

    virtual int GetNickname(const User &user, std::string &nickname) const = 0;

    virtual int Rm(const User &user) const = 0;

    virtual ~DBUser() = default;
};
