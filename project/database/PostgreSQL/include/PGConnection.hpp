#pragma once  //  NOlINT

#include <string>
#include <memory>
#include <fstream>

#include <pqxx/pqxx>

#include "DBConnection.hpp"

const std::string path_config = {"project/configs/Database.txt"};

class PGConnection : public DBConnection {
    std::shared_ptr<pqxx::connection> connect;

    std::string LoadConfig(const std::string &path) const override;

public:
    PGConnection();
    ~PGConnection() = default;

    std::shared_ptr<pqxx::connection> GetConnection();

    void CloseConnection();
};

std::string PGConnection::LoadConfig(const std::string &path) const {
    std::string config;

    std::ifstream in(path);
    if (in.is_open()) {
        getline(in, config);
    }

    in.close();

    return config;
}

PGConnection::PGConnection() {
    this->connect = std::make_shared<pqxx::connection>(LoadConfig(path_config));
}

std::shared_ptr<pqxx::connection> PGConnection::GetConnection() {
    return this->connect;
}
