#pragma once  //  NOLINT

#include <string>
#include <set>

class Event {
    std::string event_id;
    std::string event_name;
    std::string date;
    std::string description;
    std::string time_begin;
    std::string time_end;
    std::string user_id;
public:
    bool IsEmpty();

    void SetEventId(const std::string &event_id);
    void SetEventName(const std::string &event_name);
    void SetDate(const std::string &date);
    void SetDescription(const std::string &description);
    void SetTimeBegin(const std::string &time_begin);
    void SetTimeEnd(const std::string &time_end);
    void SetUserId(const std::string &user_id);

    std::string GetEventId();
    std::string GetEventName();
    std::string GetDate();
    std::string GetDescription();
    std::string GetTimeBegin();
    std::string GetTimeEnd();
    std::string GetUserId();

    Event() = default;
    virtual ~Event() = default;

    bool operator<(const Event &other) const;

    void Print() const;
};
