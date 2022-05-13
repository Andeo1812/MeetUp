#pragma once  //  NOLINT

#include <set>

#include "Event.hpp"

template<class ClassConnection>
class DBEvent {
 public:
    virtual int Add(const Event &event, std::string *new_event_id, ClassConnection *connection) const = 0;

    virtual int Write(const Event &event, ClassConnection *connection) const = 0;

    virtual int Rm(const Event &event, ClassConnection *connection) const = 0;

    virtual int GetId(const Event &event, std::string *event_id, ClassConnection *connection) const = 0;

    virtual int GetSet(const std::string &user_id, std::set<Event> *events, const std::string &date, ClassConnection *connection) const = 0;

    virtual ~DBEvent() = default;
};
