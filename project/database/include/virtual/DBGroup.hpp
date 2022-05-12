#pragma once  //  NOLINT

#include <string>

#include "Group.hpp"
#include "User.hpp"

class DBGroup {
 public:
    virtual int Create(const Group &group, std::string &group_id) const = 0;

    virtual int ReWrite(const Group &group) const = 0;

    virtual int DeleteAllMembers(const std::string &group_id) const = 0;

    virtual int Delete(const std::string &group_id) const = 0;

    virtual int GetMembers(const std::string &group_id, Group &group) const = 0;

    virtual int AddMember(const User &user, const std::string &group_id) const = 0;

    virtual int RmMember(const User &user, const std::string &group_id) const = 0;

    virtual int GetId(const Group &group, std::string &group_id) const = 0;

    virtual ~DBGroup() = default;
};
