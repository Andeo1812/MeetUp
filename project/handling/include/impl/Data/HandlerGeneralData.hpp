#pragma once  //  NOLINT

#include "Handler.hpp"

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class WriteGeneralData : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class GetGeneralData : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

#include "HandlerGeneralDataDefinition.hpp"
