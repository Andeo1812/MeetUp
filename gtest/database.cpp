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


TEST(PostgreSQL, RegAuth) {
    std::string input_reg = {"{\"registration\":{\"nickname\":\"Sasha\",\"password\":\"123456asd64569898989\"}}"};
    std::string key_nickname = {"Sasha"};
    std::string key_password = {"123456asd64569898989"};

    ParserRegAuth parser;

    Context context;

    User user;

    context = user;

    context = parser.StrToObject(input);

    EXPECT_TRUE(key_nickname == context.GetPassword());
    EXPECT_TRUE(key_nickname == context.GetNickname());
}

TEST(PostgreSQL, GetId) {
//  По аналогии с RegAuth
}

TEST(PostgreSQL, GetField) {
//  По аналогии с RegAuth
}

TEST(PostgreSQL, Data) {
//  По аналогии с RegAuth
}

TEST(PostgreSQL, PrivateData) {
//  По аналогии с RegAuth
}

TEST(PostgreSQL, Event) {
//  По аналогии с RegAuth
}

TEST(PostgreSQL, Contact) {
//  По аналогии с RegAuth
}

TEST(PostgreSQL, Group) {
//  По аналогии с RegAuth
}

TEST(PostgreSQL, Synchro) {
//  По аналогии с RegAuth
}
