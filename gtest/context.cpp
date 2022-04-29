#include <gtest/gtest.h>

#include <string>

#include "User.hpp"
#include "AddressData.hpp"
#include "PersonalData.hpp"
#include "GeneralData.hpp"
#include "Event.hpp"
#include "Contacts.hpp"
#include "Group.hpp"
#include "MeetUp.hpp"


TEST(DATACLASS, User) {
    std::string id = {"123"};
    std::string password = {"GogozikPARSSS"};
    std::string nickname = {"Gogozik"};

    User user;

    EXPECT_TRUE(user.IsEmpty());

    user.SetId(id);
    user.SetPassword(password);
    user.SetNickname(nickname);

    EXPECT_TRUE(id == user.GetId());
    EXPECT_TRUE(password == user.GetPassword());
    EXPECT_TRUE(nickname == user.GetNickname());
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
