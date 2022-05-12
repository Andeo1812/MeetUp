#include <iostream>

#include "DBEventImpl.hpp"
#include "DBManagerPG.hpp"

std::string DBEventImpl::Add(const Event &event) const {
    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    std::string SQL = "INSERT INTO event_m (event_name,event_date,time_begin,time_end,description,fk_user_id) "
                      "VALUES ('" + event.GetName() + "','"
                      + event.GetDate() + "','"
                      + event.GetTimeBegin() + "','"
                      + event.GetTimeEnd() + "','"
                      + event.GetDescription() + "','"
                      + event.GetUserId() + "' ) RETURNING event_id;";

    std::string new_event_id;

    try {
        pqxx::work work(con->GetConnection());

        pqxx::result result(work.exec(SQL));

        new_event_id = result.begin()["event_id"].as<std::string>();

        work.commit();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    return new_event_id;
}

int DBEventImpl::Write(const Event &event) const {
    return EXIT_SUCCESS;
}

int DBEventImpl::Rm(const Event &event) const {
    return EXIT_SUCCESS;
}

std::string DBEventImpl::GetId(const Event &event) const {
    std::string res;
    return res;
}
