#include <nlohmann/json.hpp>

#include <ParserMeetUp.hpp>

Context ParserMeetUp::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json value = j[j.begin().key()];

    MeetUp meetup;

    Group group;

    if (value.contains("group_id")) {
        meetup.SetGroupId(value["group_id"].get<std::string>());
    }

    if (value.contains("meetup_date")) {
        meetup.SetDate(value["meetup_date"].get<std::string>());
    }

    std::set<std::string> members;
    if (value.contains("members")) {
        for (auto &element_in : value["members"]) {
            members.insert(element_in.get<std::string>());
        }
    }

    Context res;

    group.SetMembers(members);

    std::set<Group> groups;

    groups.insert(group);

    res = groups;

    std::set<MeetUp> meetups;

    meetups.insert(meetup);

    res = meetups;

    return res;
}

std::string ParserMeetUp::ObjectToStr(const std::string type_response, const Context &other) const {
    nlohmann::json j;

    std::string res;

    if (!other.GetError().empty()) {
        j[type_response] = other.GetError();

        res = j.dump();

        return res;
    }

    std::set<MeetUp> meetups = other.GetMeetUp();

    nlohmann::json json_meetups;

    if (!meetups.empty()) {
        for (auto &meetup : meetups) {
            nlohmann::json json_meetup;

            if (!meetup.GetName().empty()) {
                json_meetup["meetup_name"] = meetup.GetName();
            }

            if (!meetup.GetTimeBegin().empty()) {
                json_meetup["time_begin"] = meetup.GetTimeBegin();
            }

            if (!meetup.GetTimeEnd().empty()) {
                json_meetup["time_end"] = meetup.GetTimeEnd();
            }

            if (!meetup.GetDescription().empty()) {
                json_meetup["description"] = meetup.GetDescription();
            }

            if (!meetup.GetDate().empty()) {
                json_meetup["meetup_date"] = meetup.GetDate();
            }

            json_meetups.push_back(json_meetup);
        }
    }

    j[type_response] = json_meetups;

    res = j.dump();

    return res;
}
