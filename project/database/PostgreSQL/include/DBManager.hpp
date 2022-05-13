#pragma once  //  NOLINT

#include <queue>
#include <string>
#include <unistd.h>
#include <pqxx/pqxx>

#include "DBConnection.hpp"
#include "DBUserImpl.hpp"
#include "DBUserDataImpl.hpp"
#include "DBEventImpl.hpp"
#include "DBContactsImpl.hpp"
#include "DBGroupImpl.hpp"

//  LIMIT from ElephantSQL.com(source DB)
const size_t MAX_COUNT_FREE_DB_VERSION = 2;

static enum result_sql {SUCCESS = 0} RESULT;

template<typename T, class ClassConnection = DBConnection<T>>
class DBManager {
    std::queue<ClassConnection *> connection_pool;
public:
    DBUserImpl User;
    DBUserDataImpl UserData;
    DBEventImpl Event;
    DBContactsImpl Contacts;
    DBGroupImpl Group;

    ClassConnection *GetFreeConnection();

    void InsertConnection(ClassConnection *connection);

    size_t Size() const noexcept;

    DBManager();

    ~DBManager() = default;
};

template<typename Class>
class Singleton {
private:
    Class data;
public:
    static Singleton &GetInstance() {
        static Singleton _instance;
        return _instance;
    }

    Class &GetData() {
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

#include "DBManagerImpl.hpp"
