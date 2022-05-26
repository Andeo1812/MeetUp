#include <nlohmann/json.hpp>

#include "ParserGroup.hpp"

Context ParserGroup::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    Context res;

    get_data<size_t>(&Context::SetLeftBorder,     &res, j, "left");
    get_data<size_t>(&Context::SetRightBorder,    &res, j, "right");

    nlohmann::json value = j[j.begin().key()];

    std::set<Group> groups;

    for (auto &element : value) {
        Group group;

        get_data<std::string>(&Group::SetId,             &group, element, "group_id");
        get_data<std::string>(&Group::SetTitle,          &group, element, "title");
        get_data<std::string>(&Group::SetDescription,    &group, element, "description");

        std::set<std::string> members;

        if (element.contains("members")) {
            for (auto &element_in : element["members"]) {
                members.insert(element_in.get<std::string>());
            }
        }

        group.SetMembers(members);

        groups.insert(group);
    }

    res = groups;

    return res;
}

std::string ParserGroup::ObjectToStr(const std::string type_response, const Context &other) const {
    nlohmann::json j;

    std::string res;

    if (!other.GetError().empty()) {
        j[type_response] = other.GetError();

        res = j.dump();

        return res;
    }

    if (type_response == WRITE_GROUP || type_response == RM_GROUP || type_response == ADD_USER_GROUP ||
        type_response == RM_USER_GROUP) {
        j[type_response] = "OK";

        res = j.dump();

        return res;
    }

    std::set<Group> groups = other.GetGroups();

    nlohmann::json json_groups;

    for (auto &group : groups) {
        nlohmann::json json_group;

        if (!group.GetId().empty()) {
            json_group["group_id"] = group.GetId();
        }

        if (!group.GetTitle().empty()) {
            json_group["title"] = group.GetTitle();
        }

        if (!group.GetDescription().empty()) {
            json_group["description"] = group.GetDescription();
        }

        if (!(group.GetMembers().empty())) {
            json_group["members"] = group.GetMembers();
        }

        json_groups.push_back(json_group);
    }

    if (other.GetLeftBorder()) {
        j["left"] = other.GetLeftBorder();
    }

    if (other.GetRightBorder()) {
        j["right"] = other.GetRightBorder();
    }

    j[type_response] = json_groups;

    res = j.dump();

    return res;
}

