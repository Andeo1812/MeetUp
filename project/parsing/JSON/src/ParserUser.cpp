#include <nlohmann/json.hpp>

#include "ParserUser.hpp"

Context ParserUser::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json value = j[j.begin().key()];

    User user;

    get_data<std::string>(&User::SetId,        &user, value, "user_id");
    get_data<std::string>(&User::SetPassword,  &user, value, "password");
    get_data<std::string>(&User::SetNickname,  &user, value, "nickname");

    return user;
}

std::string ParserUser::ObjectToStr(const std::string type_response, const Context &other) const {
    nlohmann::json j;

    std::string res;

    if (!other.AccessError().empty()) {
        j[type_response] = other.AccessError();

        res = j.dump();

        return res;
    }

    if (type_response == RM_USER) {
        j[type_response] = "OK";

        res = j.dump();

        return res;
    }

    User user = other.AccessUser();

    nlohmann::json value;

    get_json(&User::AccessId,        user, &value, "user_id");
    get_json(&User::AccessPassword,  user, &value, "password");
    get_json(&User::AccessNickname,  user, &value, "nickname");

    j[type_response] = value;

    res = j.dump();

    return res;
}

