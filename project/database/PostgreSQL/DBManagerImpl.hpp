#pragma once  //  NOLINT

#include <unistd.h>

#include "DBManager.hpp"

template<typename T, class ClassConnection , class DBMethods, class DBWorker>
DBManager<T, ClassConnection, DBMethods, DBWorker>::DBManager() {
    //  size_t numCPU = sysconf(_SC_NPROCESSORS_ONLN);

    size_t numCPU = MAX_COUNT_FREE_DB_VERSION;

    for (size_t i = 0; i < numCPU; ++i) {
        this->db_workers_pool.push_back(new DBWorker(db_methods));
    }
}

template<typename T, class ClassConnection , class DBMethods, class DBWorker>
DBWorker *DBManager<T, ClassConnection, DBMethods, DBWorker>::GetFreeWorker(const size_t index) {
    while (this->db_workers_pool.empty()) {
        sleep(1);
    }

    return db_workers_pool[index];
}

template<typename T, class ClassConnection , class DBMethods, class DBWorker>
size_t DBManager<T, ClassConnection, DBMethods, DBWorker>::Size() const noexcept {
    return this->db_workers_pool.size();
}
