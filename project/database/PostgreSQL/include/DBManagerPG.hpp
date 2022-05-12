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
const size_t MAX_COUNT_FREE_DB_VERSION = 3;

const int ERR_AUTHENTICATION = -1;

static enum result_sql {SUCCESS = 0,
        NOT_REGISTRATION, ERROR_REGISTRATION,
        NOT_AUTHENTICATION, ERROR_AUTHENTICATION,
        NOT_GET_USER_ID, ERROR_GET_USER_ID,
        NOT_GET_USER_NICKNAME, ERROR_GET_USER_NICKNAME,
        NOT_DELETE_USER, ERROR_DELETE_USER} RESULT;

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

