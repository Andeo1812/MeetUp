#pragma once  //  NOLINT

#include <string>
#include <set>

class Event {
    std::string id;
    std::string name;
    std::string date;
    std::string description;
    std::string time_begin;
    std::string time_end;
    std::string user_id;

 public:
    bool IsEmpty() const noexcept;

    void SetId(const std::string &id) noexcept;
    void SetName(const std::string &name) noexcept;
    void SetDate(const std::string &date) noexcept;
    void SetDescription(const std::string &description) noexcept;
    void SetTimeBegin(const std::string &time_begin) noexcept;
    void SetTimeEnd(const std::string &time_end) noexcept;
    void SetUserId(const std::string &user_id) noexcept;

    std::string GetId() const noexcept;
    std::string GetName() const noexcept;
    std::string GetDate() const noexcept;
    std::string GetDescription() const noexcept;
    std::string GetTimeBegin() const noexcept;
    std::string GetTimeEnd() const noexcept;
    std::string GetUserId() const noexcept;

    Event() = default;
    virtual ~Event() = default;

    bool operator<(const Event &other) const noexcept;

    friend void operator<<(std::ostream &os, const Event &it) noexcept;
};
