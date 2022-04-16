#pragma once  //  NOLINT

#include "DBGetField.hpp"

class DBGetFieldImpl: public DBGetField {
public:
    std::string UserId(const User& user) const override;

    std::string EventId(const Event& event) const override;

    std::string GroupId(const Group& group) const override;

    std::string Nickname(const User& user) const override;

    ~DBGetFieldImpl() = default;
};
