#pragma once  //  NOLINT

#include "Handler.hpp"

template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>>
class GetMeetUps : public Handler<T, ClassConnection, ClassDBMethods, ClassDBWorker> {
    int GetDataSetEvents(const std::string &group_id, const std::string &date,  ClassDBWorker *db_worker, std::set<Event> *events_day) const;

    int GetMeetUpSet(const std::string &group_id, const std::string &date,  ClassDBWorker *db_worker, std::set<MeetUp> *meetups_day) const;
 public:
    Context operator()(const Context &request_body, ClassDBWorker *db_worker) const override;
};

/*
class GetHistoryMeetUp: public Handler {
public:
    Context process(const Context& request_body) const override;
};
*/

#include "HandlerMeetUpDefinition.hpp"
