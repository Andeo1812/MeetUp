#include <gtest/gtest.h>

#include <unistd.h>
#include <random>

#include "DBManagerPG.hpp"
#include "DBUserImpl.hpp"
#include "DBUserDataImpl.hpp"
#include "DBEventImpl.hpp"
#include "DBContactsImpl.hpp"
#include "DBGroupImpl.hpp"

TEST(PostgreSQL, DBManager) {
    Singleton<DBManagerPG>::GetInstance();

    const size_t numCPU = MAX_COUNT_FREE_DB_VERSION;

    //  const size_t numCPU = sysconf(_SC_NPROCESSORS_ONLN);

    EXPECT_EQ(Singleton<DBManagerPG>::GetInstance().GetData().Size(), numCPU);

    auto con = Singleton<DBManagerPG>::GetInstance().GetData().GetFreeConnection();

    EXPECT_EQ(Singleton<DBManagerPG>::GetInstance().GetData().Size(), numCPU - 1);

    Singleton<DBManagerPG>::GetInstance().GetData().InsertConnection(con);

    EXPECT_EQ(Singleton<DBManagerPG>::GetInstance().GetData().Size(), numCPU);
}

TEST(PostgreSQL, DBUser) {
    User user;
    user.SetPassword("TEST_DEV100");
    user.SetNickname("TEST_DEV100");

    std::string new_user_id;

    int res_reg = Singleton<DBManagerPG>::GetInstance().GetData().User.Registration(user, new_user_id);
    user.SetId(new_user_id);

    EXPECT_EQ(res_reg, SUCCESS);

    int res_auth = Singleton<DBManagerPG>::GetInstance().GetData().User.Authentication(user);

    EXPECT_EQ(res_auth, SUCCESS);

    User user_not_exist;
    user_not_exist.SetPassword({"user_not_exist"});
    user_not_exist.SetNickname({"user_not_exist"});

    int res_wrong_auth = Singleton<DBManagerPG>::GetInstance().GetData().User.Authentication(user_not_exist);

    EXPECT_EQ(res_wrong_auth, NOT_AUTHENTICATION);

    std::string user_id;

    int res_get_id = Singleton<DBManagerPG>::GetInstance().GetData().User.GetId(user, user_id);

    EXPECT_EQ(res_get_id, SUCCESS);
    EXPECT_EQ(user_id, user.GetId());

    std::string get_nickname;

    int res_get_nickname = Singleton<DBManagerPG>::GetInstance().GetData().User.GetNickname(user, get_nickname);

    EXPECT_EQ(res_get_nickname, SUCCESS);
    EXPECT_EQ(get_nickname, user.GetNickname());

    int res_rm_user = Singleton<DBManagerPG>::GetInstance().GetData().User.Rm(user);

    EXPECT_EQ(res_rm_user, SUCCESS);
}


TEST(PostgreSQL, DBUserData) {

}

TEST(PostgreSQL, DBEvent) {
    std::string event_date = {"2000.01.01"};
    std::string event_name = {"lunch"};
    std::string time_begin = {"14:00"};
    std::string time_end = {"15:01"};
    std::string description = {"Important"};

    Event event;
    event.SetName(event_name);
    event.SetDate(event_date);
    event.SetTimeBegin(time_begin);
    event.SetTimeEnd(time_end);
    event.SetDescription(description);

    User user;
    user.SetPassword("TEST_DEV100");
    user.SetNickname("TEST_DEV100");

    std::string new_user_id;

    Singleton<DBManagerPG>::GetInstance().GetData().User.Registration(user, new_user_id);
    user.SetId(new_user_id);

    event.SetUserId(new_user_id);

    std::string new_event_id;

    int res_add = Singleton<DBManagerPG>::GetInstance().GetData().Event.Add(event, &new_event_id);
    event.SetId(new_event_id);

    EXPECT_TRUE(!new_event_id.empty());
    EXPECT_EQ(res_add, SUCCESS);

    int res_rm = Singleton<DBManagerPG>::GetInstance().GetData().Event.Rm(event);

    EXPECT_EQ(res_rm, SUCCESS);

    Singleton<DBManagerPG>::GetInstance().GetData().User.Rm(user);
}

