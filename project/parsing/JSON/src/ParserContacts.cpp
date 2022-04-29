#include <nlohmann/json.hpp>

#include <ParserContacts.hpp>

Context ParserUserContacts::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    Contacts contacts;

    if (value.contains("id")) {
        contacts.SetUserId(value["id"].get<std::string>());
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
    std::string res;

    return res;
}
