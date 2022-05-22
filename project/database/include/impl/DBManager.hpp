#pragma once  //  NOLINT

#include <queue>
#include <string>
#include <unistd.h>
#include <pqxx/pqxx>

#include "DBConnectionImpl.hpp"
#include "DBUserImpl.hpp"
#include "DBUserDataImpl.hpp"
#include "DBEventImpl.hpp"
#include "DBContactsImpl.hpp"
#include "DBGroupImpl.hpp"

//  LIMIT from ElephantSQL.com(source DB)
const size_t MAX_COUNT_FREE_DB_VERSION = 2;

template<typename T, class ClassConnection = DBConnection<T>>
class DBManager {
    std::queue<ClassConnection *> connection_pool;

 public:
    DBUserImpl<ClassConnection> User;
    DBUserDataImplDefinition<ClassConnection> UserData;
    DBEventImpl<ClassConnection> Event;
    DBContactsImpl<ClassConnection> Contacts;
    DBGroupImplDefinition<ClassConnection> Group;

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

    Singleton &operator=(const Singleton &s) {
        return s;
    }

    ~Singleton() {}
};

#include "DBManagerImpl.hpp"
