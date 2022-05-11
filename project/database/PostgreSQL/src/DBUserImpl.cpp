#include <iostream>

#include "DBUserImpl.hpp"
#include "DBManagerPG.hpp"

std::string DBUserImpl::Registration(const User &user) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "INSERT INTO user_m (nickname,password) "
                      "VALUES ('" + user.GetNickname() + "','" + user.GetPassword() + "' ) RETURNING user_id;";

    std::string new_user_id;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        new_user_id = result.begin()["user_id"].as<std::string>();

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return new_user_id;
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
