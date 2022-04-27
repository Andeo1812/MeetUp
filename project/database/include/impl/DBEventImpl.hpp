#pragma once  //  NOLINT

#include "DBEvent.hpp"

class DBEventImpl: public DBEvent {
public:
    int Add(const Event& event) const override;

    int Write(const Event& event) const override;

    int Rm(const Event& event) const override;

    std::string GetId(const Event& event) const override;

    ~DBEventImpl() = default;
};
