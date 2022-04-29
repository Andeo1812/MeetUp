#include <nlohmann/json.hpp>

#include <ParserGroup.hpp>

Context ParserGroup::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);


    nlohmann::json value = j[j.begin().key()];

    Group group;

    if (value.contains("group_id")) {
        group.SetGroupId(value["group_id"].get<std::string>());
    }

    if (value.contains("title")) {
        group.SetTitle(value["title"].get<std::string>());
    }

    if (value.contains("description")) {
        group.SetDescription(value["description"].get<std::string>());
    }

    std::set<std::string> members;

    if (value.contains("members")) {
        for (auto &element_in : value["members"]) {
            members.insert(element_in.get<std::string>());
        }
    }

    group.SetMembers(members);

    std::set<Group> groups;

    groups.insert(group);

    Context res;

    res = groups;

    return res;
}

std::string ParserGroup::ObjectToStr(const std::string type_response, const Context &other) const {
    nlohmann::json j;

    std::string res;

    if (type_response == WRITE_GROUP || type_response == RM_GROUP || type_response == ADD_USER ||
        type_response == RM_USER) {
        if (other.GetError().empty()) {
            j[type_response] = "OK";

            res = j.dump();
        } else {
            j[type_response] = other.GetError();

            res = j.dump();
        }

        return res;
    }

    if (other.GetError().empty()) {
        j[type_response] = "Not found group";

        res = j.dump();

        return res;
    }

    std::set<Group> groups = other.GetGroups();

    nlohmann::json json_groups;

    for (auto &group : groups) {
        nlohmann::json json_group;

        if (!group.GetGroupId().empty()) {
            json_group["group_id"] = group.GetGroupId();
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

    j[type_response] = json_groups;

    res = j.dump();

    return res;
}

