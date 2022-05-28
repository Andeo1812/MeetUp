#pragma once  //  NOLINT

#include "Handler.hpp"

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class AddGroup : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class WriteGroup : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class RmGroup : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class GetGroupMembers : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};


template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class AddUserGroup : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class RmUserGroup : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

/*
class SearchGroup: public Handler {
 public:
    Context* process(const Context* request_body) const override;
};
 */

#include "HandlerGroupDefinition.hpp"
#include "HandlerGroupManagementDefinition.hpp"
