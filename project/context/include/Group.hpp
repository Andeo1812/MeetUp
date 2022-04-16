#pragma once  //  NOLINT

#include <string>
#include <set>

class Group {
    std::string group_id;
    std::string title;
    std::string description;
    std::set<std::string> members;
public:
    bool IsEmpty();

    void SetGroupId(const std::string &group_id);
    void SetTitle(const std::string &title);
    void SetDescription(const std::string &description);
    void SetMembers(const std::set<std::string> &members);

    std::string SetGroupId() const;
    std::string SetTitle() const;
    std::string SetDescription() const;
    std::set<std::string> SetMembers() const;

    Group() = default;
    virtual ~Group() = default;

    bool operator<(const Group &group) const;

    void Print() const;
};
