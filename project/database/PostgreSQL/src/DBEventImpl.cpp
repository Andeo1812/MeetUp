#include <iostream>

#include "DBEventImpl.hpp"
#include "DBManagerPG.hpp"

int DBEventImpl::Add(const Event &event, std::string &new_event_id) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "INSERT INTO event_m (event_name,event_date,time_begin,time_end,description,fk_user_id) "
                      "VALUES ('" + event.GetName() + "','"
                      + event.GetDate() + "','"
                      + event.GetTimeBegin() + "','"
                      + event.GetTimeEnd() + "','"
                      + event.GetDescription() + "','"
                      + event.GetUserId() + "' ) RETURNING event_id;";

    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            new_event_id = result.begin()["event_id"].as<std::string>();
        } else {
            res = NOT_ADD_EVENT;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_ADD_EVENT;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

int DBEventImpl::Write(const Event &event) const {
    return EXIT_SUCCESS;
}

int DBEventImpl::Rm(const Event &event) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "DELETE FROM event_m WHERE event_id = '" + event.GetId() + "'";

    int res = SUCCESS;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        if (!result.empty()) {
            res = NOT_RM_EVENT;
        }

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;

        res = ERROR_RM_EVENT;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return res;
}

int DBEventImpl::GetId(const Event &event, std::string &event_id) const {
    int res;
    return res;
}
