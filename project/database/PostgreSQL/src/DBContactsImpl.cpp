#include <iostream>

#include "DBContactsImpl.hpp"
#include "DBManagerPG.hpp"

int DBContactsImpl::Add(const std::string &user_id, const std::string &user_id_friend) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "INSERT INTO contacts (fk_user_id,fk_friend_id) "
                      "VALUES ('" + user_id + "','" + user_id_friend + "' ) ;";

    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_ADD_CONTACT;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_ADD_CONTACT;
    }

    if (res != SUCCESS) {
        Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

        return res;
    }

    SQL = "INSERT INTO contacts (fk_user_id,fk_friend_id) "
                      "VALUES ('" + user_id_friend + "','" + user_id + "' ) ;";

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_ADD_CONTACT;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_ADD_CONTACT;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

int DBContactsImpl::Rm(const std::string &user_id, const std::string &user_id_friend) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "DELETE FROM contacts WHERE fk_user_id = '" + user_id + "' and fk_friend_id = '" + user_id_friend + "'";


    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_RM_CONTACT;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_RM_CONTACT;
    }

    if (res != SUCCESS) {
        Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

        return res;
    }

    SQL = "DELETE FROM contacts WHERE fk_user_id = '" + user_id_friend + "' and fk_friend_id = '" + user_id + "'";

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_RM_CONTACT;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_RM_CONTACT;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

int DBContactsImpl::GetSet(const std::string &user_id, std::set<std::string> &contacts, const size_t count, const size_t page) const {
    return EXIT_SUCCESS;
}

