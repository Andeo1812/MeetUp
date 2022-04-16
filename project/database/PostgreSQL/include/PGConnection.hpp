#pragma once  //  NOlINT

#include <string>
#include <iostream>

#include "libpq-fe.h"

class PGConnection {
    PGConnection() = default;
    ~PGConnection() = default;

public:
    static PGconn *GetConnection();

    static void CloseConnection();
};
