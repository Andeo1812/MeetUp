#pragma once  //  NOLINT

#include "DBGroup.hpp"

class DBGroupImpl: public DBGroup {
public:
    int Create(const Group& group) const override;

    int ReWrite(const Group& group) const override;

    int DeleteAllMembers(const std::string& group_id) const override;

    int Delete(const std::string& group_id) const override;

    Group GetMembers(const std::string& group_id) const override;

    int AddMember(const std::string& user_nickname, const std::string& group_id) const override;

    int RmMember(const std::string& user_nickname, const std::string& group_id) const override;

    std::string GetId(const Group& group) const override;

    ~DBGroupImpl() = default;
};
