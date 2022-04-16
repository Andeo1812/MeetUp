#pragma once  //  NOLINT

#include "DBRegAuth.hpp"

class DBRegAuthImpl: public DBRegAuth {
public:
    int Registration(const User& user) const override;

    int Authentication(const User& user) const override;

    ~DBRegAuthImpl() = default;
};
