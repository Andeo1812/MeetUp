#include <gtest/gtest.h>

#include <unistd.h>

#include "DBManager.hpp"
#include "DBUserImpl.hpp"
#include "DBUserDataImpl.hpp"
#include "DBEventImpl.hpp"
#include "DBContactsImpl.hpp"
#include "DBGroupImpl.hpp"

TEST(PostgreSQL, DBManager) {
    Singleton<DBManager<pqxx::connection>>::GetInstance();

    const size_t numCPU = MAX_COUNT_FREE_DB_VERSION;

    //  const size_t numCPU = sysconf(_SC_NPROCESSORS_ONLN);

    EXPECT_EQ(Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().Size(), numCPU);
}

TEST(PostgreSQL, DBUser) {
    auto worker = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().GetFreeWorker(0);
    auto conn = &worker->connection;

    User user;
    user.SetPassword("TEST_DEV100");
    user.SetNickname("TEST_DEV100");

    std::string new_user_id;

    int res_reg = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Registration(user, &new_user_id, conn);
    user.SetId(new_user_id);
    EXPECT_EQ(res_reg, EXIT_SUCCESS);

    std::string user_idd;

    int res_auth = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Authentication(user, &user_idd, conn);
    EXPECT_EQ(res_auth, EXIT_SUCCESS);

    User user_not_exist;
    user_not_exist.SetPassword({"user_not_exist"});
    user_not_exist.SetNickname({"user_not_exist"});

    int res_wrong_auth = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Authentication(user_not_exist, &user_idd, conn);
    EXPECT_EQ(res_wrong_auth, NOT_AUTHENTICATION);

    std::string user_id;

    int res_get_id = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.GetId(user, &user_id, conn);
    EXPECT_EQ(res_get_id, EXIT_SUCCESS);
    EXPECT_EQ(user_id, user.GetId());

    std::string get_nickname;

    int res_get_nickname = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.GetNickname(user, &get_nickname, conn);
    EXPECT_EQ(res_get_nickname, EXIT_SUCCESS);
    EXPECT_EQ(get_nickname, user.GetNickname());

    int res_rm_user = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Rm(user, conn);
    EXPECT_EQ(res_rm_user, EXIT_SUCCESS);
}


//    TEST(PostgreSQL, DBUserData) {
//
//    }

TEST(PostgreSQL, DBEvent) {
    auto worker = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().GetFreeWorker(0);
    auto conn = &worker->connection;

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

    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Registration(user, &new_user_id, conn);
    user.SetId(new_user_id);

    event.SetUserId(new_user_id);

    std::string new_event_id;

    int res_add = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Event.Add(event, &new_event_id, conn);
    event.SetId(new_event_id);
    EXPECT_TRUE(!new_event_id.empty());
    EXPECT_EQ(res_add, EXIT_SUCCESS);

    int res_rm = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Event.Rm(event, conn);
    EXPECT_EQ(res_rm, EXIT_SUCCESS);

    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Rm(user, conn);
}

TEST(PostgreSQL, DBContacts) {
    auto worker = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().GetFreeWorker(0);
    auto conn = &worker->connection;

    User user_1;
    user_1.SetPassword("TEST_DEV100");
    user_1.SetNickname("TEST_DEV100");

    std::string new_user_id_1;

    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Registration(user_1, &new_user_id_1, conn);
    user_1.SetId(new_user_id_1);

    User user_2;
    user_2.SetPassword("TEST_DEV200");
    user_2.SetNickname("TEST_DEV200");

    std::string new_user_id_2;

    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Registration(user_2, &new_user_id_2, conn);
    user_2.SetId(new_user_id_2);

    User user_3;
    user_3.SetPassword("TEST_DEV300");
    user_3.SetNickname("TEST_DEV300");

    std::string new_user_id_3;

    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Registration(user_2, &new_user_id_3, conn);
    user_3.SetId(new_user_id_3);

    int res_add_contact_1 = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Contacts.Add(user_1.GetId(), user_2.GetId(), conn);
    EXPECT_EQ(res_add_contact_1, EXIT_SUCCESS);

    int res_add_contact_2 = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Contacts.Add(user_1.GetId(), user_3.GetId(), conn);
    EXPECT_EQ(res_add_contact_2, EXIT_SUCCESS);

    std::set<std::string> contacts_get;

    std::set<std::string> contacts_exp = {user_3.GetId(), user_2.GetId()};

    size_t left = 0;
    size_t right = 3;

    int res_get_set = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Contacts.GetSet(user_1.GetId(), &contacts_get, left, right, conn);
    EXPECT_EQ(res_get_set, EXIT_SUCCESS);
    EXPECT_EQ(contacts_get, contacts_exp);

    int res_delete_contact_1 = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Contacts.Rm(user_1.GetId(), user_2.GetId(), conn);
    EXPECT_EQ(res_delete_contact_1, EXIT_SUCCESS);

    int res_delete_contact_2 = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Contacts.Rm(user_1.GetId(), user_3.GetId(), conn);
    EXPECT_EQ(res_delete_contact_2, EXIT_SUCCESS);

    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Rm(user_1, conn);
    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Rm(user_2, conn);
    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Rm(user_3, conn);
}

