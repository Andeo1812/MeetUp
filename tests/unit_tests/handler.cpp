#include <gtest/gtest.h>

#include "HandlerUser.hpp"
#include "HandlerAddressData.hpp"
#include "HandlerPersonalData.hpp"
#include "HandlerPrivateData.hpp"
#include "HandlerEvent.hpp"
#include "HandlerContacts.hpp"
#include "HandlerGroup.hpp"
#include "HandlerMeetUp.hpp"
#include "HandlerSynchroClient.hpp"

DBMethods<pqxx::connection> db_methods;
DBWorker<pqxx::connection> db_worker(db_methods);

static std::string user_id;  //  NOLINT
static std::string event_id_1;  //  NOLINT
static std::string event_id_2;  //  NOLINT

TEST(HANDLERS, Registration) {
    User user;

    user.SetPassword({"password"});
    user.SetNickname({"Gogozik"});

    Context context = user;

    Registration<pqxx::connection> handler;

    context = handler(context, &db_worker);

    EXPECT_TRUE(!context.IsEmpty());

    EXPECT_TRUE(context.AccessError().empty());

    user_id = context.AccessUser().AccessId();
}

TEST(HANDLERS, Authorization) {
    User user;

    user.SetPassword({"password"});
    user.SetNickname({"Gogozik"});

    Context context = user;

    Authentication<pqxx::connection> handler;

    context = handler(context, &db_worker);

    EXPECT_TRUE(!context.IsEmpty());

    EXPECT_TRUE(context.AccessError().empty());
}

static std::string date = {"01.06.2000"};  //  NOLINT

TEST(HANDLERS, AddEvent) {
    Event event_1;

    event_1.SetName("123");
    event_1.SetDate(date);
    event_1.SetDescription("dfhsdftjsftksft");
    event_1.SetTimeBegin("15:45");
    event_1.SetTimeEnd("16:45");
    event_1.SetUserId(user_id);

    Event event_2;

    event_2.SetName("12asd3");
    event_2.SetDate(date);
    event_2.SetDescription("asd221");
    event_2.SetTimeBegin("15:10");
    event_2.SetTimeEnd("16:04");
    event_2.SetUserId(user_id);

    Context context;

    context.GetEvents().insert(event_1);
    context.GetEvents().insert(event_2);

    AddEvent<pqxx::connection> handler;

    context = handler(context, &db_worker);

    EXPECT_TRUE(!context.IsEmpty());

    auto iterator = context.AccessEvents().begin();

    event_id_1 = iterator->AccessId();

    EXPECT_TRUE(!event_id_1.empty());

    iterator++;

    event_id_2 = iterator->AccessId();

    EXPECT_TRUE(!event_id_2.empty());

    EXPECT_TRUE(context.AccessError().empty());
}

TEST(HANDLERS, GetSetEvents) {
    Event event_1;
    event_1.SetUserId(user_id);
    event_1.SetDate(date);

    Context context;

    context.GetEvents().insert(event_1);

    context.SetLeftBorder(0);
    context.SetRightBorder(2);

    GetSetEvents<pqxx::connection> handler;

    context = handler(context, &db_worker);
    EXPECT_EQ(context.AccessEvents().size(), 2);
}

TEST(HANDLERS, RmEvent) {
    Event event_1;
    event_1.SetId(event_id_1);

    Event event_2;
    event_2.SetId(event_id_2);

    Context context;

    context.GetEvents().insert(event_1);
    context.GetEvents().insert(event_2);

    RmEvent<pqxx::connection> handler;

    context = handler(context, &db_worker);

    EXPECT_TRUE(context.IsEmpty());
}

static std::string friend_id_1;  //  NOLINT

static std::string friend_id_2;  //  NOLINT

