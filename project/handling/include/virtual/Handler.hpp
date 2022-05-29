#pragma once  //  NOLINT

#include "Context.hpp"
#include "DBManager.hpp"

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class Handler {
 public:
    virtual Context operator()(const Context &request_body, ClassDBWorker *db_worker) const = 0;

    virtual ~Handler() = default;
};
