#include <gtest/gtest.h>

#include "HandlerUser.hpp"
#include "HandlerAddressData.hpp"
#include "HandlerPersonalData.hpp"
#include "HandlerPrivateData.hpp"
#include "HandlerEvent.hpp"
#include "HandlerContacts.hpp"
#include "HandlerGroup.hpp"
#include "HandlerMeetUp.hpp"

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
}

TEST(HANDLERS, Authorization) {
//  По аналогии с Registration
}

TEST(HANDLERS, WriteAddressData) {
//  По аналогии с Registration
}

TEST(HANDLERS, GetAddressData) {
//  По аналогии с Registration
}

TEST(HANDLERS, WritePersonalData) {
//  По аналогии с Registration
}

TEST(HANDLERS, GetPersonalData) {
//  По аналогии с Registration
}

TEST(HANDLERS, WriteGeneralData) {
//  По аналогии с Registration
}

TEST(HANDLERS, GetGeneralData) {
//  По аналогии с Registration
}

TEST(HANDLERS, WritePassword) {
//  По аналогии с Registration
}

TEST(HANDLERS, GetNickname) {
//  По аналогии с Registration
}

TEST(HANDLERS, AddEvent) {
//  По аналогии с Registration
}

TEST(HANDLERS, WriteEvent) {
//  По аналогии с Registration
}

TEST(HANDLERS, RmEvent) {
//  По аналогии с Registration
}

TEST(HANDLERS, AddUserContact) {
//  По аналогии с Registration
}

TEST(HANDLERS, RmUserContact) {
//  По аналогии с Registration
}

TEST(HANDLERS, CreateGroup) {
//  По аналогии с Registration
}

TEST(HANDLERS, WriteGroup) {
//  По аналогии с Registration
}

TEST(HANDLERS, RmGroup) {
//  По аналогии с Registration
}

TEST(HANDLERS, GetGroupMembers) {
//  По аналогии с Registration
}

TEST(HANDLERS, AddUserGroup) {
//  По аналогии с Registration
}

TEST(HANDLERS, RmUserGroup) {
//  По аналогии с Registration
}

TEST(HANDLERS, GetMeetUp) {
//  По аналогии с Registration
}

TEST(HANDLERS, SynchroClientEvents) {
//  По аналогии с Registration
}

TEST(HANDLERS, SynchroClientContacts) {
//  По аналогии с Registration
}

TEST(HANDLERS, SynchroClientGroup) {
//  По аналогии с Registration
}
