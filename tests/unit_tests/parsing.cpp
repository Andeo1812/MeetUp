#include <gtest/gtest.h>

#include "ParserUser.hpp"
#include "ParserAddressData.hpp"
#include "ParserPersonalData.hpp"
#include "ParserGeneralData.hpp"
#include "ParserEvent.hpp"
#include "ParserContacts.hpp"
#include "ParserGroup.hpp"
#include "ParserMeetUp.hpp"


TEST(PARSING, User) {
    std::string input = {"{\"registration\":{\"nickname\":\"Sasha\",\"password\":\"123456asd64569898989\"}}"};
    std::string type_request = {"registration"};

    ParserUser parser;

    Context context;

    context = parser.StrToObject(input);

    EXPECT_EQ("Sasha", context.GetUser().GetNickname());
    EXPECT_EQ("123456asd64569898989", context.GetUser().GetPassword());

    std::string response = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(input, response);

    context.SetError("Test error");

    std::string expected_response_error = {"{\"registration\":\"Test error\"}"};

    std::string response_error = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response_error, expected_response_error);
}

TEST(PARSING, AddressData) {
    std::string input = {"{\"write_address\":{\"user_id\":\"1\", "
                         "\"building\":\"2\", "
                         "\"housing\":\"3\", "
                         "\"street\":\"Bolshaya Voskresenskaya\", "
                         "\"city\":\"Krasnogorsk\", "
                         "\"district\": \"Krasnogorskiy\", "
                         "\"index\":\"143430\", "
                         "\"country\":\"Russia\"}}"};
    std::string type_request = {"write_address"};

    ParserAddressData parser;

    Context context;

    context = parser.StrToObject(input);

    EXPECT_EQ("1", context.GetAddressData().GetUserId());
    EXPECT_EQ("2", context.GetAddressData().GetBuilding());
    EXPECT_EQ("3", context.GetAddressData().GetHousing());
    EXPECT_EQ("Bolshaya Voskresenskaya", context.GetAddressData().GetStreet());
    EXPECT_EQ("Krasnogorsk", context.GetAddressData().GetCity());
    EXPECT_EQ("Krasnogorskiy", context.GetAddressData().GetDistrict());
    EXPECT_EQ("143430", context.GetAddressData().GetIndex());
    EXPECT_EQ("Russia", context.GetAddressData().GetCountry());

    std::string response = parser.ObjectToStr(type_request, context);

    std::string expected_response_ok = {"{\"write_address\":\"OK\"}"};

    EXPECT_EQ(response, expected_response_ok);

    context.SetError("Test error");

    std::string expected_response_error = {"{\"write_address\":\"Test error\"}"};

    std::string response_error = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response_error, expected_response_error);
}

TEST(PARSING, PersonalData) {
    std::string input = {"{\"write_personal\":{\"user_id\":\"8\", "
                         "\"name\":\"Bogdan\", "
                         "\"surname\":\"Kazimirov\", "
                         "\"date_birth\":\"2000-01-01\", "
                         "\"phone_number\":\"+79017453550\", "
                         "\"email\":\"bs@mt11.su\"}}"};
    std::string type_request = {"write_personal"};

    ParserPersonalData parser;

    Context context;

    context = parser.StrToObject(input);

    EXPECT_EQ("8", context.GetPersonalData().GetUserId());
    EXPECT_EQ("Bogdan", context.GetPersonalData().GetName());
    EXPECT_EQ("Kazimirov", context.GetPersonalData().GetSurname());
    EXPECT_EQ("bs@mt11.su", context.GetPersonalData().GetEmail());
    EXPECT_EQ("2000-01-01", context.GetPersonalData().GetDateBirth());
    EXPECT_EQ("+79017453550", context.GetPersonalData().GetPhoneNumber());

    std::string response = parser.ObjectToStr(type_request, context);

    std::string expected_response_ok = {"{\"write_personal\":\"OK\"}"};

    EXPECT_EQ(response, expected_response_ok);

    context.SetError("Test error");

    std::string expected_response_error = {"{\"write_personal\":\"Test error\"}"};

    std::string response_error = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response_error, expected_response_error);
}

