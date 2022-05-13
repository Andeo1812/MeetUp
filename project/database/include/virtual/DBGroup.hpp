#pragma once  //  NOLINT

#include <string>
#include <set>

#include "Group.hpp"
#include "User.hpp"

template<class ClassConnection>
class DBGroup {
 public:
    virtual int Create(const Group &group, std::string *group_id, ClassConnection *connection) const = 0;

    virtual int ReWrite(const Group &group, ClassConnection *connection) const = 0;

    virtual int RmAllMembers(const std::string &group_id, ClassConnection *connection) const = 0;

    virtual int Rm(const std::string &group_id, ClassConnection *connection) const = 0;

    virtual int GetMembers(const std::string &group_id, Group *group, ClassConnection *connection) const = 0;

    virtual int AddMember(const std::string &user_id, const std::string &group_id, ClassConnection *connection) const = 0;

    virtual int RmMember(const std::string &user_id, const std::string &group_id, ClassConnection *connection) const = 0;

    virtual int GetId(const Group &group, std::string *group_id, ClassConnection *connection) const = 0;

    virtual int GetSet(const std::string &user_id, std::set<Group> *groups, const size_t &left, const size_t &right, ClassConnection *connection) const = 0;

    virtual ~DBGroup() = default;
};
