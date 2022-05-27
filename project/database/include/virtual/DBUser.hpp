#pragma once  //  NOLINT

#include "User.hpp"

template<class ClassConnection>
class DBUser {
 public:
    virtual int Registration(const User &user, std::string *new_user_id, ClassConnection *connection) const = 0;

    virtual int Authentication(const User &user, std::string *user_id, ClassConnection *connection) const = 0;

    virtual int GetId(const User &user, std::string *user_id, ClassConnection *connection) const = 0;

    virtual int GetNickname(const User &user, std::string *nickname, ClassConnection *connection) const = 0;

    virtual int Rm(const User &user, ClassConnection *connection) const = 0;

    virtual ~DBUser() = default;
};
