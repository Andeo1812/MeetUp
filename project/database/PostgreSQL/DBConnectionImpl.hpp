#pragma once  //  NOLINT

#include "DBConnection.hpp"

template<typename Connection>
std::string DBConnection<Connection>::LoadConfig(const std::string &path) const {
    std::string config;

    std::ifstream in(path);
    if (in.is_open()) {
        getline(in, config);
    }

    in.close();

    return config;
}

template<typename Connection>
DBConnection<Connection>::DBConnection() {
    this->connect = std::make_unique<Connection>(LoadConfig(path_config));
}

template<typename Connection>
DBConnection<Connection>::~DBConnection() {
    GetConnection().close();
}

template<typename Connection>
Connection &DBConnection<Connection>::GetConnection() {
    return this->connect.operator*();
}

