#include <gtest/gtest.h>

#include <nlohmann/json.hpp>

#include "RouteImpl.hpp"
#include "DBManager.hpp"

RouteImpl route;
std::string user_id_reg;  //  NOLINT

TEST(Routing, user) {
    std::string registration = {"{\"registration\":{\"nickname\":\"Sasha\",\"password\":\"123456asd64569898989\"}}"};

    route.InsertTask(registration);

    std::string res_reg_answer;

    while (res_reg_answer.empty()) {
        std::cout << "I wait" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        res_reg_answer = route.GetResTask(registration);
    }

    nlohmann::json j_reg = nlohmann::json::parse(res_reg_answer);
    nlohmann::json value_reg = j_reg[j_reg.begin().key()];

    user_id_reg = value_reg["user_id"].get<std::string>();

    EXPECT_TRUE(!user_id_reg.empty());

//    std::string authentication = {"{\"authentication\":{\"nickname\":\"Sasha\",\"password\":\"123456asd64569898989\"}}"};
//
//    route.InsertTask(authentication);
//
//    std::string res_auth_answer = route.GetResTask(authentication);
//
//    nlohmann::json j_auth = nlohmann::json::parse(res_auth_answer);
//    nlohmann::json value_auth = j_auth[j_auth.begin().key()];
//
//    std::string user_id_auth = value_auth["user_id"].get<std::string>();
//
//    EXPECT_TRUE(!user_id_reg.empty());
//
//    EXPECT_EQ(user_id_reg, user_id_auth);
}

//    TEST(Routing, Event) {
//    std::string add_event = {"{\"add_event\":["
//                             "{\"description\":\"2132\","
//                             "\"event_date\":\"01-06-2000\","
//                             "\"event_name\":\"Lancj\","
//                             "\"time_begin\":\"11:45\","
//                             "\"time_end\":\"14:00\","
//                             "\"user_id\":\""};
//
//    //  std::cout << user_id_reg << std::endl;
//
//    add_event += user_id_reg + "\"}]}";
//
//    route.InsertTask(add_event);
//
//    std::string res_add_event_answer = route.GetResTask(add_event);
//
//    nlohmann::json j_add_event = nlohmann::json::parse(res_add_event_answer);
//    nlohmann::json value_add_event = j_add_event[j_add_event.begin().key()];
//
//    std::string event_id_add_event = value_add_event["event_id"].get<std::string>();
//
//    EXPECT_TRUE(!event_id_add_event.empty());

//    std::string add_event_2 = {"{\"add_event\":[{\"description\":\"dfhsdftj12222222222222sftksft\","
//                               "\"event_date\":\"01-06-2000\","
//                               "\"event_name\":\"123\","
//                               "\"time_begin\":\"15:45\","
//                               "\"time_end\":\"16:45\","
//                               "\"user_id\":\"56\"},"
//                               "{\"description\":\"2132\","
//                               "\"event_date\":\"01-06-2000\","
//                               "\"event_name\":\"Lancj\","
//                               "\"time_begin\":\"11:45\","
//                               "\"time_end\":\"14:00\","
//                               "\"user_id\":"};
//
//    add_event_2 += user_id_reg + "}]}";
//
//    route.InsertTask(add_event_2);
//
//    std::string res_add_event_answer_2 = route.GetResTask(add_event_2);
//
//    nlohmann::json j_add_event_2 = nlohmann::json::parse(res_add_event_answer_2);
//    nlohmann::json value_add_event_2 = j_add_event_2[j_add_event_2.begin().key()];
//
//    std::string event_id_add_event_2 = value_add_event_2["event_id"].get<std::string>();
//
//    EXPECT_TRUE(!event_id_add_event_2.empty());
//    }



//TEST(Routing, RmUser) {
//    std::string rm_user = {"{\"rm_user\":{\"user_id\":\""};
//
//    rm_user += user_id_reg + "\"}}";
//
//    route.InsertTask(rm_user);
//
//    std::string res_rm_user_answer = route.GetResTask(rm_user);
//
//    nlohmann::json j_rm_user = nlohmann::json::parse(res_rm_user_answer);
//
//    std::string res_rm_user = j_rm_user["rm_user"].get<std::string>();
//
//    EXPECT_EQ("OK", res_rm_user);
//}
