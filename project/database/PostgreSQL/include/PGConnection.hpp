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
    ~PGConnection();

    pqxx::connection &GetConnection();
};
