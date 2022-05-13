#pragma once  //  NOLINT

#include <iostream>

#include "DBGroupImpl.hpp"
#include "DBManager.hpp"

template<class ClassConnection>
int DBGroupImplDefinition<ClassConnection>::Create(const Group &group, std::string *group_id, ClassConnection *connection) const {
    std::string SQL = "INSERT INTO group_m (title,description) "
                      "VALUES ('" + group.GetTitle() + "','" + group.GetDescription() + "' ) RETURNING group_id;";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            *group_id = result.begin()["group_id"].as<std::string>();
        } else {
            res = NOT_CREATE_GROUP;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_CREATE_GROUP;
    }

    return res;
}

template<class ClassConnection>
int DBGroupImplDefinition<ClassConnection>::ReWrite(const Group &group, ClassConnection *connection) const {
    return EXIT_SUCCESS;
}

template<class ClassConnection>
int DBGroupImplDefinition<ClassConnection>::RmAllMembers(const std::string &group_id, ClassConnection *connection) const {
    std::string SQL = "DELETE FROM group_members WHERE fk_group_id = '" + group_id + "'";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_RM_GROUP_ALL_MEMBER;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_RM_GROUP_ALL_MEMBER;
    }

    return res;
}

template<class ClassConnection>
int DBGroupImplDefinition<ClassConnection>::Rm(const std::string &group_id, ClassConnection *connection) const {
    std::string SQL = "DELETE FROM group_m WHERE group_id = '" + group_id + "'";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_RM_GROUP;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_RM_GROUP;
    }

    return res;
}

template<class ClassConnection>
int DBGroupImplDefinition<ClassConnection>::GetMembers(const std::string &group_id, Group *group, ClassConnection *connection) const {
    Group res;
    return EXIT_SUCCESS;
}

template<class ClassConnection>
int DBGroupImplDefinition<ClassConnection>::AddMember(const std::string &user_id, const std::string &group_id, ClassConnection *connection) const {
    std::string SQL = "INSERT INTO group_members (fk_group_id,fk_user_id) "
          "VALUES ('" + group_id + "','" + user_id + "' );";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_ADD_GROUP_MEMBER;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_ADD_GROUP_MEMBER;
    }

    return res;
}

template<class ClassConnection>
int DBGroupImplDefinition<ClassConnection>::RmMember(const std::string &user_id, const std::string &group_id, ClassConnection *connection) const {
    std::string SQL = "DELETE FROM group_members WHERE fk_user_id = '" + user_id + "'";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_RM_GROUP_MEMBER;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_RM_GROUP_MEMBER;
    }

    return res;
}

template<class ClassConnection>
int DBGroupImplDefinition<ClassConnection>::GetId(const Group &group, std::string *group_id, ClassConnection *connection) const {
    std::string res;
    return EXIT_SUCCESS;
}

template<class ClassConnection>
int DBGroupImplDefinition<ClassConnection>::GetSet(const std::string &user_id, std::set<Group> *groups, const size_t &left, const size_t &right, ClassConnection *connection) const {
    return EXIT_SUCCESS;
}
