#pragma once  //  NOLINT

#include "DBConnectionImpl.hpp"
#include "DBMethods.hpp"

template<typename T, class ClassConnection = DBConnection<T>, class DBMethods = AllDBMethods<T, ClassConnection>>
class DBWorker {
 public:
    ClassConnection connection;
    const DBMethods &db_methods;

    DBWorker(const DBMethods &db_methods) : db_methods(db_methods) {}

    ~DBWorker() = default;
};

