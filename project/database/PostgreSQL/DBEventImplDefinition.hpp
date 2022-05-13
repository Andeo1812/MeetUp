#pragma once  //  NOLINT

#include <iostream>

#include "DBEventImpl.hpp"
#include "DBManager.hpp"

template<class ClassConnection>
int DBEventImpl<ClassConnection>::Add(const Event &event, std::string *new_event_id, ClassConnection *connection) const {
    std::string SQL = "INSERT INTO event (event_name,event_date,time_begin,time_end,description,fk_user_id) "
                      "VALUES ('" + event.GetName() + "','"
                      + event.GetDate() + "','"
                      + event.GetTimeBegin() + "','"
                      + event.GetTimeEnd() + "','"
                      + event.GetDescription() + "','"
                      + event.GetUserId() + "' ) RETURNING event_id;";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            *new_event_id = result.begin()["event_id"].as<std::string>();
        } else {
            res = NOT_ADD_EVENT;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_ADD_EVENT;
    }

    return res;
}

template<class ClassConnection>
int DBEventImpl<ClassConnection>::Write(const Event &event, ClassConnection *connection) const {
    return EXIT_SUCCESS;
}

template<class ClassConnection>
int DBEventImpl<ClassConnection>::Rm(const Event &event, ClassConnection *connection) const {
    std::string SQL = "DELETE FROM event WHERE event_id = '" + event.GetId() + "'";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_RM_EVENT;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_RM_EVENT;
    }

    return res;
}

template<class ClassConnection>
int DBEventImpl<ClassConnection>::GetId(const Event &event, std::string *event_id, ClassConnection *connection)  const {
    int res;
    return res;
}

template<class ClassConnection>
int DBEventImpl<ClassConnection>::GetSet(const std::string &user_id, std::set<Event> *events, const std::string &date, ClassConnection *connection) const {
    std::string SQL = "SELECT * FROM event WHERE event_date = '" + date + "' ORDER BY DESK time_begin";

    int res = EXIT_SUCCESS;

    try {
        pqxx::work work(connection->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            for (auto row : result) {
                Event event;

                event.SetId(row["event_id"].as<std::string>());
                event.SetName(row["event_name"].as<std::string>());
                event.SetTimeBegin(row["time_begin"].as<std::string>());
                event.SetTimeEnd(row["time_end"].as<std::string>());
                event.SetDescription(row["description"].as<std::string>());

                events->insert(event);
            }
        } else {
            res = NOT_GET_SET_EVENTS;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_GET_SET_EVENTS;
    }

    return res;
}
