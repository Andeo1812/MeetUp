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

    if (!other.GetError().empty()) {
        j[type_response] = other.GetError();

        res = j.dump();

        return res;
    }

    User user = other.GetUser();

    nlohmann::json value;

    get_json(&User::GetId,        user, &value, "user_id");
    get_json(&User::GetPassword,  user, &value, "password");
    get_json(&User::GetNickname,  user, &value, "nickname");

    j[type_response] = value;

    res = j.dump();

    return res;
}

