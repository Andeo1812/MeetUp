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

    if (!user.GetId().empty()) {
        value["user_id"] = user.GetId();
    }

    if (!user.GetPassword().empty()) {
        value["password"] = user.GetPassword();
    }

    if (!user.GetNickname().empty()) {
        value["nickname"] = user.GetNickname();
    }

    j[type_response] = value;

    res = j.dump();

    return res;
}

