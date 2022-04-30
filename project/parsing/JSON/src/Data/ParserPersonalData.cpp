#include <nlohmann/json.hpp>

#include "ParserPersonalData.hpp"

Context ParserPersonalData::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json value = j[j.begin().key()];

    PersonalData personal_data;

    if (value.contains("user_id")) {
        personal_data.SetUserId(value["user_id"].get<std::string>());
    }

    if (value.contains("name")) {
        personal_data.SetName(value["name"].get<std::string>());
    }

    if (value.contains("surname")) {
        personal_data.SetSurname(value["surname"].get<std::string>());
    }

    if (value.contains("date_birth")) {
        personal_data.SetDateBirth(value["date_birth"].get<std::string>());
    }

    if (value.contains("email")) {
        personal_data.SetEmail(value["email"].get<std::string>());
    }

    if (value.contains("phone_number"))
        personal_data.SetPhoneNumber(value["phone_number"].get<std::string>());

    Context res;

    res = personal_data;

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
        if (other.GetError().empty()) {
            j[type_response] = "OK";

            res = j.dump();

        return res;
    }

    PersonalData personal_data = other.GetPersonalData();

    nlohmann::json value;

    if (!personal_data.GetUserId().empty()) {
        value["user_id"] = personal_data.GetUserId();
    }

    if (!personal_data.GetName().empty()) {
        value["name"] = personal_data.GetName();
    }

    if (!personal_data.GetSurname().empty()) {
        value["surname"] = personal_data.GetSurname();
    }

    if (!personal_data.GetEmail().empty()) {
        value["email"] = personal_data.GetEmail();
    }

    if (!personal_data.GetDateBirth().empty()) {
        value["date_birth"] = personal_data.GetDateBirth();
    }

    if (!personal_data.GetPhoneNumber().empty()) {
        value["phone_number"] = personal_data.GetPhoneNumber();
    }

    j[type_response] = value;

    res = j.dump();

    return res;
}
