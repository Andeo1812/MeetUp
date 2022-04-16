#include <gtest/gtest.h>

#include "Registration.hpp"
#include "Authorization.hpp"

#include "WriteAddressData.hpp"
#include "GetAddressData.hpp"

#include "WritePersonalData.hpp"
#include "GetPersonalData.hpp"

#include "WritePassword.hpp"
#include "GetNickname.hpp"

#include "AddEvent.hpp"
#include "WriteEvent.hpp"
#include "RmEvent.hpp"

#include "AddUserContact.hpp"
#include "RmUserContact.hpp"

#include "CreateGroup.hpp"
#include "WriteGroup.hpp"
#include "RmGroup.hpp"
#include "GetGroupMembers.hpp"
#include "AddUserGroup.hpp"
#include "RmUserGroup.hpp"

#include "GetMeetUp.hpp"


TEST(HANDLERS, Registration) {
    std::string user_id = {"123"};
    std::string password = {"GogozikPARSSS"};
    std::string nickname = {"Gogozik"};

    User user;

    user.SetUserId(user_id);
    user.SetPassword(password);
    user.SetNickname(nickname);

    Context context;

    context = user;

    Registration reg_handler;

    EXPECT_TRUE(reg_handler);

    context = reg_handler.process(context);

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
