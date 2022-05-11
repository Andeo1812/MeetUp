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
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "SELECT user_id FROM user_m WHERE password = '" + user.GetPassword() + "' and nickname = '" + user.GetNickname() + "'";

    int res = 0;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (result.empty()) {
            res = NOT_AUTHENTICATION;
        } else {
            res = SUCCESS;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_AUTHENTICATION;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

std::string DBUserImpl::GetId(const User &user) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "SELECT user_id FROM user_m WHERE password = '" + user.GetPassword() + "' and nickname = '" + user.GetNickname() + "'";

    std::string user_id;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            user_id = result.begin()["user_id"].as<std::string>();
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return user_id;
}

std::string DBUserImpl::GetNickname(const User &user) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "SELECT nickname FROM user_m WHERE user_id = '" + user.GetId() + "'";

    std::string nickname;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            nickname = result.begin()["nickname"].as<std::string>();
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return nickname;
}