TEST(HANDLERS, Contacts) {
    User friend_1;
    friend_1.SetPassword({"password123"});
    friend_1.SetNickname({"Gogozik123"});

    Context context = friend_1;

    Registration<pqxx::connection> registration;

    context = registration(context, &db_worker);

    friend_id_1 = context.AccessUser().AccessId();

    User friend_2;
    friend_2.SetPassword({"passwordasdasd123"});
    friend_2.SetNickname({"Gogoasdadszik123"});

    context = friend_2;

    context = registration(context, &db_worker);

    friend_id_2 = context.AccessUser().AccessId();

    context.GetContacts().GetContacts().clear();

    AddUserContacts<pqxx::connection> add_contact;

    context.GetContacts().SetUserId(user_id);
    context.GetContacts().GetContacts().insert(friend_id_1);

    context = add_contact(context, &db_worker);
    EXPECT_TRUE(context.AccessError().empty());

    context.GetContacts().SetUserId(user_id);
    context.GetContacts().GetContacts().insert(friend_id_2);

    context = add_contact(context, &db_worker);
    EXPECT_TRUE(context.AccessError().empty());

    context.GetContacts().SetUserId(user_id);
    context.SetLeftBorder(0);
    context.SetRightBorder(2);

    GetSetContacts<pqxx::connection> get_set_contacts;

    context = get_set_contacts(context, &db_worker);

    EXPECT_TRUE(context.AccessError().empty());

    EXPECT_EQ(context.AccessContacts().AccessContacts().size(), 2);

    RmUserContacts<pqxx::connection> rm_contact;

    context.GetContacts().SetUserId(user_id);
    context.GetContacts().GetContacts().insert(friend_id_1);

    context = rm_contact(context, &db_worker);
    EXPECT_TRUE(context.AccessError().empty());

    context.GetContacts().SetUserId(user_id);
    context.GetContacts().GetContacts().insert(friend_id_2);

    context = rm_contact(context, &db_worker);
    EXPECT_TRUE(context.AccessError().empty());

    context.GetContacts().SetUserId(user_id);
    context.SetLeftBorder(0);
    context.SetRightBorder(2);

    context = get_set_contacts(context, &db_worker);
    EXPECT_TRUE(!context.AccessError().empty());
}

static std::string group_id_1;  //  NOLINT

static std::string group_id_2;  //  NOLINT

TEST(HANDLERS, Group) {
    Group group_1;

    group_1.SetTitle({"asdasdasd"});
    group_1.SetDescription({"asdgaagawga"});
    group_1.SetUserId(user_id);

    Context context;

    context.GetGroups().insert(group_1);

    AddGroup<pqxx::connection> add_group;

    context = add_group(context, &db_worker);

    EXPECT_TRUE(!context.IsEmpty());

    EXPECT_TRUE(context.AccessError().empty());

    group_id_1 = context.AccessGroups().begin()->AccessId();

    EXPECT_TRUE(!group_id_1.empty());

    Group group_2;

    group_2.SetTitle({"asdasddasdasdasdasdasdasd"});
    group_2.SetDescription({"asdgaagawga"});
    group_2.SetUserId(user_id);

    context.GetGroups().clear();
    context.GetGroups().insert(group_2);

    context = add_group(context, &db_worker);

    group_id_2 = context.AccessGroups().begin()->AccessId();

    Group group_for_set;

    group_for_set.SetUserId(user_id);

    context.GetGroups().clear();
    context.GetGroups().insert(group_for_set);
    context.SetLeftBorder(0);
    context.SetRightBorder(2);

    GetSetGroups<pqxx::connection> get_set_groups;

    context = get_set_groups(context, &db_worker);

    EXPECT_TRUE(context.AccessError().empty());

    EXPECT_EQ(context.AccessGroups().size(), 2);

    context.GetGroups().clear();

    Group group_add;

    group_add.SetUserId(friend_id_1);
    group_add.SetId(group_id_1);

    context.GetGroups().clear();
    context.GetGroups().insert(group_add);

    AddUserGroup<pqxx::connection> add_user_group;

    context = add_user_group(context, &db_worker);

    EXPECT_TRUE(context.AccessError().empty());

    Group group_rm;

    group_rm.SetUserId(friend_id_1);
    group_rm.SetId(group_id_1);

    context.GetGroups().clear();
    context.GetGroups().insert(group_rm);

    RmUserGroup<pqxx::connection> rm_user_group;

    context = add_user_group(context, &db_worker);

    EXPECT_TRUE(context.AccessError().empty());
}

