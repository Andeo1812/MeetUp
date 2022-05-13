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
    std::string input = {"{\"add_event\":[{\"description\":\"dfhsdftjsftksft\","
                         "\"event_date\":\"01-06-2000\","
                         "\"event_name\":\"123\","
                         "\"time_begin\":\"15:45\","
                         "\"time_end\":\"16:45\","
                         "\"user_id\":\"56\"},"
                         "{\"description\":\"2132\","
                         "\"event_date\":\"01-06-2000\","
                         "\"event_name\":\"Lancj\","
                         "\"time_begin\":\"11:45\","
                         "\"time_end\":\"14:00\","
                         "\"user_id\":\"56\"}]}"};
    std::string type_request = {"add_event"};

    ParserEvent parser;

    Context context;

    std::set<Event> events;

    Event event_1;

    event_1.SetName("123");
    event_1.SetDate("01-06-2000");
    event_1.SetDescription("dfhsdftjsftksft");
    event_1.SetTimeBegin("15:45");
    event_1.SetTimeEnd("16:45");
    event_1.SetUserId("56");

    events.insert(event_1);

    Event event_2;

    event_2.SetName("Lancj");
    event_2.SetDate("01-06-2000");
    event_2.SetDescription("2132");
    event_2.SetTimeBegin("11:45");
    event_2.SetTimeEnd("14:00");
    event_2.SetUserId("56");

    events.insert(event_2);

    context = parser.StrToObject(input);

    EXPECT_EQ(events, context.GetEvents());

    std::string response = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response, input);

    context.SetError("Test error");

    std::string expected_response_error = {"{\"add_event\":\"Test error\"}"};

    std::string response_error = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response_error, expected_response_error);
}

TEST(PARSING, UserContacts) {
    std::string input = {"{\"left\":\"5\",\"right\":\"10\",\"add_contact\":{\"user_id\":\"56\",\"contacts\":[\"Ibragim\", \"Ahper\"]}}"};
    std::string type_request = {"add_contact"};
    std::set<std::string> contacts = {"Ibragim", "Ahper"};

    ParserUserContacts parser;

    Context context;

    context = parser.StrToObject(input);

    EXPECT_EQ("56", context.GetContacts().GetUserId());
    EXPECT_EQ(contacts, context.GetContacts().GetContacts());
    EXPECT_EQ("5", context.GetLeftBorder());
    EXPECT_EQ("10", context.GetRightBorder());

    std::string response = parser.ObjectToStr(type_request, context);

    std::string expected_response = {"{\"add_contact\":\"OK\"}"};

    EXPECT_EQ(response, expected_response);

    context.SetError("Test error");

    std::string expected_response_error = {"{\"add_contact\":\"Test error\"}"};

    std::string response_error = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response_error, expected_response_error);
}

TEST(PARSING, Groups) {
    std::string input = {"{\"create_group\":[{\"description\":\"2132\","
                         "\"members\":[\"Ibragim\",\"Sultan\"],"
                         "\"title\":\"Texno\"},"
                         "{\"description\":\"121252\","
                         "\"members\":[\"Gaib\"],"
                         "\"title\":\"Texno231\"}]}"};
    std::string type_request = {"create_group"};
    std::set<std::string> members_1 = {"Ibragim", "Sultan"};
    std::set<std::string> members_2 = {"Gaib"};

    std::set<Group> groups;

    Group group_1;

    group_1.SetTitle("Texno");
    group_1.SetDescription("2132");
    group_1.SetMembers(members_1);

    groups.insert(group_1);

    Group group_2;

    group_2.SetTitle("Texno231");
    group_2.SetDescription("121252");
    group_2.SetMembers(members_2);

    groups.insert(group_2);

    ParserGroup parser;

    Context context;

    context = parser.StrToObject(input);

    EXPECT_EQ(groups, context.GetGroups());

    std::string response = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(input, response);

    context.SetError("Test error");

    std::string expected_response_error = {"{\"create_group\":\"Test error\"}"};

    std::string response_error = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response_error, expected_response_error);

    std::string input_get = {"{\"get_groups\":[{\"user_id\":\"654\"}],\"left\":\"5\",\"right\":\"10\"}"};

    context = parser.StrToObject(input_get);

    EXPECT_EQ("5", context.GetLeftBorder());
    EXPECT_EQ("10", context.GetRightBorder());
}

TEST(PARSING, MeetUps) {
    std::string input = {"{\"get_meetup\":[{\"description\":\"dfhsdftjsftksft\","
                         "\"group_id\":\"56\","
                         "\"meetup_date\":\"01-06-2000\","
                         "\"meetup_name\":\"123\","
                         "\"time_begin\":\"15:45\","
                         "\"time_end\":\"16:45\"},"
                         "{\"description\":\"2132\","
                         "\"group_id\":\"56\","
                         "\"meetup_date\":\"01-06-2000\","
                         "\"meetup_name\":\"Lancj\","
                         "\"time_begin\":\"11:45\","
                         "\"time_end\":\"14:00\"}]}"};
    std::string type_request = {"get_meetup"};

    ParserMeetUp parser;

    Context context;

    std::set<MeetUp> meetups;

    MeetUp meetup_1;

    meetup_1.SetName("123");
    meetup_1.SetDate("01-06-2000");
    meetup_1.SetDescription("dfhsdftjsftksft");
    meetup_1.SetTimeBegin("15:45");
    meetup_1.SetTimeEnd("16:45");
    meetup_1.SetGroupId("56");

    meetups.insert(meetup_1);

    MeetUp meetup_2;

    meetup_2.SetName("Lancj");
    meetup_2.SetDate("01-06-2000");
    meetup_2.SetDescription("2132");
    meetup_2.SetTimeBegin("11:45");
    meetup_2.SetTimeEnd("14:00");
    meetup_2.SetGroupId("56");

    meetups.insert(meetup_2);

    context = parser.StrToObject(input);

    EXPECT_EQ(meetups, context.GetMeetUp());

    std::string response = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response, input);

    context.SetError("Test error");

    std::string expected_response_error = {"{\"get_meetup\":\"Test error\"}"};

    std::string response_error = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response_error, expected_response_error);
}
