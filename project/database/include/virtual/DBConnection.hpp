#pragma once  //  NOLINT

#include <string>

class DBConnection {
public:
    virtual int LoadConfig(const std::string& path) const = 0;

    virtual ~DBConnection() =default;
};