TEST(HANDLERS, GetMeetUp) {
    Event event_1;
    event_1.SetDate(date);
    event_1.SetTimeBegin({"8:00"});
    event_1.SetTimeEnd({"9:00"});
    event_1.SetUserId(user_id);

    Event event_2;
    event_2.SetDate(date);
    event_2.SetTimeBegin({"13:23"});
    event_2.SetTimeEnd({"16:58"});
    event_2.SetUserId(user_id);

    Event event_3;
    event_3.SetDate(date);
    event_3.SetTimeBegin({"6:20"});
    event_3.SetTimeEnd({"7:40"});
    event_3.SetUserId(friend_id_1);

    Event event_4;
    event_4.SetDate(date);
    event_4.SetTimeBegin({"8:30"});
    event_4.SetTimeEnd({"14:20"});
    event_4.SetUserId(friend_id_1);

    Event event_5;
    event_5.SetDate(date);
    event_5.SetTimeBegin({"20:15"});
    event_5.SetTimeEnd({"21:20"});
    event_5.SetUserId(user_id);

    MeetUp meetup_1;
    meetup_1.SetTimeBegin({"00:00"});
    meetup_1.SetTimeEnd({"6:20"});

    MeetUp meetup_2;
    meetup_2.SetTimeBegin({"16:58"});
    meetup_2.SetTimeEnd({"20:15"});

    MeetUp meetup_3;
    meetup_3.SetTimeBegin({"21:20"});
    meetup_3.SetTimeEnd({"24::00"});

    std::set<MeetUp> expected_meetups;

    expected_meetups.insert(meetup_1);
    expected_meetups.insert(meetup_2);
    expected_meetups.insert(meetup_3);



    Context context;

    context.GetEvents().insert(event_1);
    context.GetEvents().insert(event_2);
    context.GetEvents().insert(event_5);

    AddEvent<pqxx::connection> add_event;

    context = add_event(context, &db_worker);

    auto iterator = context.AccessEvents().begin();

    event_1.SetId(iterator->AccessId());
    iterator++;

    event_2.SetId(iterator->AccessId());
    iterator++;

    event_5.SetId(iterator->AccessId());

    context.GetEvents().clear();
    context.GetEvents().insert(event_3);
    context.GetEvents().insert(event_4);

    context = add_event(context, &db_worker);

    auto iterator_2 = context.AccessEvents().begin();

    event_3.SetId(iterator_2->AccessId());
    iterator_2++;

    event_4.SetId(iterator_2->AccessId());

    Group group_add;

    group_add.SetUserId(friend_id_1);
    group_add.SetId(group_id_1);

    AddUserGroup<pqxx::connection> add_user_group;

    context.GetGroups().insert(group_add);

    context = add_user_group(context, &db_worker);




    MeetUp meetup;

    meetup.SetDate(date);
    meetup.SetGroupId(group_id_1);

    context.GetMeetUps().insert(meetup);

    GetMeetUps<pqxx::connection> get_set_meetups;

    context = get_set_meetups(context, &db_worker);

    EXPECT_TRUE(context.AccessError().empty());

    EXPECT_EQ(context.AccessMeetUps(), expected_meetups);






    Group group_rm;

    group_rm.SetUserId(friend_id_1);
    group_rm.SetId(group_id_1);

    context.GetGroups().clear();
    context.GetGroups().insert(group_rm);

    RmUserGroup<pqxx::connection> rm_user_group;

    context = rm_user_group(context, &db_worker);


    context.GetEvents().clear();
    context.GetEvents().insert(event_1);
    context.GetEvents().insert(event_2);
    context.GetEvents().insert(event_5);

    RmEvent<pqxx::connection> rm_event;

    context = rm_event(context, &db_worker);

    context.GetEvents().clear();
    context.GetEvents().insert(event_3);
    context.GetEvents().insert(event_4);

    context = rm_event(context, &db_worker);
}

TEST(HANDLERS, RmGroup) {
    Group group;
    group.SetId(group_id_1);

    Context context;

    context.GetGroups().insert(group);

    RmGroup<pqxx::connection> handler;

    context = handler(context, &db_worker);

    EXPECT_TRUE(context.IsEmpty());

    EXPECT_TRUE(context.AccessError().empty());

    group.SetId(group_id_2);
    context.GetGroups().insert(group);
    context = handler(context, &db_worker);
}

TEST(HANDLERS, RmUser) {
    User user;

    user.SetId(user_id);

    Context context = user;

    RmUser<pqxx::connection> handler;

    context = handler(context, &db_worker);

    EXPECT_TRUE(context.IsEmpty());

    EXPECT_TRUE(context.AccessError().empty());

    user.SetId(friend_id_1);
    context = user;
    context = handler(context, &db_worker);

    user.SetId(friend_id_2);
    context = user;
    context = handler(context, &db_worker);
}
