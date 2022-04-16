#pragma once  //  NOLINT

#include "User.hpp"

class DBRegAuth {
public:
    virtual int Registration(const User& user) const = 0;

    virtual int Authentication(const User& user) const = 0;

    virtual ~DBRegAuth() = default;
};
