#pragma once  //  NOLINT

#include "DBGroup.hpp"

class DBGroupImpl : public DBGroup {
 public:
    int Create(const Group &group, std::string &group_id) const override;

    int ReWrite(const Group &group) const override;

    int DeleteAllMembers(const std::string &group_id) const override;

    int Delete(const std::string &group_id) const override;

    int GetMembers(const std::string &group_id, Group &group) const override;

    int AddMember(const User &user, const std::string &group_id) const override;

    int RmMember(const User &user, const std::string &group_id) const override;

    int GetId(const Group &group, std::string &group_id) const override;

    DBGroupImpl() = default;
    ~DBGroupImpl() = default;
};
