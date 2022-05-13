#include <nlohmann/json.hpp>

#include "ParserContacts.hpp"

Context ParserUserContacts::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    Context res;

    if (j.contains("page")) {
        res.SetPage(j["page"].get<std::string>());
    }

    if (j.contains("count_one_page")) {
        res.SetCountOnePage(j["count_one_page"].get<std::string>());
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

    if (!other.GetPage().empty()) {
        j["page"] = other.GetPage();
    }

    if (!other.GetCountOnePage().empty()) {
        j["count_one_page"] = other.GetCountOnePage();
    }

    j[type_response] = contacts.GetContacts();

    res = j.dump();

    return res;
}
