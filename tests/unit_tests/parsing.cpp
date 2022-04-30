#include <gtest/gtest.h>

#include "ParserUser.hpp"
#include "ParserAddressData.hpp"
#include "ParserPersonalData.hpp"
#include "ParserGeneralData.hpp"
#include "ParserContacts.hpp"
#include "ParserGroup.hpp"
#include "ParserMeetUp.hpp"


TEST(PARSING, User) {
    std::string input = {"{\"registration\":{\"nickname\":\"Sasha\",\"password\":\"123456asd64569898989\"}}"};
    std::string type_request = {"registration"};
    std::string key_nickname = {"Sasha"};
    std::string key_password = {"123456asd64569898989"};

    ParserUser parser;

    Context context;

    User user;

    context = user;

    context = parser.StrToObject(input);

    EXPECT_EQ(key_nickname, context.GetUser().GetNickname());
    EXPECT_EQ(key_password, context.GetUser().GetPassword());

    std::string response = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(input, response);
}

TEST(PARSING, AddressData) {
    std::string input = {"{\"write_address\":{\"user_id\":\"1\", \"building\":\"2\", \"housing\":\"3\", \"street\":\"Bolshaya Voskresenskaya\",\"city\":\"Krasnogorsk\",\"district\":\"Krasnogorskiy\",\"index\":\"143430\", \"country\":\"Russia\"}}"};
    std::string type_request = {"write_address"};
    std::string user_id = {"1"};
    std::string building = {"2"};
    std::string housing = {"3"};
    std::string street = {"Bolshaya Voskresenskaya"};
    std::string city = {"Krasnogorsk"};
    std::string district = {"Krasnogorskiy"};
    std::string index = {"143430"};
    std::string country = {"Russia"};

    ParserAddressData parser;

    Context context;

    AddressData address_data;

    context = address_data;

    context = parser.StrToObject(input);

    EXPECT_EQ(user_id, context.GetAddressData().GetUserId());
    EXPECT_EQ(building, context.GetAddressData().GetBuilding());
    EXPECT_EQ(housing, context.GetAddressData().GetHousing());
    EXPECT_EQ(street, context.GetAddressData().GetStreet());
    EXPECT_EQ(city, context.GetAddressData().GetCity());
    EXPECT_EQ(district, context.GetAddressData().GetDistrict());
    EXPECT_EQ(index, context.GetAddressData().GetIndex());
    EXPECT_EQ(country, context.GetAddressData().GetCountry());

    std::string response = parser.ObjectToStr(type_request, context);

    std::string expected_response_ok = {"{\"write_address\":\"OK\"}"};

    EXPECT_EQ(response, expected_response_ok);

    context.SetError("Test error");

    std::string expected_response_error = {"{\"write_address\":\"Test error\"}"};

    std::string response_error = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response_error, expected_response_error);
}

TEST(PARSING, PersonalData) {
    std::string input = {"{\"write_address\":{\"user_id\":\"1\", \"building\":\"2\", \"housing\":\"3\", \"street\":\"Bolshaya Voskresenskaya\",\"city\":\"Krasnogorsk\",\"district\":\"Krasnogorskiy\",\"index\":\"143430\", \"country\":\"Russia\"}}"};
    std::string type_request = {"write_address"};
    std::string user_id = {"1"};
    std::string building = {"2"};
    std::string housing = {"3"};
    std::string street = {"Bolshaya Voskresenskaya"};
    std::string city = {"Krasnogorsk"};
    std::string district = {"Krasnogorskiy"};
    std::string index = {"143430"};
    std::string country = {"Russia"};

    ParserPersonalData parser;

    Context context;

    PersonalData personal_data;

    context = personal_data;

    context = parser.StrToObject(input);

    EXPECT_EQ(user_id, context.GetAddressData().GetUserId());
    EXPECT_EQ(building, context.GetAddressData().GetBuilding());
    EXPECT_EQ(housing, context.GetAddressData().GetHousing());
    EXPECT_EQ(street, context.GetAddressData().GetStreet());
    EXPECT_EQ(city, context.GetAddressData().GetCity());
    EXPECT_EQ(district, context.GetAddressData().GetDistrict());
    EXPECT_EQ(index, context.GetAddressData().GetIndex());
    EXPECT_EQ(country, context.GetAddressData().GetCountry());

    std::string response = parser.ObjectToStr(type_request, context);

    std::string expected_response_ok = {"{\"write_address\":\"OK\"}"};

    EXPECT_EQ(response, expected_response_ok);

    context.SetError("Test error");

    std::string expected_response_error = {"{\"write_address\":\"Test error\"}"};

    std::string response_error = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response_error, expected_response_error);
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
