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

