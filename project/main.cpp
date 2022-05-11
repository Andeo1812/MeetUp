#include <iostream>

#include "DBManagerPG.hpp"

DBManagerPG db_manager;

int main(int argc, const char *argv[]) {
    std::cout << "Starting server..." << std::endl;

    std::cout << db_manager.Size() << std::endl;

    std::string sql = "SELECT * FROM user_m";

    auto &con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection()->GetConnection();

    std::cout << db_manager.Size() << std::endl;

    pqxx::work w(con);

    pqxx::result R(w.exec(sql));

    for (auto row : R) {
        std::cout << "ID = " << row[0].as<std::string>() << std::endl;
        std::cout << "Nickname = " << row[1].as<std::string>() << std::endl;
        std::cout << "Password = " << row[2].as<std::string>() << std::endl;
    }

    std::cout << con.is_open() << std::endl;

    return EXIT_SUCCESS;
}
