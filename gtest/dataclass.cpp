#include <gtest/gtest.h>

#include <string>

#include "User.hpp"
#include "Address.hpp"
#include "PersonalData.hpp"
#include "GeneralData.hpp"
#include "Events.hpp"
#include "Contacts.hpp"
#include "Groups.hpp"
#include "MeetUps.hpp"


TEST(DATACLASS, User) {
    std::string user_id = {"123"};
    std::string password = {"GogozikPARSSS"};
    std::string nickname = {"Gogozik"};

    User user;

    EXPECT_TRUE(user.IsEmpty());

    user.SetUserId(user_id);
    user.SetPassword(password);
    user.SetNickname(nickname);

    EXPECT_TRUE(user_id == user.GetUserId());
    EXPECT_TRUE(user_id == user.GetPassword());
    EXPECT_TRUE(user_id == user.GetNickname());
}

TEST(DATACLASS, Address) {
  //  По аналогии с User
}

TEST(DATACLASS, PersonalData) {
    //  По аналогии с User
}

TEST(DATACLASS, GeneralData) {
    //  По аналогии с User
}

TEST(DATACLASS, Events) {
    //  По аналогии с User
}

TEST(DATACLASS, Contacts) {
    //  По аналогии с User
}

TEST(DATACLASS, Groups) {
    //  По аналогии с User
}

TEST(DATACLASS, MeetUps) {

}
