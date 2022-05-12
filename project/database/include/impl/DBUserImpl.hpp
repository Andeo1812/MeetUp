#pragma once  //  NOLINT

#include "DBUser.hpp"

class DBUserImpl : public DBUser {
 public:
    int Registration(const User &user, std::string &new_user_id) const override;

    int Authentication(const User &user) const override;

    int GetId(const User &user, std::string &user_id) const override;

    int GetNickname(const User &user, std::string &nickname) const override;

    int Rm(const User &user) const override;

    DBUserImpl() = default;
    ~DBUserImpl() = default;
};