TEST(PARSING, GeneralData) {
    std::string input = {"{\"write_general\":{\"user_id\":\"8\", "
                         "\"status\":\"asdas\", "
                         "\"tags\":\"1asd\", "
                         "\"description\":\"MT11-72\", "
                         "\"nickname\":\"asdasd\"}}"};
    std::string type_request = {"write_general"};

    ParserGeneralData parser;

    Context context;

    context = parser.StrToObject(input);

    EXPECT_EQ("8", context.GetGeneralData().GetUserId());
    EXPECT_EQ("asdas", context.GetGeneralData().GetStatus());
    EXPECT_EQ("1asd", context.GetGeneralData().GetTags());
    EXPECT_EQ("MT11-72", context.GetGeneralData().GetDescription());
    EXPECT_EQ("asdasd", context.GetGeneralData().GetNickname());

    std::string response = parser.ObjectToStr(type_request, context);

    std::string expected_response_ok = {"{\"write_general\":\"OK\"}"};

    EXPECT_EQ(response, expected_response_ok);

    context.SetError("Test error");

    std::string expected_response_error = {"{\"write_general\":\"Test error\"}"};

    std::string response_error = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response_error, expected_response_error);
}

TEST(PARSING, Events) {
//    std::string input = {"{\"add_event\":[{\"event_name\":\"breakfast\", "
//                         "\"event_date\":\"01-06-2000\", "
//                         "\"description\":\"dfhsdftjsftksft\", "
//                         "\"time_begin\":\"15:45\", "
//                         "\"time_end\":\"16:45\", "
//                         "\"user_id\":\"56\"}]}, "
//                         "{\"event_name\":\"Lancj\", "
//                         "\"event_date\":\"01-06-2000\", "
//                         "\"description\":\"2132\", "
//                         "\"time_begin\":\"11:45\", "
//                         "\"time_end\":\"14:00\", "
//                         "\"user_id\":\"56\"}]"};
//    std::string type_request = {"add_event"};
//    std::string user_id = {"56"};
//    std::set<std::string> contacts = {"Ibragim", "Ahper"};
//
//    ParserEvent parser;
//
//    Context context;
//
//    std::set<Event> events = {};
//
//    context = events;
//
//    context = parser.StrToObject(input);
//
//    EXPECT_EQ(user_id, context.GetContacts().GetUserId());
//    EXPECT_EQ(contacts, context.GetContacts().GetContacts());
//
//    std::string response = parser.ObjectToStr(type_request, context);
//
//    std::string expected_response = {"{\"add_contact\":\"OK\"}"};
//
//    EXPECT_EQ(response, expected_response);
//
//    context.SetError("Test error");
//
//    std::string expected_response_error = {"{\"add_contact\":\"Test error\"}"};
//
//    std::string response_error = parser.ObjectToStr(type_request, context);
//
//    EXPECT_EQ(response_error, expected_response_error);
}

TEST(PARSING, UserContacts) {
    std::string input = {"{\"add_contact\":{\"user_id\":\"56\",\"contacts\":[\"Ibragim\", \"Ahper\"]}}"};
    std::string type_request = {"add_contact"};
    std::set<std::string > contacts = {"Ibragim", "Ahper"};

    ParserUserContacts parser;

    Context context;

    context = parser.StrToObject(input);

    EXPECT_EQ("56", context.GetContacts().GetUserId());
    EXPECT_EQ(contacts, context.GetContacts().GetContacts());

    std::string response = parser.ObjectToStr(type_request, context);

    std::string expected_response = {"{\"add_contact\":\"OK\"}"};

    EXPECT_EQ(response, expected_response);

    context.SetError("Test error");

    std::string expected_response_error = {"{\"add_contact\":\"Test error\"}"};

    std::string response_error = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response_error, expected_response_error);
}

TEST(PARSING, Groups) {
//  По аналогии с RegAuth
}

TEST(PARSING, MeetUps) {
//  По аналогии с RegAuth
}
