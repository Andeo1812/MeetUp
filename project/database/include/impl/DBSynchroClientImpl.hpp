#pragma once  //  NOLINT

#include "DBSynchroClient.hpp"

class DBSynchroClientImpl: public DBSynchroClient {
 public:
    std::set<std::string> Contacts(const std::string& user_id, const size_t count) const override;

    std::set<Event> Events(const std::string& user_id, const std::string& date) const override;

    std::set<Group> Groups(const std::string& user_id, const size_t count) const override;

    ~DBSynchroClientImpl() = default;
};
