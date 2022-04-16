#pragma once  //  NOLINT

#include <string>

#include "User.hpp"
#include "Event.hpp"
#include "Group.hpp"

class DBGetField {
public:
    virtual std::string UserId(const User& user) const = 0;

    virtual std::string EventId(const Event& event) const = 0;

    virtual std::string GroupId(const Group& group) const = 0;

    virtual std::string Nickname(const User& user) const = 0;

    virtual ~DBGetField() = default;
};
