#pragma once  //  NOLINT

#include "DBConnectionImpl.hpp"
#include "DBMethods.hpp"

template<typename T = pqxx::connection, class ClassConnection = DBConnection<T>, class ClassDBMethods = DBMethods<T, ClassConnection>>
class DBWorker {
 public:
    ClassConnection connection;
    const ClassDBMethods &db_methods;

    explicit DBWorker(const ClassDBMethods &db_methods) : db_methods(db_methods) {}

    ~DBWorker() = default;
};

