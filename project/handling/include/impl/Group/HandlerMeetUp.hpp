#pragma once  //  NOLINT

#include "Handler.hpp"

template<typename T,
        class ClassConnection = DBConnection<T>,
        class DBMethods = AllDBMethods<T, ClassConnection>,
        class DBWorker = DBWorker<T, ClassConnection, DBMethods>>
class GetMeetUps : public Handler<T, ClassConnection, DBMethods, DBWorker> {
 public:
    Context operator()(const Context &request_body, const DBWorker &db_worker) const override;
};

/*
class GetHistoryMeetUp: public Handler {
public:
    Context process(const Context& request_body) const override;
};
*/

#include "HandlerMeetUpDefinition.hpp"
