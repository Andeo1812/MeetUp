#include <nlohmann/json.hpp>

#include "ParserContacts.hpp"

Context ParserUserContacts::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

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

    Context res;

    res = contacts;

    return res;
}

std::string ParserUserContacts::ObjectToStr(const std::string type_response, const Context &other) const {
    nlohmann::json j;

    std::string res;

    if (type_response == ADD_USER_CONTACTS || type_response == RM_USER_CONTACTS) {
        if (other.GetError().empty()) {
            j[type_response] = "OK";
            res = j.dump();
        } else {
            j[type_response] = other.GetError();
            res = j.dump();
        }
        return res;
    }

    Contacts contacts = other.GetContacts();

    if (contacts.GetContacts().empty()) {
        j[type_response] = "Not found contacts";

        res = j.dump();

        return res;
    }

    j[type_response] = contacts.GetContacts();

    res = j.dump();

    return res;
}
