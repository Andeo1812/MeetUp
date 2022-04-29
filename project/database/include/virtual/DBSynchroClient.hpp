#pragma once  //  NOLINT

#include <string>
#include <set>

#include "Event.hpp"
#include "Group.hpp"

class DBSynchroClient {
 public:
    virtual std::set<std::string> Contacts(const std::string &user_id, const size_t count) const = 0;

    virtual std::set<Event> Events(const std::string &user_id, const std::string &date) const = 0;

    virtual std::set<Group> Groups(const std::string &user_id, const size_t count) const = 0;

    virtual ~DBSynchroClient() = default;
};
