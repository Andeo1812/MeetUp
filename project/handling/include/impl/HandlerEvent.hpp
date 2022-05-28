#pragma once  //  NOLINT

#include "Handler.hpp"

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class AddEvent : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class WriteEvent : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class RmEvent : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

#include "HandlerEventDefinition.hpp"
