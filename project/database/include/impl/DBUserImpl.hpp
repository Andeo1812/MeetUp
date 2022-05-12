#pragma once  //  NOLINT

#include "DBUser.hpp"

static enum result_registration {NOT_REGISTRATION = 0, ERROR_REGISTRATION} REG;

static enum result_authentication {NOT_AUTHENTICATION = 5, ERROR_AUTHENTICATION} AUTH;

static enum result_get_user_id {NOT_GET_USER_ID = 10, ERROR_GET_USER_ID} GET_USER_ID;

static enum result_get_user_nickname {NOT_GET_USER_NICKNAME = 15, ERROR_GET_USER_NICKNAME} GET_NICKNAME;

static enum result_delete_user {NOT_DELETE_USER = 20, ERROR_DELETE_USER} GET_USER_DELETE;

class DBUserImpl : public DBUser {
 public:
    int Registration(const User &user, std::string &new_user_id) const override;

    int Authentication(const User &user) const override;

    int GetId(const User &user, std::string &user_id) const override;

    int GetNickname(const User &user, std::string &nickname) const override;

    int Rm(const User &user) const override;

    DBUserImpl() = default;
    ~DBUserImpl() = default;
};
