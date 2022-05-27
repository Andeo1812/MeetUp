#include <gtest/gtest.h>

#include "HandlerUser.hpp"
#include "HandlerAddressData.hpp"
#include "HandlerPersonalData.hpp"
#include "HandlerPrivateData.hpp"
#include "HandlerEvent.hpp"
#include "HandlerContacts.hpp"
#include "HandlerGroup.hpp"
#include "HandlerMeetUp.hpp"

std::string user_id;

TEST(HANDLERS, Registration) {
    AllDBMethods<pqxx::connection> db_methods;
    DBWorker<pqxx::connection> db_worker(db_methods);

    User user;

    user.SetPassword({"password"});
    user.SetNickname({"Gogozik"});

    Context context;

    context = user;

    Registration<pqxx::connection> reg_handler;

    context = reg_handler(context, &db_worker);

    EXPECT_TRUE(!context.IsEmpty());

    EXPECT_TRUE(context.AccessError().empty());

    user_id = context.AccessUser().AccessId();
}

TEST(HANDLERS, Authorization) {
    AllDBMethods<pqxx::connection> db_methods;
    DBWorker<pqxx::connection> db_worker(db_methods);

    User user;

    user.SetPassword({"password"});
    user.SetNickname({"Gogozik"});

    Context context;

    context = user;

    Authentication<pqxx::connection> reg_handler;

    context = reg_handler(context, &db_worker);

    EXPECT_TRUE(context.IsEmpty());

    EXPECT_TRUE(context.AccessError().empty());
}

TEST(HANDLERS, RmUser) {
    AllDBMethods<pqxx::connection> db_methods;
    DBWorker<pqxx::connection> db_worker(db_methods);

    User user;

    std::cout << user_id << std::endl;

    user.SetId(user_id);
    user.SetPassword({"password"});
    user.SetNickname({"Gogozik"});

    Context context;

    context = user;

    RmUser<pqxx::connection> reg_handler;

    context = reg_handler(context, &db_worker);

    EXPECT_TRUE(context.IsEmpty());

    EXPECT_TRUE(context.AccessError().empty());
}

//    TEST(HANDLERS, WriteAddressData) {
//
//    }
//
//    TEST(HANDLERS, GetAddressData) {
//
//    }
//
//    TEST(HANDLERS, WritePersonalData) {
//
//    }
//
//    TEST(HANDLERS, GetPersonalData) {
//
//    }
//
//    TEST(HANDLERS, WriteGeneralData) {
//
//    }
//
//    TEST(HANDLERS, GetGeneralData) {
//
//    }
//
//    TEST(HANDLERS, WritePassword) {
//
//    }
//
//    TEST(HANDLERS, GetNickname) {
//
//    }
//
//    TEST(HANDLERS, AddEvent) {
//
//    }
//
//    TEST(HANDLERS, WriteEvent) {
//
//    }
//
//    TEST(HANDLERS, RmEvent) {
//
//    }
//
//    TEST(HANDLERS, AddUserContact) {
//
//    }
//
//    TEST(HANDLERS, RmUserContact) {
//
//    }
//
//    TEST(HANDLERS, CreateGroup) {
//
//    }
//
//    TEST(HANDLERS, WriteGroup) {
//
//    }
//
//    TEST(HANDLERS, RmGroup) {
//
//    }
//
//    TEST(HANDLERS, GetGroupMembers) {
//
//    }
//
//    TEST(HANDLERS, AddUserGroup) {
//
//    }
//
//    TEST(HANDLERS, RmUserGroup) {
//
//    }
//
//    TEST(HANDLERS, GetMeetUp) {
//
//    }
//
//    TEST(HANDLERS, SynchroClientEvents) {
//
//    }
//
//    TEST(HANDLERS, SynchroClientContacts) {
//
//    }
//
//    TEST(HANDLERS, SynchroClientGroup) {
//
//    }
