#pragma once  //  NOLINT

#include <queue>
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


class DBManagerPG {
    std::queue<PGConnection*> connection_pool;
 public:
    DBUserImpl User;
    DBUserDataImpl UserData;
    DBEventImpl Event;
    DBContactsImpl Contacts;
    DBGroupImpl Group;
    DBSynchroClientImpl SynchroClient;

    PGConnection *GetFreeConnection();

    DBManagerPG();

    ~DBManagerPG() = default;
};

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