#include <iostream>

#include "PGConnection.hpp"

int main(int argc, const char *argv[]) {
    std::cout << "Starting server..." << std::endl;

    PGConnection coon;

    std::string sql = "SELECT * FROM user_m";

    pqxx::work w(coon.GetConnection().operator*());

    pqxx::result R(w.exec(sql));

    for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
        std::cout << "ID = " << c[0].as<std::string>() << std::endl;
        std::cout << "Nickname = " << c[1].as<std::string>() << std::endl;
        std::cout << "Password = " << c[2].as<std::string>() << std::endl;
    }

    std::cout << coon.GetConnection().operator*().is_open() << std::endl;

    return EXIT_SUCCESS;
}
