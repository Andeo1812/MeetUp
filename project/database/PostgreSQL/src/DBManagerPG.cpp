#include <unistd.h>

#include "DBManagerPG.hpp"

DBManagerPG::DBManagerPG() {
    //  size_t numCPU = sysconf(_SC_NPROCESSORS_ONLN);

    size_t numCPU = MAX_COUNT_FREE_DB_VERSION;

    for (size_t i = 0; i < numCPU; ++i) {
        this->connection_pool.push(new PGConnection);
    }
}

PGConnection *DBManagerPG::GetFreeConnection() {
    while (this->connection_pool.empty()) {
        sleep(1);
    }

    PGConnection *res = this->connection_pool.front();

    this->connection_pool.pop();

    return res;
}

void DBManagerPG::InsertConnection(PGConnection *connection) {
    this->connection_pool.push(connection);
}

size_t DBManagerPG::Size() const noexcept {
    return this->connection_pool.size();
}
