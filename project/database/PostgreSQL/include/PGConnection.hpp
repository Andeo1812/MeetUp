#pragma once  //  NOlINT

#include <string>
#include <iostream>

#include <libpq-fe.h>

#include "DBConnection.hpp"

class PGConnection : public DBConnection {
    PGConnection() = default;
    ~PGConnection() = default;

 public:
    static PGconn *GetConnection();

    static void CloseConnection();
};
