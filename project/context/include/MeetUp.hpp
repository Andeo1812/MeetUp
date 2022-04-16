#pragma once  //  NOLINT

#include <string>
#include <set>

class MeetUp {
    std::string meetup_id;
    std::string meetup_name;
    std::string date;
    std::string description;
    std::string time_begin;
    std::string time_end;
    std::string group_id;
public:
    bool IsEmpty();

    void SetMeetUpId(const std::string &meetup_id);
    void SetMeetUpName(const std::string &meetup_name);
    void SetDate(const std::string &date);
    void SetDescription(const std::string &description);
    void SetTimeBegin(const std::string &time_begin);
    void SetTimeEnd(const std::string &time_end);
    void SetUserId(const std::string &user_id);

    std::string GetMeetUpId();
    std::string GetMeetUpName();
    std::string GetDate();
    std::string GetDescription();
    std::string GetTimeBegin();
    std::string GetTimeEnd();
    std::string GetUserId();

    MeetUp() = default;
    virtual ~MeetUp() = default;

    bool operator<(const MeetUp &other) const;

    void Print() const;
};
