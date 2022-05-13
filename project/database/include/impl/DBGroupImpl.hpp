#pragma once  //  NOLINT

#include "DBGroup.hpp"

static enum result_create_group {NOT_CREATE_GROUP = 5, ERROR_CREATE_GROUP} CREATE_CONTACT;

static enum result_add_group_member  {NOT_ADD_GROUP_MEMBER = 10, ERROR_ADD_GROUP_MEMBER} ADD_GROUP_MEMBER;

static enum result_rm_group_member  {NOT_RM_GROUP_MEMBER = 10, ERROR_RM_GROUP_MEMBER} RM_GROUP_MEMBER;

static enum result_delete_group_all_member  {NOT_RM_GROUP_ALL_MEMBER = 10, ERROR_RM_GROUP_ALL_MEMBER} DELETE_GROUP_ALL_MEMBER;

static enum result_delete_group  {NOT_RM_GROUP = 10, ERROR_RM_GROUP} DELETE_GROUP;

class DBGroupImpl : public DBGroup {
 public:
    int Create(const Group &group, std::string &group_id) const override;

    int ReWrite(const Group &group) const override;

    int RmAllMembers(const std::string &group_id) const override;

    int Rm(const std::string &group_id) const override;

    int GetMembers(const std::string &group_id, Group &group) const override;

    int AddMember(const User &user, const std::string &group_id) const override;

    int RmMember(const User &user, const std::string &group_id) const override;

    int GetId(const Group &group, std::string &group_id) const override;

    int GetSet(const std::string &user_id, std::set<Group> &groups, const size_t count, const size_t page) const override;

    DBGroupImpl() = default;
    ~DBGroupImpl() = default;
};
