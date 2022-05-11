#include "PGConnection.hpp"

#include "iostream"

std::string PGConnection::LoadConfig(const std::string &path) const {
    std::string config;

    std::ifstream in(path);
    if (in.is_open()) {
        getline(in, config);
    }

    std::cout << path << std::endl;

    in.close();

    return config;
}

PGConnection::PGConnection() {
    this->connect = std::make_shared<pqxx::connection>(LoadConfig(path_config));
}

PGConnection::~PGConnection() {
    GetConnection().close();
}

pqxx::connection &PGConnection::GetConnection() {
    return this->connect.operator*();
}
