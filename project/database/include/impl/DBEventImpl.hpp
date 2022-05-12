#pragma once  //  NOLINT

#include "DBEvent.hpp"

class DBEventImpl : public DBEvent {
 public:
    int Add(const Event &event, std::string &new_event_id) const override;

    int Write(const Event &event) const override;

    int Rm(const Event &event) const override;

    int GetId(const Event &event, std::string &event_id) const override;

    DBEventImpl() = default;
    ~DBEventImpl() = default;
};
