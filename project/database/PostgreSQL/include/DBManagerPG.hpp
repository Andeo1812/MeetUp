#pragma once  //  NOLINT

#include <queue>
#include <string>
#include <unistd.h>

#include "PGConnection.hpp"
#include "DBUserImpl.hpp"
#include "DBUserDataImpl.hpp"
#include "DBEventImpl.hpp"
#include "DBContactsImpl.hpp"
#include "DBGroupImpl.hpp"
#include "DBSynchroClientImpl.hpp"

//  LIMIT from ElephantSQL.com(source DB)
const size_t MAX_COUNT_FREE_DB_VERSION = 2;

static enum result_sql {SUCCESS = 0} RESULT;

static enum result_registration {NOT_REGISTRATION = 0, ERROR_REGISTRATION} REG;

static enum result_authentication {NOT_AUTHENTICATION = 5, ERROR_AUTHENTICATION} AUTH;

static enum result_get_user_id {NOT_GET_USER_ID = 10, ERROR_GET_USER_ID} GET_USER_ID;

static enum result_get_user_nickname {NOT_GET_USER_NICKNAME = 15, ERROR_GET_USER_NICKNAME} GET_NICKNAME;

static enum result_delete_user {NOT_DELETE_USER = 20, ERROR_DELETE_USER} GET_USER_DELETE;

static enum result_add_event {NOT_ADD_EVENT = 0, ERROR_ADD_EVENT} GET_ADD_EVENT;

static enum result_rm_event {NOT_RM_EVENT = 5, ERROR_RM_EVENT} RM_EVENT;

static enum result_add_contact {NOT_ADD_CONTACT = 5, ERROR_ADD_CONTACT} ADD_CONTACT;

static enum result_delete_contact  {NOT_DELETE_CONTACT = 10, ERROR_DELETE_CONTACT} DELETE_CONTACT;

static enum result_create_group {NOT_CREATE_GROUP = 5, ERROR_CREATE_GROUP} CREATE_CONTACT;

static enum result_add_group_member  {NOT_ADD_GROUP_MEMBER = 10, ERROR_ADD_GROUP_MEMBER} ADD_GROUP_MEMBER;

static enum result_rm_group_member  {NOT_RM_GROUP_MEMBER = 10, ERROR_RM_GROUP_MEMBER} RM_GROUP_MEMBER;

static enum result_delete_group_all_member  {NOT_DELETE_GROUP_ALL_MEMBER = 10, ERROR_DELETE_GROUP_ALL_MEMBER} DELETE_GROUP_ALL_MEMBER;

static enum result_delete_group  {NOT_DELETE_GROUP = 10, ERROR_DELETE_GROUP} DELETE_GROUP;

class DBManagerPG {
    std::queue<PGConnection *> connection_pool;
public:
    DBUserImpl User;
    DBUserDataImpl UserData;
    DBEventImpl Event;
    DBContactsImpl Contacts;
    DBGroupImpl Group;
    DBSynchroClientImpl SynchroClient;

    PGConnection *GetFreeConnection();

    void InsertConnection(PGConnection *connection);

    size_t Size() const noexcept;

    DBManagerPG();

    ~DBManagerPG() = default;
};

template<typename T>
class Singleton {
private:
    T data;
public:
    static Singleton &GetInstance() {
        static Singleton _instance;
        return _instance;
    }

    T &GetData() {
        return data;
    }

private:
    Singleton() = default;

    Singleton(const Singleton &s) {}

    Singleton &operator=(Singleton &s) {
        return s;
    }

    ~Singleton() {}
};

