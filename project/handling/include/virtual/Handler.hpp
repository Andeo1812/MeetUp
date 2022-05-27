#pragma once  //  NOLINT

#include "Context.hpp"
#include "DBManager.hpp"

template<typename T,
        class ClassConnection = DBConnection<T>,
        class DBMethods = AllDBMethods<T, ClassConnection>,
        class DBWorker = DBWorker<T, ClassConnection, DBMethods>>
class Handler {
 public:
    virtual Context operator()(const Context &request_body, const DBWorker &db_worker) const = 0;

    virtual ~Handler() = default;
};
