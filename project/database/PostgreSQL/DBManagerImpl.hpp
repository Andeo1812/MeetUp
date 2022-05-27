#pragma once  //  NOLINT

#include <unistd.h>

#include "DBManager.hpp"

template<typename T, class ClassConnection , class DBMethods>
DBManager<T, ClassConnection, DBMethods>::DBManager() {
    //  size_t numCPU = sysconf(_SC_NPROCESSORS_ONLN);

    size_t numCPU = MAX_COUNT_FREE_DB_VERSION;

    for (size_t i = 0; i < numCPU; ++i) {
        this->connection_pool.push(new ClassConnection);
    }
}

template<typename T, class ClassConnection , class DBMethods>
ClassConnection *DBManager<T, ClassConnection, DBMethods>::GetFreeConnection() {
    while (this->connection_pool.empty()) {
        sleep(1);
    }

    ClassConnection *res = this->connection_pool.front();

    this->connection_pool.pop();

    return res;
}

template<typename T, class ClassConnection , class DBMethods>
void DBManager<T, ClassConnection, DBMethods>::InsertConnection(ClassConnection *connection) {
    this->connection_pool.push(connection);
}

template<typename T, class ClassConnection , class DBMethods>
size_t DBManager<T, ClassConnection, DBMethods>::Size() const noexcept {
    return this->connection_pool.size();
}
