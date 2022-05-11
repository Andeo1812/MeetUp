#include "DBUserImpl.hpp"
#include "DBManagerPG.hpp"

#include <iostream>

int DBUserImpl::Registration(const User &user) const {
    std::cout << Singleton<DBManagerPG>::GetInstance().GetData().Size() << std::endl;

    auto &con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection()->GetConnection();

    std::string sql = "SELECT * FROM user_m";

    std::cout << Singleton<DBManagerPG>::GetInstance().GetData().Size() << std::endl;

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

int DBUserImpl::Authentication(const User &user) const {
    return EXIT_SUCCESS;
}

std::string DBUserImpl::GetId(const User &user) const {
    std::string res;
    return res;
}

std::string DBUserImpl::GetNickname(const User &user) const {
    std::string res;
    return res;
}