TEST(PostgreSQL, DBGroup) {
    auto worker = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().GetFreeWorker(0);
    auto conn = &worker->connection;

    User user_1;
    user_1.SetPassword("TEST_DEV100");
    user_1.SetNickname("TEST_DEV100");

    std::string new_user_id_1;

    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Registration(user_1, &new_user_id_1, conn);
    user_1.SetId(new_user_id_1);

    User user_2;
    user_2.SetPassword("TEST_DEV200");
    user_2.SetNickname("TEST_DEV200");

    std::string new_user_id_2;

    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Registration(user_2, &new_user_id_2, conn);
    user_2.SetId(new_user_id_2);

    Group group_1;

    group_1.SetTitle("TEST_DEV100");
    group_1.SetDescription("TEST_DEV100");
    group_1.SetUserId(user_1.GetId());

    std::string group_id_1;

    Group group_2;

    group_2.SetTitle("TEST_DEV200");
    group_2.SetDescription("TEST_DEV200");
    group_2.SetUserId(user_1.GetId());

    std::string group_id_2;

    int res_create_group = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.Create(group_1, &group_id_1, conn);
    group_1.SetId(group_id_1);

    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.Create(group_2, &group_id_2, conn);

    EXPECT_EQ(res_create_group, EXIT_SUCCESS);

    int res_add_member_owner = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.AddMember(user_1.GetId(), group_id_1, conn);
    EXPECT_EQ(res_add_member_owner, EXIT_SUCCESS);

    int res_add_member_1 = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.AddMember(user_2.GetId(), group_id_1, conn);
    EXPECT_EQ(res_add_member_1, EXIT_SUCCESS);

    int res_rm_member_1 = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.RmMember(user_2.GetId(), group_id_1, conn);
    EXPECT_EQ(res_rm_member_1, EXIT_SUCCESS);

    int res_delete_all_members = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.RmAllMembers(group_id_1, conn);
    EXPECT_EQ(res_delete_all_members, EXIT_SUCCESS);

    int res_delete_group = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.Rm(group_id_1, conn);
    EXPECT_EQ(res_delete_group, EXIT_SUCCESS);

    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.Create(group_1, &group_id_1, conn);
    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.AddMember(user_1.GetId(), group_id_1, conn);
    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.Create(group_2, &group_id_2, conn);
    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.AddMember(user_1.GetId(), group_id_2, conn);

    size_t left = 0;
    size_t right = 3;

    std::set<Group> expected_groups;

    group_1.SetUserId({});
    group_2.SetUserId({});
    group_1.SetId(group_id_1);
    group_2.SetId(group_id_2);

    expected_groups.insert(group_1);
    expected_groups.insert(group_2);

    std::set<Group> get_groups;

    int res_get_set = Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.GetSet(user_1.GetId(), &get_groups, left, right, conn);
    EXPECT_EQ(res_get_set, EXIT_SUCCESS);
    EXPECT_EQ(get_groups, expected_groups);

    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.RmAllMembers(group_id_1, conn);
    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.Rm(group_id_1, conn);

    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.RmAllMembers(group_id_2, conn);
    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.Group.Rm(group_id_2, conn);

    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Rm(user_1, conn);
    Singleton<DBManager<pqxx::connection>>::GetInstance().GetData().db_methods.User.Rm(user_2, conn);
}
