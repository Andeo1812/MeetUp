#pragma once  //  NOLINT

#include <iostream>

#include "DBManager.hpp"
#include "DBContactsImpl.hpp"

template<class ClassConnection>
int DBContactsImpl<ClassConnection>::Add(const std::string &user_id, const std::string &user_id_contact, ClassConnection *connection) const {
    std::string SQL = "INSERT INTO contacts (fk_user_id,fk_contact_id) "
                      "VALUES ('" + user_id + "','" + user_id_contact + "' ) ;";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_ADD_CONTACT;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_ADD_CONTACT;
    }

    if (res != EXIT_SUCCESS) {
        return res;
    }

    SQL = "INSERT INTO contacts (fk_user_id,fk_contact_id) "
                      "VALUES ('" + user_id_contact + "','" + user_id + "' ) ;";

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_ADD_CONTACT;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_ADD_CONTACT;
    }

    return res;
}

template<class ClassConnection>
int DBContactsImpl<ClassConnection>::Rm(const std::string &user_id, const std::string &user_id_contact, ClassConnection *connection) const {
    std::string SQL = "DELETE FROM contacts WHERE fk_user_id = '" + user_id + "' and fk_contact_id = '" + user_id_contact + "'";


    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_RM_CONTACT;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_RM_CONTACT;
    }

    if (res != EXIT_SUCCESS) {
        return res;
    }

    SQL = "DELETE FROM contacts WHERE fk_user_id = '" + user_id_contact + "' and fk_contact_id = '" + user_id + "'";

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_RM_CONTACT;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_RM_CONTACT;
    }

    return res;
}

template<class ClassConnection>
int DBContactsImpl<ClassConnection>::GetSet(const std::string &user_id, std::set<std::string> *contacts, const size_t &left, const size_t &right, ClassConnection *connection) const {
    std::string SQL = "SELECT fk_contact_id FROM contacts WHERE fk_user_id = " + user_id + " ORDER BY fk_contact_id DESC OFFSET " + std::to_string(left) + " ROWS FETCH NEXT " + std::to_string(right - left) + " ROWS ONLY";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            for (auto row : result) {
                contacts->insert(row["fk_contact_id"].as<std::string>());
            }
        } else {
            res = NOT_GET_SET_CONTACT;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_GET_SET_CONTACT;
    }

    return res;
}
