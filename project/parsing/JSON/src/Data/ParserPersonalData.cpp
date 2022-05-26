#include <nlohmann/json.hpp>

#include "ParserPersonalData.hpp"

Context ParserPersonalData::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json value = j[j.begin().key()];

    PersonalData personal_data;

    get_data<std::string>(&PersonalData::SetUserId,      &personal_data, value, "user_id");
    get_data<std::string>(&PersonalData::SetName,        &personal_data, value, "name");
    get_data<std::string>(&PersonalData::SetSurname,     &personal_data, value, "surname");
    get_data<std::string>(&PersonalData::SetDateBirth,   &personal_data, value, "date_birth");
    get_data<std::string>(&PersonalData::SetEmail,       &personal_data, value, "email");
    get_data<std::string>(&PersonalData::SetPhoneNumber, &personal_data, value, "phone_number");

    Context res = personal_data;

    return res;
}

std::string ParserPersonalData::ObjectToStr(const std::string type_response, const Context &other) const {
    nlohmann::json j;

    std::string res;

    if (!other.GetError().empty()) {
        j[type_response] = other.GetError();

        res = j.dump();

        return res;
    }

    if (type_response == WRITE_PERSONAL_DATA) {
        j[type_response] = "OK";

        res = j.dump();

        return res;
    }

    PersonalData personal_data = other.GetPersonalData();

    nlohmann::json value;

    get_json(&PersonalData::GetUserId,        personal_data, &value, "user_id");
    get_json(&PersonalData::GetName,          personal_data, &value, "status");
    get_json(&PersonalData::GetSurname,       personal_data, &value, "name");
    get_json(&PersonalData::GetEmail,         personal_data, &value, "email");
    get_json(&PersonalData::GetDateBirth,     personal_data, &value, "date_birth");
    get_json(&PersonalData::GetPhoneNumber,   personal_data, &value, "phone_number");

    j[type_response] = value;

    res = j.dump();

    return res;
}
