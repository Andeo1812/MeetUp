#include <gtest/gtest.h>

#include "User.hpp"
#include "AddressData.hpp"
#include "PersonalData.hpp"
#include "GeneralData.hpp"
#include "Event.hpp"
#include "Contacts.hpp"
#include "Group.hpp"
#include "MeetUp.hpp"

TEST(CONTEXT, User) {
    std::string user_id = {"123"};
    std::string password = {"GogozikPARSSS"};
    std::string nickname = {"Gogozik"};

    User user;

    EXPECT_TRUE(user.IsEmpty());

    user.SetId(user_id);
    user.SetPassword(password);
    user.SetNickname(nickname);

    EXPECT_EQ(user_id, user.GetId());
    EXPECT_EQ(password, user.GetPassword());
    EXPECT_EQ(nickname, user.GetNickname());

    EXPECT_TRUE(!user.IsEmpty());
}

TEST(CONTEXT, AddressData) {
    std::string user_id = {"123"};
    std::string building = {"13"};
    std::string housing = {"3"};
    std::string street = {"Lenina"};
    std::string city = {"Florencia"};
    std::string district = {"Venecia"};
    std::string index = {"42421"};
    std::string country = {"Italy"};

    AddressData address_data;

    EXPECT_TRUE(address_data.IsEmpty());

    address_data.SetUserId(user_id);
    address_data.SetBuilding(building);
    address_data.SetHousing(housing);
    address_data.SetStreet(street);
    address_data.SetCity(city);
    address_data.SetDistrict(district);
    address_data.SetIndex(index);
    address_data.SetCountry(country);

    EXPECT_EQ(user_id, address_data.GetUserId());
    EXPECT_EQ(building, address_data.GetBuilding());
    EXPECT_EQ(housing, address_data.GetHousing());
    EXPECT_EQ(street, address_data.GetStreet());
    EXPECT_EQ(city, address_data.GetCity());
    EXPECT_EQ(district, address_data.GetDistrict());
    EXPECT_EQ(index, address_data.GetIndex());
    EXPECT_EQ(country, address_data.GetCountry());

    EXPECT_TRUE(!address_data.IsEmpty());
}

TEST(CONTEXT, PersonalData) {
    std::string user_id = {"123"};
    std::string name = {"Alex"};
    std::string surname = {"Anofrikov"};
    std::string email = {"anof1131@mail.ru"};
    std::string date_birth = {"1999-01-26"};
    std::string phone_number = {"+79181826455"};

    PersonalData personal_data;

    EXPECT_TRUE(personal_data.IsEmpty());

    personal_data.SetUserId(user_id);
    personal_data.SetName(name);
    personal_data.SetSurname(surname);
    personal_data.SetEmail(email);
    personal_data.SetDateBirth(date_birth);
    personal_data.SetPhoneNumber(phone_number);

    EXPECT_EQ(user_id, personal_data.GetUserId());
    EXPECT_EQ(name, personal_data.GetName());
    EXPECT_EQ(surname, personal_data.GetSurname());
    EXPECT_EQ(email, personal_data.GetEmail());
    EXPECT_EQ(date_birth, personal_data.GetDateBirth());
    EXPECT_EQ(phone_number, personal_data.GetPhoneNumber());

    EXPECT_TRUE(!personal_data.IsEmpty());
}

TEST(CONTEXT, GeneralData) {
    std::string user_id = {"123"};
    std::string status = {"I free"};
    std::string tags = {"developer"};
    std::string description = {"TECHPARK THE BEST"};
    std::string nickname = {"MS.Gogozik"};

    GeneralData general_data;

    EXPECT_TRUE(general_data.IsEmpty());

    general_data.SetUserId(user_id);
    general_data.SetStatus(status);
    general_data.SetTags(tags);
    general_data.SetDescription(description);
    general_data.SetNickname(nickname);

    EXPECT_EQ(user_id, general_data.GetUserId());
    EXPECT_EQ(status, general_data.GetStatus());
    EXPECT_EQ(tags, general_data.GetTags());
    EXPECT_EQ(description, general_data.GetDescription());
    EXPECT_EQ(nickname, general_data.GetNickname());

    EXPECT_TRUE(!general_data.IsEmpty());
}

