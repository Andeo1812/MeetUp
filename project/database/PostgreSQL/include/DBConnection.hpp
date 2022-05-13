#pragma once  //  NOlINT

#include <string>
#include <memory>
#include <fstream>

const std::string path_config = {"project/configs/Database.txt"};

template<typename Connection>
class DBConnection {
    std::shared_ptr<Connection> connect;

    std::string LoadConfig(const std::string &path) const;

public:
    DBConnection();
    ~DBConnection();

    Connection& GetConnection();
};

#include "DBConnectionImpl.hpp"
