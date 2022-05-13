#pragma once  //  NOLINT

#include <unistd.h>

#include "DBManager.hpp"

template<typename T, class ClassConnection>
DBManager<T, ClassConnection>::DBManager() {
    //  size_t numCPU = sysconf(_SC_NPROCESSORS_ONLN);

    size_t numCPU = MAX_COUNT_FREE_DB_VERSION;

    for (size_t i = 0; i < numCPU; ++i) {
        this->connection_pool.push(new ClassConnection);
    }
}

template<typename T, class ClassConnection>
ClassConnection *DBManager<T, ClassConnection>::GetFreeConnection() {
    while (this->connection_pool.empty()) {
        sleep(1);
    }

    ClassConnection *res = this->connection_pool.front();

    this->connection_pool.pop();

    return res;
}

template<typename T, class ClassConnection>
void DBManager<T, ClassConnection>::InsertConnection(ClassConnection *connection) {
    this->connection_pool.push(connection);
}

template<typename T, class ClassConnection>
size_t DBManager<T, ClassConnection>::Size() const noexcept {
    return this->connection_pool.size();
}
