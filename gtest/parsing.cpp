#include <gtest/gtest.h>

#include "ParserUser.hpp"
#include "ParserAddressData.hpp"
#include "ParserPersonalData.hpp"
#include "ParserGeneralData.hpp"
#include "ParserEvent.hpp"
#include "ParserContacts.hpp"
#include "ParserGroup.hpp"
#include "ParserMeetUp.hpp"


TEST(PARSING, RegAuth) {
    std::string input_reg = {"{\"registration\":{\"nickname\":\"Sasha\",\"password\":\"123456asd64569898989\"}}"};
    std::string key_nickname = {"Sasha"};
    std::string key_password = {"123456asd64569898989"};

    ParserRegAuth parser;

    Context context;

    User user;

    context = user;

    context = parser.StrToObject(input_reg);

    EXPECT_TRUE(key_nickname == context.user.GetPassword());
    EXPECT_TRUE(key_nickname == context.user.GetNickname());
}

TEST(PARSING, Address) {
//  По аналогии с RegAuth
}

TEST(PARSING, PersonalData) {
//  По аналогии с RegAuth
}

TEST(PARSING, GeneralData) {
//  По аналогии с RegAuth
}

TEST(PARSING, PrivateData) {
//  По аналогии с RegAuth
}

TEST(PARSING, Events) {
//  По аналогии с RegAuth
}

TEST(PARSING, UserContacts) {
//  По аналогии с RegAuth
}

TEST(PARSING, Groups) {
//  По аналогии с RegAuth
}

TEST(PARSING, MeetUps) {
//  По аналогии с RegAuth
}