TEST(PostgreSQL, DBContacts) {
    User user_1;
    user_1.SetPassword("TEST_DEV100");
    user_1.SetNickname("TEST_DEV100");

    std::string new_user_id_1;

    Singleton<DBManagerPG>::GetInstance().GetData().User.Registration(user_1, new_user_id_1);
    user_1.SetId(new_user_id_1);

    User user_2;
    user_2.SetPassword("TEST_DEV200");
    user_2.SetNickname("TEST_DEV200");

    std::string new_user_id_2;

    Singleton<DBManagerPG>::GetInstance().GetData().User.Registration(user_2, new_user_id_2);
    user_2.SetId(new_user_id_2);

    User user_3;
    user_3.SetPassword("TEST_DEV300");
    user_3.SetNickname("TEST_DEV300");

    std::string new_user_id_3;

    Singleton<DBManagerPG>::GetInstance().GetData().User.Registration(user_2, new_user_id_3);
    user_3.SetId(new_user_id_3);

    int res_add_contact_1 = Singleton<DBManagerPG>::GetInstance().GetData().Contacts.Add(user_1.GetId(), user_2.GetId());

    EXPECT_EQ(res_add_contact_1, SUCCESS);

    int res_add_contact_2 = Singleton<DBManagerPG>::GetInstance().GetData().Contacts.Add(user_1.GetId(), user_3.GetId());

    EXPECT_EQ(res_add_contact_2, SUCCESS);

    std::set<std::string> contacts_get;

    std::set<std::string> contacts_exp = {user_3.GetId(), user_2.GetId()};

    int res_get_set = Singleton<DBManagerPG>::GetInstance().GetData().Contacts.GetSet(user_1.GetId(), &contacts_get, 0, 3);

    EXPECT_EQ(res_get_set, SUCCESS);
    EXPECT_EQ(contacts_get, contacts_exp);

    int res_delete_contact_1 = Singleton<DBManagerPG>::GetInstance().GetData().Contacts.Rm(user_1.GetId(), user_2.GetId());

    EXPECT_EQ(res_delete_contact_1, SUCCESS);

    int res_delete_contact_2 = Singleton<DBManagerPG>::GetInstance().GetData().Contacts.Rm(user_1.GetId(), user_3.GetId());

    EXPECT_EQ(res_delete_contact_2, SUCCESS);

    Singleton<DBManagerPG>::GetInstance().GetData().User.Rm(user_1);
    Singleton<DBManagerPG>::GetInstance().GetData().User.Rm(user_2);
    Singleton<DBManagerPG>::GetInstance().GetData().User.Rm(user_3);
}

TEST(PostgreSQL, DBGroup) {
    User user_1;
    user_1.SetPassword("TEST_DEV100");
    user_1.SetNickname("TEST_DEV100");

    std::string new_user_id_1;

    Singleton<DBManagerPG>::GetInstance().GetData().User.Registration(user_1, new_user_id_1);
    user_1.SetId(new_user_id_1);

    User user_2;
    user_2.SetPassword("TEST_DEV200");
    user_2.SetNickname("TEST_DEV200");

    std::string new_user_id_2;

    Singleton<DBManagerPG>::GetInstance().GetData().User.Registration(user_2, new_user_id_2);
    user_2.SetId(new_user_id_2);

    Group group;

    group.SetTitle("Test");
    group.SetDescription("Test");
    group.SetUserId(user_1.GetId());


    std::string group_id;

    int res_create_group = Singleton<DBManagerPG>::GetInstance().GetData().Group.Create(group, &group_id);
    group.SetId(group_id);

    EXPECT_EQ(res_create_group, SUCCESS);

    int res_add_member_owner = Singleton<DBManagerPG>::GetInstance().GetData().Group.AddMember(user_1, group_id);

    EXPECT_EQ(res_add_member_owner, SUCCESS);

    int res_add_member_1 = Singleton<DBManagerPG>::GetInstance().GetData().Group.AddMember(user_2, group_id);

    EXPECT_EQ(res_add_member_1, SUCCESS);

    int res_rm_member_1 = Singleton<DBManagerPG>::GetInstance().GetData().Group.RmMember(user_2, group_id);

    EXPECT_EQ(res_rm_member_1, SUCCESS);

    int res_delete_all_members = Singleton<DBManagerPG>::GetInstance().GetData().Group.RmAllMembers(group_id);

    EXPECT_EQ(res_delete_all_members, SUCCESS);

    int res_delete_group = Singleton<DBManagerPG>::GetInstance().GetData().Group.Rm(group_id);

    EXPECT_EQ(res_delete_group, SUCCESS);

    Singleton<DBManagerPG>::GetInstance().GetData().User.Rm(user_1);
    Singleton<DBManagerPG>::GetInstance().GetData().User.Rm(user_2);
}
