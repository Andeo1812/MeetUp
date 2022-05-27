#pragma once  //  NOLINT

#include <iostream>

#include "DBUserImpl.hpp"
#include "DBManager.hpp"

template<class ClassConnection>
int DBUserImpl<ClassConnection>::Registration(const User &user, std::string *new_user_id, ClassConnection *connection) const {
    std::string SQL = "INSERT INTO user_m (nickname,password) "
                      "VALUES ('" + user.AccessNickname() + "','" + user.AccessPassword() + "' ) RETURNING user_id;";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            *new_user_id = result.begin()["user_id"].as<std::string>();
        } else {
            res = NOT_REGISTRATION;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_REGISTRATION;
    }

    return res;
}

template<class ClassConnection>
int DBUserImpl<ClassConnection>::Authentication(const User &user, ClassConnection *connection) const {
    std::string SQL = "SELECT user_id FROM user_m WHERE password = '" + user.AccessPassword() + "' and nickname = '" + user.AccessNickname() + "'";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (result.empty()) {
            res = NOT_AUTHENTICATION;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_AUTHENTICATION;
    }

    return res;
}

template<class ClassConnection>
int DBUserImpl<ClassConnection>::GetId(const User &user, std::string *user_id, ClassConnection *connection) const {
    std::string SQL = "SELECT user_id FROM user_m WHERE  nickname = '" + user.AccessNickname() + "'";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            *user_id = result.begin()["user_id"].as<std::string>();
        } else {
            res = NOT_GET_USER_ID;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_GET_USER_ID;
    }

    return res;
}

template<class ClassConnection>
int DBUserImpl<ClassConnection>::GetNickname(const User &user, std::string *nickname, ClassConnection *connection) const {
    std::string SQL = "SELECT nickname FROM user_m WHERE user_id = '" + user.AccessId() + "'";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            *nickname = result.begin()["nickname"].as<std::string>();
        } else {
            res = NOT_GET_USER_NICKNAME;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_GET_USER_NICKNAME;
    }

    return res;
}

template<class ClassConnection>
int DBUserImpl<ClassConnection>::Rm(const User &user, ClassConnection *connection) const {
    std::string SQL = "DELETE FROM user_m WHERE user_id = '" + user.AccessId() + "'";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_RM_USER;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_RM_USER;
    }

    return res;
}
