#pragma once  //  NOLINT

#include "Handler.hpp"
#include "Parser.hpp"
#include "DBManager.hpp"

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>,
        class ClassDBManager = DBManager<T, ClassConnection, ClassDBMethods, ClassDBWorker>>
class Route {
 public:
    virtual void InsertTask(const std::string &task) = 0;

    virtual std::tuple<int, std::string> GetResTask(const std::string &request_body) = 0;

    virtual ~Route() = default;
};
