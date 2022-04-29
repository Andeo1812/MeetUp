#pragma once  //  NOLINT

#include "DBUser.hpp"

class DBUserImpl : public DBUser {
 public:
    int Registration(const User &user) const override;

    int Authentication(const User &user) const override;

    std::string GetId(const User &user) const override;

    std::string GetNickname(const User &user) const override;

    ~DBUserImpl() = default;
};
