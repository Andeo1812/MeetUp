#pragma once  //  NOLINT

#include "Handler.hpp"

template<typename T,
        class ClassConnection = DBConnection<T>,
        class DBMethods = AllDBMethods<T, ClassConnection>,
        class DBWorker = DBWorker<T, ClassConnection, DBMethods>>
class AddEvent : public Handler<T, ClassConnection, DBMethods, DBWorker> {
 public:
    Context operator()(const Context &request_body, const DBWorker &db_worker) const override;
};

template<typename T,
        class ClassConnection = DBConnection<T>,
        class DBMethods = AllDBMethods<T, ClassConnection>,
        class DBWorker = DBWorker<T, ClassConnection, DBMethods>>
class WriteEvent : public Handler<T, ClassConnection, DBMethods, DBWorker> {
 public:
    Context operator()(const Context &request_body, const DBWorker &db_worker) const override;
};

template<typename T,
        class ClassConnection = DBConnection<T>,
        class DBMethods = AllDBMethods<T, ClassConnection>,
        class DBWorker = DBWorker<T, ClassConnection, DBMethods>>
class RmEvent : public Handler<T, ClassConnection, DBMethods, DBWorker> {
 public:
    Context operator()(const Context &request_body, const DBWorker &db_worker) const override;
};

#include "HandlerEventDefinition.hpp"
