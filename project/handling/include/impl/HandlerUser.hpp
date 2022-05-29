#pragma once  //  NOLINT

#include "Handler.hpp"

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class Registration : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class Authentication : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class RmUser : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

#include "HandlerUserDefinition.hpp"