TEST(CONTEXT, Events) {
    std::string event_id = {"123"};
    std::string event_name = {"lunch"};
    std::string event_date = {"2022-01-01"};
    std::string description = {"EAT!"};
    std::string time_begin = {"19:11"};
    std::string time_end = {"20:12"};
    std::string user_id = {"32"};

    Event event;

    EXPECT_TRUE(event.IsEmpty());

    event.SetId(event_id);
    event.SetName(event_name);
    event.SetDate(event_date);
    event.SetDescription(description);
    event.SetTimeBegin(time_begin);
    event.SetTimeEnd(time_end);
    event.SetUserId(user_id);

    EXPECT_EQ(event_id, event.GetId());
    EXPECT_EQ(event_name, event.GetName());
    EXPECT_EQ(event_date, event.GetDate());
    EXPECT_EQ(description, event.GetDescription());
    EXPECT_EQ(time_begin, event.GetTimeBegin());
    EXPECT_EQ(time_end, event.GetTimeEnd());
    EXPECT_EQ(user_id, event.GetUserId());

    EXPECT_TRUE(!event.IsEmpty());

    std::string event_id_2 = {"1235"};
    std::string event_name_2 = {"lunch"};
    std::string event_date_2 = {"2022-01-02"};
    std::string description_2 = {"EAT!"};
    std::string time_begin_2 = {"19:11"};
    std::string time_end_2 = {"20:12"};
    std::string user_id_2 = {"32"};

    Event event_2;

    event_2.SetId(event_id_2);
    event_2.SetName(event_name_2);
    event_2.SetDate(event_date_2);
    event_2.SetDescription(description_2);
    event_2.SetTimeBegin(time_begin_2);
    event_2.SetTimeEnd(time_end_2);
    event_2.SetUserId(user_id_2);

    EXPECT_TRUE(event < event_2);
}

TEST(CONTEXT, Contacts) {
    std::string user_id = {"123"};
    std::set<std::string> cnt = {"Ibragim", "Gogozik"};

    Contacts contacts;

    EXPECT_TRUE(contacts.IsEmpty());

    contacts.SetUserId(user_id);
    contacts.SetContacts(cnt);

    EXPECT_EQ(user_id, contacts.GetUserId());
    EXPECT_EQ(cnt, contacts.GetContacts());

    EXPECT_TRUE(!contacts.IsEmpty());
}

TEST(CONTEXT, Groups) {
    std::string group_id = {"123"};
    std::string title = {"TP"};
    std::string description = {"the best company"};
    std::set<std::string> members = {"Gogozik", "Ibragim", "Alex"};
    std::string user_id = {"12332"};

    Group group;

    EXPECT_TRUE(group.IsEmpty());

    group.SetId(group_id);
    group.SetTitle(title);
    group.SetDescription(description);
    group.SetMembers(members);
    group.SetUserId(user_id);

    EXPECT_EQ(group_id, group.GetId());
    EXPECT_EQ(title, group.GetTitle());
    EXPECT_EQ(description, group.GetDescription());
    EXPECT_EQ(members, group.GetMembers());
    EXPECT_EQ(user_id, group.GetUserId());

    EXPECT_TRUE(!group.IsEmpty());

    std::string group_id_2 = {"12"};
    std::string title_2 = {"TP"};
    std::string description_2 = {"the best company"};
    std::set<std::string> members_2 = {"Gogozik", "Ibragim", "Alex"};
    std::string user_id_2 = {"12332"};

    Group group_2;

    group_2.SetId(group_id_2);
    group_2.SetTitle(title_2);
    group_2.SetDescription(description_2);
    group_2.SetMembers(members_2);
    group_2.SetUserId(user_id_2);

    EXPECT_TRUE(group_2 < group);
}

TEST(CONTEXT, MeetUps) {
    std::string meetup_id = {"123"};
    std::string meetup_name = {"lunch"};
    std::string meetup_date = {"2022-01-01"};
    std::string description = {"EAT!"};
    std::string time_begin = {"19:11"};
    std::string time_end = {"20:12"};
    std::string group_id = {"32"};

    MeetUp meetup;

    meetup.SetId(meetup_id);
    meetup.SetName(meetup_name);
    meetup.SetDate(meetup_date);
    meetup.SetDescription(description);
    meetup.SetTimeBegin(time_begin);
    meetup.SetTimeEnd(time_end);
    meetup.SetGroupId(group_id);

    EXPECT_EQ(meetup_id, meetup.GetId());
    EXPECT_EQ(meetup_name, meetup.GetName());
    EXPECT_EQ(meetup_date, meetup.GetDate());
    EXPECT_EQ(description, meetup.GetDescription());
    EXPECT_EQ(time_begin, meetup.GetTimeBegin());
    EXPECT_EQ(time_end, meetup.GetTimeEnd());
    EXPECT_EQ(group_id, meetup.GetGroupId());

    EXPECT_TRUE(!meetup.IsEmpty());

    std::string meetup_id_2 = {"123342"};
    std::string meetup_name_2 = {"lunch"};
    std::string meetup_date_2 = {"2022-01-02"};
    std::string description_2 = {"EAT!"};
    std::string time_begin_2 = {"19:11"};
    std::string time_end_2 = {"20:12"};
    std::string group_id_2 = {"32"};

    MeetUp meetup_2;

    meetup_2.SetId(meetup_id_2);
    meetup_2.SetName(meetup_name_2);
    meetup_2.SetDate(meetup_date_2);
    meetup_2.SetDescription(description_2);
    meetup_2.SetTimeBegin(time_begin_2);
    meetup_2.SetTimeEnd(time_end_2);
    meetup_2.SetGroupId(group_id_2);

    EXPECT_TRUE(meetup < meetup_2);
}
