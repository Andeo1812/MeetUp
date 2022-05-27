#pragma once  //  NOLINT

#include "DBUser.hpp"

static enum result_registration {NOT_REGISTRATION = 1, ERROR_REGISTRATION} REG;

static enum result_authentication {NOT_AUTHENTICATION = 5, ERROR_AUTHENTICATION} AUTH;

static enum result_get_user_id {NOT_GET_USER_ID = 10, ERROR_GET_USER_ID} GET_USER_ID;

static enum result_get_user_nickname {NOT_GET_USER_NICKNAME = 15, ERROR_GET_USER_NICKNAME} GET_NICKNAME;

static enum result_delete_user {NOT_RM_USER = 20, ERROR_RM_USER} GET_USER_DELETE;

template<class ClassConnection>
class DBUserImpl : public DBUser<ClassConnection> {
 public:
    int Registration(const User &user, std::string *new_user_id, ClassConnection *connection) const override;

    int Authentication(const User &user, ClassConnection *connection) const override;

    int GetId(const User &user, std::string *user_id, ClassConnection *connection) const override;

    int GetNickname(const User &user, std::string *nickname, ClassConnection *connection) const override;

    int Rm(const User &user, ClassConnection *connection) const override;

    DBUserImpl() = default;
    ~DBUserImpl() = default;
};

#include "DBUserImplDefinition.hpp"
