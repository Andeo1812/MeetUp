#include <iostream>

#include "DBGroupImpl.hpp"
#include "DBManagerPG.hpp"

int DBGroupImpl::Create(const Group &group, std::string &group_id) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "INSERT INTO group_m (title,description) "
                      "VALUES ('" + group.GetTitle() + "','" + group.GetDescription() + "' ) RETURNING group_id;";

    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            group_id = result.begin()["group_id"].as<std::string>();
        } else {
            res = NOT_CREATE_GROUP;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_CREATE_GROUP;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

int DBGroupImpl::ReWrite(const Group &group) const {
    return EXIT_SUCCESS;
}

int DBGroupImpl::RmAllMembers(const std::string &group_id) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "DELETE FROM group_members WHERE fk_group_id = '" + group_id + "'";

    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_RM_GROUP_ALL_MEMBER;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_RM_GROUP_ALL_MEMBER;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

int DBGroupImpl::Rm(const std::string &group_id) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "DELETE FROM group_m WHERE group_id = '" + group_id + "'";

    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_RM_GROUP;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_RM_GROUP;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

int DBGroupImpl::GetMembers(const std::string &group_id, Group &group) const {
    Group res;
    return EXIT_SUCCESS;
}

int DBGroupImpl::AddMember(const User &user, const std::string &group_id) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string user_id;

    if (!user.GetId().empty()) {
        user_id = user.GetId();
    } else {
        std::string user_id;

        Singleton<DBManagerPG>::GetInstance().GetData().User.GetId(user, user_id);
    }

    std::string SQL = "INSERT INTO group_members (fk_group_id,fk_user_id) "
          "VALUES ('" + group_id + "','" + user_id + "' );";

    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_ADD_GROUP_MEMBER;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_ADD_GROUP_MEMBER;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

int DBGroupImpl::RmMember(const User &user, const std::string &group_id) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string user_id;

    if (!user.GetId().empty()) {
        user_id = user.GetId();
    } else {
        std::string user_id;

        Singleton<DBManagerPG>::GetInstance().GetData().User.GetId(user, user_id);
    }

    std::string SQL = "DELETE FROM group_members WHERE fk_user_id = '" + user_id + "'";

    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_RM_GROUP_MEMBER;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_RM_GROUP_MEMBER;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

int DBGroupImpl::GetId(const Group &group, std::string &group_id) const {
    std::string res;
    return EXIT_SUCCESS;
}

int DBGroupImpl::GetSet(const std::string &user_id, std::set<Group> &groups, const size_t count, const size_t page) const {
    return EXIT_SUCCESS;
}
