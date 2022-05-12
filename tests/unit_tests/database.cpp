#include <gtest/gtest.h>

#include <unistd.h>
#include <random>

#include "DBManagerPG.hpp"
#include "DBUserImpl.hpp"
#include "DBUserDataImpl.hpp"
#include "DBEventImpl.hpp"
#include "DBContactsImpl.hpp"
#include "DBGroupImpl.hpp"
#include "DBSynchroClientImpl.hpp"


TEST(PostgreSQL, DBManager) {
    Singleton<DBManagerPG>::GetInstance();

    const size_t numCPU = MAX_COUNT_FREE_DB_VERSION;

    //  const size_t numCPU = sysconf(_SC_NPROCESSORS_ONLN);

    EXPECT_EQ(Singleton<DBManagerPG>::GetInstance().GetData().Size(), numCPU);

    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    EXPECT_EQ(Singleton<DBManagerPG>::GetInstance().GetData().Size(), numCPU - 1);

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    EXPECT_EQ(Singleton<DBManagerPG>::GetInstance().GetData().Size(), numCPU);
}

std::string new_user_id;

TEST(PostgreSQL, DBUser) {
    std::string password = {"TEST_DEV100"};
    std::string nickname = {"TEST_DEV100"};

    User user;
    user.SetPassword(password);
    user.SetNickname(nickname);

    int res = Singleton<DBManagerPG>::GetInstance().GetData().User.Registration(user, new_user_id);
    user.SetId(new_user_id);

    EXPECT_EQ(res, SUCCESS);

    res = Singleton<DBManagerPG>::GetInstance().GetData().User.Authentication(user);

    EXPECT_EQ(res, SUCCESS);

    User user_not_exist;
    user_not_exist.SetPassword({"user_not_exist"});
    user_not_exist.SetNickname({"user_not_exist"});

    res = Singleton<DBManagerPG>::GetInstance().GetData().User.Authentication(user_not_exist);

    EXPECT_EQ(res, NOT_AUTHENTICATION);

    std::string user_id;

    res = Singleton<DBManagerPG>::GetInstance().GetData().User.GetId(user, user_id);

    EXPECT_EQ(res, SUCCESS);
    EXPECT_EQ(user_id, user.GetId());

    std::string get_nickname;

    res = Singleton<DBManagerPG>::GetInstance().GetData().User.GetNickname(user, get_nickname);

    EXPECT_EQ(res, SUCCESS);
    EXPECT_EQ(nickname, user.GetNickname());
}


TEST(PostgreSQL, DBUserData) {

}

TEST(PostgreSQL, DBEvent) {
    std::string event_date = {"2000.01.01"};
    std::string event_name = {"lunch"};
    std::string time_begin = {"14:00"};
    std::string time_end = {"15:01"};
    std::string description = {"Important"};

    Event event;
    event.SetName(event_name);
    event.SetDate(event_date);
    event.SetTimeBegin(time_begin);
    event.SetTimeEnd(time_end);
    event.SetDescription(description);
    event.SetUserId(new_user_id);

    std::string new_event_id;

    int res_add = Singleton<DBManagerPG>::GetInstance().GetData().Event.Add(event, new_event_id);
    event.SetId(new_event_id);

    EXPECT_TRUE(!new_event_id.empty());
    EXPECT_EQ(res_add, SUCCESS);

    int res_rm = Singleton<DBManagerPG>::GetInstance().GetData().Event.Rm(event);

    EXPECT_EQ(res_rm, SUCCESS);
}

TEST(PostgreSQL, DBContacts) {

}

TEST(PostgreSQL, DBGroup) {

}

TEST(PostgreSQL, DBSynchroClient) {

}

TEST(PostgreSQL, EndTesting) {
    User user;

    user.SetId(new_user_id);
    int res_rm = Singleton<DBManagerPG>::GetInstance().GetData().User.Rm(user);

    EXPECT_EQ(res_rm, SUCCESS);
}
