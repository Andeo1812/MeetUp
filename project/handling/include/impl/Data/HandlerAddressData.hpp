#pragma once  //  NOLINT

#include "Handler.hpp"

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class WriteAddressData : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class GetAddressData : public Handler<T, ClassConnection, ClassDBWorker, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

#include "HandlerAddressDataDefinition.hpp"
