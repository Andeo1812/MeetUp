#include <nlohmann/json.hpp>

#include <iostream>

#include "ParserContacts.hpp"

Context ParserUserContacts::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    Context res;

    if (j.contains("left")) {
        res.SetLeftBorder(j["left"].get<size_t>());
    }

    if (j.contains("right")) {
        res.SetRightBorder(j["right"].get<size_t>());
    }

    nlohmann::json value = j[j.begin().key()];

    Contacts contacts;

    if (value.contains("user_id")) {
        contacts.SetUserId(value["user_id"].get<std::string>());
    }

    std::set<std::string> cnt;

    if (value.contains("contacts")) {
        for (auto &element : value["contacts"]) {
            cnt.insert(element.get<std::string>());
        }
    }

    contacts.SetContacts(cnt);

    res = contacts;

    return res;
}

std::string ParserUserContacts::ObjectToStr(const std::string type_response, const Context &other) const {
    nlohmann::json j;

    std::string res;

    if (!other.GetError().empty()) {
        j[type_response] = other.GetError();

        res = j.dump();

        return res;
    }

    if (type_response == ADD_USER_CONTACTS || type_response == RM_USER_CONTACTS) {
        j[type_response] = "OK";

        res = j.dump();

        return res;
    }

    Contacts contacts = other.GetContacts();

    if (other.GetLeftBorder()) {
        j["left"] = other.GetLeftBorder();
    }

    if (other.GetRightBorder()) {
        j["right"] = other.GetRightBorder();
    }

    j[type_response] = contacts.GetContacts();

    res = j.dump();

    return res;
}
