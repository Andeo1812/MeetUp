#pragma once  //  NOLINT

#include <unistd.h>

#include "DBManager.hpp"

template<typename T, class ClassConnection , class ClassDBMethods, class ClassDBWorker>
DBManager<T, ClassConnection, ClassDBMethods, ClassDBWorker>::DBManager() {
    //  size_t numCPU = sysconf(_SC_NPROCESSORS_ONLN);

    size_t numCPU = MAX_COUNT_FREE_DB_VERSION;

    for (size_t i = 0; i < numCPU; ++i) {
        this->db_workers_pool.push_back(std::make_unique<ClassDBWorker>(db_methods));
    }

    count_db_workers = db_workers_pool.size();
}

template<typename T, class ClassConnection , class ClassDBMethods, class ClassDBWorker>
ClassDBWorker *DBManager<T, ClassConnection, ClassDBMethods, ClassDBWorker>::GetFreeWorker(const size_t index) {
    while (this->db_workers_pool.empty()) {
        sleep(1);
    }

    return db_workers_pool[index].get();
}

template<typename T, class ClassConnection , class ClassDBMethods, class ClassDBWorker>
size_t DBManager<T, ClassConnection, ClassDBMethods, ClassDBWorker>::Size() const noexcept {
    return this->db_workers_pool.size();
}
