#pragma once  //  NOLINT

#include "Event.hpp"

class DBEvent {
 public:
    virtual int Add(const Event& event) const = 0;

    virtual int Write(const Event& event) const = 0;

    virtual int Rm(const Event& event) const = 0;

    virtual std::string GetId(const Event& event) const = 0;

    virtual ~DBEvent() = default;
};
