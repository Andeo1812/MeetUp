#pragma once  //  NOLINT

#include <string>
#include <set>

#include "Time.hpp"

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

    std::string &GetId() noexcept;
    std::string &GetName() noexcept;
    std::string &GetDate() noexcept;
    std::string &GetDescription() noexcept;
    std::string &GetTimeBegin() noexcept;
    std::string &GetTimeEnd() noexcept;
    std::string &GetUserId() noexcept;

    const std::string &AccessId() const noexcept;
    const std::string &AccessName() const noexcept;
    const std::string &AccessDate() const noexcept;
    const std::string &AccessDescription() const noexcept;
    const std::string &AccessTimeBegin() const noexcept;
    const std::string &AccessTimeEnd() const noexcept;
    const std::string &AccessUserId() const noexcept;

    Event() = default;
    virtual ~Event() = default;

    bool operator<(const Event &other) const noexcept;

    bool operator==(const Event &other) const noexcept;

    friend std::ostream& operator<<(std::ostream &os, const Event &it) noexcept;
};
