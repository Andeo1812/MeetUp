#include <nlohmann/json.hpp>

#include "ParserGeneralData.hpp"

Context ParserGeneralData::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json value = j[j.begin().key()];

    GeneralData general_data;

    if (value.contains("user_id")) {
        general_data.SetUserId(value["user_id"].get<std::string>());
    }

    if (value.contains("status")) {
        general_data.SetStatus(value["status"].get<std::string>());
    }

    if (value.contains("tags")) {
        general_data.SetTags(value["tags"].get<std::string>());
    }

    if (value.contains("description")) {
        general_data.SetDescription(value["description"].get<std::string>());
    }

    if (value.contains("nickname")) {
        general_data.SetNickname(value["nickname"].get<std::string>());
    }
    return general_data;
}

std::string ParserGeneralData::ObjectToStr(const std::string type_response, const Context &other) const {
    nlohmann::json j;

    std::string res;

    if (!other.GetError().empty()) {
        j[type_response] = other.GetError();

        res = j.dump();

        return res;
    }

    if (type_response == WRITE_GENERAL_DATA) {
        j[type_response] = "OK";

        res = j.dump();

        return res;
    }

    GeneralData general_data = other.GetGeneralData();

    nlohmann::json value;

    if (!general_data.GetUserId().empty()) {
        value["user_id"] = general_data.GetUserId();
    }

    if (!general_data.GetStatus().empty()) {
        value["status"] = general_data.GetStatus();
    }

    if (!general_data.GetTags().empty()) {
        value["tags"] = general_data.GetTags();
    }

    if (!general_data.GetDescription().empty()) {
        value["description"] = general_data.GetDescription();
    }

    if (!general_data.GetNickname().empty()) {
        value["nickname"] = general_data.GetNickname();
    }

    j[type_response] = value;

    res = j.dump();

    return res;
}
