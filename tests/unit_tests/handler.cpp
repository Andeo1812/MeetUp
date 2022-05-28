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
    event_2.SetTimeBegin("15:45");
    event_2.SetTimeEnd("16:45");
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

    std::cout << context.AccessError() << std::endl;

    EXPECT_TRUE(context.IsEmpty());
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
