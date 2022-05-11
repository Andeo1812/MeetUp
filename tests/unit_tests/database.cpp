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

TEST(PostgreSQL, DBUser) {
    std::string password = {"TEST_DEV"};
    std::string nickname = {"TEST_DEV"};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(80,100);

    std::string random_add = std::to_string(dist(gen));

    password += random_add;
    nickname += random_add;

    User user;
    user.SetPassword(password);
    user.SetNickname(nickname);

    std::string new_user_id = Singleton<DBManagerPG>::GetInstance().GetData().User.Registration(user);
    user.SetId(new_user_id);

    EXPECT_TRUE(!new_user_id.empty());

    EXPECT_EQ(Singleton<DBManagerPG>::GetInstance().GetData().User.Authentication(user), SUCCESS);

    User user_not_exist;
    user_not_exist.SetPassword({"user_not_exist"});
    user_not_exist.SetNickname({"user_not_exist"});

    EXPECT_EQ(Singleton<DBManagerPG>::GetInstance().GetData().User.Authentication(user_not_exist), NOT_AUTHENTICATION);

    EXPECT_EQ(Singleton<DBManagerPG>::GetInstance().GetData().User.GetId(user), user.GetId());

    EXPECT_EQ(Singleton<DBManagerPG>::GetInstance().GetData().User.GetNickname(user), user.GetNickname());
}


TEST(PostgreSQL, DBUserData) {

}

TEST(PostgreSQL, DBEvent) {

}

TEST(PostgreSQL, DBContacts) {

}

TEST(PostgreSQL, DBGroup) {

}

TEST(PostgreSQL, DBSynchroClient) {

}
