#pragma once  //  NOLINT

#include "Handler.hpp"

template<typename T,
        class ClassConnection = DBConnection<T>,
        class DBMethods = AllDBMethods<T, ClassConnection>,
        class DBWorker = DBWorker<T, ClassConnection, DBMethods>>
class WriteAddressData : public Handler<T, ClassConnection, DBMethods, DBWorker> {
 public:
    Context operator()(const Context &request_body, const DBWorker &db_worker) const override;
};

template<typename T,
        class ClassConnection = DBConnection<T>,
        class DBMethods = AllDBMethods<T, ClassConnection>,
        class DBWorker = DBWorker<T, ClassConnection, DBMethods>>
class GetAddressData : public Handler<T, ClassConnection, DBMethods, DBWorker> {
 public:
    Context operator()(const Context &request_body, const DBWorker &db_worker) const override;
};

#include "HandlerAddressDataDefinition.hpp"
