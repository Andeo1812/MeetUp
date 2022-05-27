#pragma once  //  NOLINT

#include <queue>
#include <string>
#include <unistd.h>
#include <pqxx/pqxx>

#include "DBConnectionImpl.hpp"
#include "DBMethods.hpp"
#include "DBWorker.hpp"

//  LIMIT from ElephantSQL.com(source DB)
const size_t MAX_COUNT_FREE_DB_VERSION = 2;

template<typename T,
        class ClassConnection = DBConnection<T>,
                class DBMethods = AllDBMethods<T, ClassConnection>,
                        class DBWorker = DBWorker<T, ClassConnection, DBMethods>>
class DBManager {
    std::vector<DBWorker*> db_workers_pool;

 public:
    DBMethods db_methods;

    DBWorker *GetFreeWorker(const size_t index);

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
