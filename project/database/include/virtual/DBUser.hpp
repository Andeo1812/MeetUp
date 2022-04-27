#pragma once  //  NOLINT

#include "User.hpp"

class DBUser {
public:
    virtual int Registration(const User& user) const = 0;

    virtual int Authentication(const User& user) const = 0;

    virtual std::string GetId(const User& user) const = 0;

    virtual std::string GetNickname(const User& user) const = 0;

    virtual ~DBUser() = default;
};
