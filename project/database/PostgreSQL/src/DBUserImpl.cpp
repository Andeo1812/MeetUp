#include <iostream>

#include "DBUserImpl.hpp"
#include "DBManagerPG.hpp"

int DBUserImpl::Registration(const User &user, std::string &new_user_id) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "INSERT INTO user_m (nickname,password) "
                      "VALUES ('" + user.GetNickname() + "','" + user.GetPassword() + "' ) RETURNING user_id;";

    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            new_user_id = result.begin()["user_id"].as<std::string>();
        } else {
            res = NOT_REGISTRATION;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_REGISTRATION;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

int DBUserImpl::Authentication(const User &user) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "SELECT user_id FROM user_m WHERE password = '" + user.GetPassword() + "' and nickname = '" + user.GetNickname() + "'";

    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (result.empty()) {
            res = NOT_AUTHENTICATION;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_AUTHENTICATION;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

int DBUserImpl::GetId(const User &user, std::string &user_id) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "SELECT user_id FROM user_m WHERE password = '" + user.GetPassword() + "' and nickname = '" + user.GetNickname() + "'";

    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            user_id = result.begin()["user_id"].as<std::string>();
        } else {
            res = NOT_GET_USER_ID;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_GET_USER_ID
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

int DBUserImpl::GetNickname(const User &user, std::string &nickname) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "SELECT nickname FROM user_m WHERE user_id = '" + user.GetId() + "'";

    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            nickname = result.begin()["nickname"].as<std::string>();
        } else {
            res = NOT_GET_USER_NICKNAME;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_GET_USER_NICKNAME;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

int DBUserImpl::Rm(const User &user) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "DELETE FROM user_m WHERE user_id = '" + user.GetId() + "'";

    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (result.empty()) {
            res = NOT_DELETE_USER;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_DELETE_USER;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}
