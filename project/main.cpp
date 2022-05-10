#include <iostream>

#include "DBManagerPG.hpp"

int main(int argc, const char *argv[]) {
    std::cout << "Starting server..." << std::endl;

    DBManagerPG db_manager;

    std::string sql = "SELECT * FROM user_m";

    pqxx::connection &con = db_manager.GetFreeConnection()->GetConnection();

    pqxx::work w(con);

    pqxx::result R(w.exec(sql));

    for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
        std::cout << "ID = " << c[0].as<std::string>() << std::endl;
        std::cout << "Nickname = " << c[1].as<std::string>() << std::endl;
        std::cout << "Password = " << c[2].as<std::string>() << std::endl;
    }

    std::cout << con.is_open() << std::endl;

    return EXIT_SUCCESS;
}
