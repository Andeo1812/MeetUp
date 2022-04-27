#pragma once  //  NOLINT

#include <string>

#include "Group.hpp"

class DBGroup {
 public:
    virtual int Create(const Group& group) const = 0;

    virtual int ReWrite(const Group& group) const = 0;

    virtual int DeleteAllMembers(const std::string& group_id) const = 0;

    virtual int Delete(const std::string& group_id) const = 0;

    virtual Group GetMembers(const std::string& group_id) const = 0;

    virtual int AddMember(const std::string& user_nickname, const std::string& group_id) const = 0;

    virtual int RmMember(const std::string& user_nickname, const std::string& group_id) const = 0;

    virtual std::string GetId(const Group& group) const = 0;

    virtual ~DBGroup() = default;
};
