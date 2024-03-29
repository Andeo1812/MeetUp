#pragma once  //  NOLINT

#include <string>
#include <set>

class Group {
    std::string id;
    std::string title;
    std::string description;
    std::set<std::string> members;
    std::string user_id;

 public:
    bool IsEmpty() const noexcept;

    void SetId(const std::string &group_id) noexcept;
    void SetTitle(const std::string &title) noexcept;
    void SetDescription(const std::string &description) noexcept;
    void SetMembers(const std::set<std::string> &members) noexcept;
    void SetUserId(const std::string &user_id) noexcept;

    std::string &GetId() noexcept;
    std::string &GetTitle() noexcept;
    std::string &GetDescription() noexcept;
    std::set<std::string> &GetMembers() noexcept;
    std::string &GetUserId() noexcept;

    const std::string &AccessId() const noexcept;
    const std::string &AccessTitle() const noexcept;
    const std::string &AccessDescription() const noexcept;
    const std::set<std::string> &AccessMembers() const noexcept;
    const std::string &AccessUserId() const noexcept;

    Group() = default;
    virtual ~Group() = default;

    bool operator<(const Group &group) const noexcept;

    bool operator==(const Group &group) const noexcept;

    friend std::ostream&  operator<<(std::ostream &os, const Group &it) noexcept;
};
