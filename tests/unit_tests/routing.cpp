#include <gtest/gtest.h>

#include <nlohmann/json.hpp>

#include "RouteImpl.hpp"
#include "DBManager.hpp"

TEST(Routing, functional) {
    RouteImpl<pqxx::connection> route;

    std::string registration = {"{\"registration\":{\"nickname\":\"Sasha\",\"password\":\"123456asd64569898989\"}}"};

    route.InsertTask(registration);

    std::string res_reg_anwer = route.GetResTask(registration);

    nlohmann::json j_reg = nlohmann::json::parse(res_reg_anwer);
    nlohmann::json value_reg = j_reg[j_reg.begin().key()];

    std::string user_id_reg = value_reg["user_id"].get<std::string>();

    EXPECT_TRUE(!user_id_reg.empty());

    std::string authentication = {"{\"authentication\":{\"nickname\":\"Sasha\",\"password\":\"123456asd64569898989\"}}"};

    route.InsertTask(authentication);

    std::string res_auth_answer = route.GetResTask(authentication);

    nlohmann::json j_auth = nlohmann::json::parse(res_auth_answer);
    nlohmann::json value_auth = j_auth[j_auth.begin().key()];

    std::string user_id_auth = value_auth["user_id"].get<std::string>();

    EXPECT_TRUE(!user_id_reg.empty());

    EXPECT_EQ(user_id_reg, user_id_auth);

    std::string rm_user = {"{\"rm_user\":{\"user_id\":\""};

    rm_user += user_id_reg + "\"}}";

    route.InsertTask(rm_user);

    std::string res_rm_user_answer = route.GetResTask(rm_user);

    nlohmann::json j_rm_user = nlohmann::json::parse(res_rm_user_answer);

    std::string res_rm_user = j_rm_user["rm_user"].get<std::string>();

    EXPECT_EQ("OK", res_rm_user);
}
