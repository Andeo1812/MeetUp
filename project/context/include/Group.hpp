#pragma once  //  NOLINT

#include <string>
#include <set>

class Group {
    std::string group_id;
    std::string title;
    std::string description;
    std::set<std::string> members;
    std::string user_id;

 public:
    bool IsEmpty() const noexcept;

    void SetGroupId(const std::string &group_id) noexcept;
    void SetTitle(const std::string &title) noexcept;
    void SetDescription(const std::string &description) noexcept;
    void SetMembers(const std::set<std::string> &members) noexcept;
    void SetUserId(const std::string &user_id) noexcept;

    std::string GetGroupId() const noexcept;
    std::string GetTitle() const noexcept;
    std::string GetDescription() const noexcept;
    std::set<std::string> GetMembers() const noexcept;
    std::string GetUserId() const noexcept;

    Group() = default;
    virtual ~Group() = default;

    bool operator<(const Group &group) const noexcept;

    friend void operator<<(std::ostream &os, const Group &it) noexcept;
};
