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
    std::string input = {"{\"write_address\":{\"user_id\":\"1\", "
                         "\"building\":\"2\", "
                         "\"housing\":\"3\", "
                         "\"street\":\"Bolshaya Voskresenskaya\", "
                         "\"city\":\"Krasnogorsk\", "
                         "\"district\": \"Krasnogorskiy\", "
                         "\"index\":\"143430\", "
                         "\"country\":\"Russia\"}}"};
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
    std::string input = {"{\"write_personal\":{\"user_id\":\"8\", "
                         "\"name\":\"Bogdan\", "
                         "\"surname\":\"Kazimirov\", "
                         "\"date_birth\":\"2000-01-01\", "
                         "\"phone_number\":\"+79017453550\", "
                         "\"email\":\"bs@mt11.su\"}}"};
    std::string type_request = {"write_personal"};
    std::string user_id = {"8"};
    std::string name = {"Bogdan"};
    std::string surname = {"Kazimirov"};
    std::string email = {"bs@mt11.su"};
    std::string date_birth = {"2000-01-01"};
    std::string phone_number = {"+79017453550"};

    ParserPersonalData parser;

    Context context;

    PersonalData personal_data;

    context = personal_data;

    context = parser.StrToObject(input);

    EXPECT_EQ(user_id, context.GetPersonalData().GetUserId());
    EXPECT_EQ(name, context.GetPersonalData().GetName());
    EXPECT_EQ(surname, context.GetPersonalData().GetSurname());
    EXPECT_EQ(email, context.GetPersonalData().GetEmail());
    EXPECT_EQ(date_birth, context.GetPersonalData().GetDateBirth());
    EXPECT_EQ(phone_number, context.GetPersonalData().GetPhoneNumber());

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
    std::string user_id = {"8"};
    std::string status = {"asdas"};
    std::string tags = {"1asd"};
    std::string description = {"MT11-72"};
    std::string nickname = {"asdasd"};

    ParserGeneralData parser;

    Context context;

    GeneralData general_data;

    context = general_data;

    context = parser.StrToObject(input);

    EXPECT_EQ(user_id, context.GetGeneralData().GetUserId());
    EXPECT_EQ(status, context.GetGeneralData().GetStatus());
    EXPECT_EQ(tags, context.GetGeneralData().GetTags());
    EXPECT_EQ(description, context.GetGeneralData().GetDescription());
    EXPECT_EQ(nickname, context.GetGeneralData().GetNickname());

    std::string response = parser.ObjectToStr(type_request, context);

    std::string expected_response_ok = {"{\"write_general\":\"OK\"}"};

    EXPECT_EQ(response, expected_response_ok);

    context.SetError("Test error");

    std::string expected_response_error = {"{\"write_general\":\"Test error\"}"};

    std::string response_error = parser.ObjectToStr(type_request, context);

    EXPECT_EQ(response_error, expected_response_error);
}

TEST(PARSING, Events) {

}

TEST(PARSING, UserContacts) {
    std::string input = {"{\"add_contact\":{\"user_id\":\"56\",\"contacts\":[\"Ibragim\", \"Ahper\"]}}"};
    std::string type_request = {"add_contact"};
    std::string user_id = {"56"};
    std::set<std::string > contacts = {"Ibragim", "Ahper"};

    ParserUserContacts parser;

    Context context;

    Contacts cnt;

    context = cnt;

    context = parser.StrToObject(input);

    EXPECT_EQ(user_id, context.GetContacts().GetUserId());
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
