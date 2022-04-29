#include <nlohmann/json.hpp>

#include "ParserUser.hpp"

Context ParserUser::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    User user;

    if (value.contains("user_id")) {
        user.SetId(value["user_id"].get<std::string>());
    }

    if (value.contains("password")) {
        user.SetPassword(value["password"].get<std::string>());
    }

    if (value.contains("nickname")) {
        user.SetNickname(value["nickname"].get<std::string>());
    }

    Context res;

    res = user;

    return res;
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

