#include <gtest/gtest.h>

#include "RegAuthImpl.hpp"
#include "GetIdImpl.hpp"
#include "GetFieldImpl.hpp"
#include "DataImpl.hpp"
#include "PrivateDataImpl.hpp"
#include "EventImpl.hpp"
#include "ContactImpl.hpp"
#include "GroupImpl.hpp"
#include "SynchroImpl.hpp"


TEST(PostgreSQL, Connection) {
    PGConnection pg_con;

    EXPECT_TRUE(pg_con != nullptr);
}

TEST(PostgreSQL, GetField) {
    DBRegAuthImpl reg_auth_db;

    EXPECT_TRUE(reg_auth_db);

    std::string user_id = {"123"};
    std::string password = {"GogozikPARSSS"};
    std::string nickname = {"Gogozik"};

    User user;

    user.SetUserId(user_id);
    user.SetPassword(password);
    user.SetNickname(nickname);

    EXPECT_TRUE(!reg_auth_db.Registration(user));
    EXPECT_TRUE(!reg_auth_db.Authentication(user));
}


TEST(PostgreSQL, DBUserData) {
//  По аналогии с GetField
}

TEST(PostgreSQL, DBRegAuth) {
//  По аналогии с GetField
}

TEST(PostgreSQL, DBEvent) {
//  По аналогии с GetField
}

TEST(PostgreSQL, DBContacts) {
//  По аналогии с GetField
}

TEST(PostgreSQL, DBGroup) {
//  По аналогии с GetField
}

TEST(PostgreSQL, DBSynchroClient) {
//  По аналогии с GetField
}
