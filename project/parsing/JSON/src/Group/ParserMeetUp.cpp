#include <nlohmann/json.hpp>

#include "ParserMeetUp.hpp"

Context ParserMeetUp::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json value = j[j.begin().key()];

    std::set<MeetUp> meetups;

    for (auto &element : value) {
        MeetUp meetup;

        get_data<std::string>(&MeetUp::SetId,           &meetup, element, "meetup_id");
        get_data<std::string>(&MeetUp::SetName,         &meetup, element, "meetup_name");
        get_data<std::string>(&MeetUp::SetDate,         &meetup, element, "meetup_date");
        get_data<std::string>(&MeetUp::SetDescription,  &meetup, element, "description");
        get_data<std::string>(&MeetUp::SetTimeBegin,    &meetup, element, "time_begin");
        get_data<std::string>(&MeetUp::SetTimeEnd,      &meetup, element, "time_end");
        get_data<std::string>(&MeetUp::SetGroupId,      &meetup, element, "group_id");

        meetups.insert(meetup);
    }

    return meetups;
}

std::string ParserMeetUp::ObjectToStr(const std::string type_response, const Context &other) const {
    nlohmann::json j;

    std::string res;

    if (!other.AccessError().empty()) {
        j[type_response] = other.AccessError();

        res = j.dump();

        return res;
    }

    std::set<MeetUp> meetups = other.AccessMeetUps();

    nlohmann::json json_meetups;

    for (auto &meetup : meetups) {
        nlohmann::json json_meetup;

        get_json(&MeetUp::AccessId,          meetup, &json_meetup, "meetup_id");
        get_json(&MeetUp::AccessName,        meetup, &json_meetup, "meetup_name");
        get_json(&MeetUp::AccessTimeBegin,   meetup, &json_meetup, "time_begin");
        get_json(&MeetUp::AccessTimeEnd,     meetup, &json_meetup, "time_end");
        get_json(&MeetUp::AccessDescription, meetup, &json_meetup, "description");
        get_json(&MeetUp::AccessDate,        meetup, &json_meetup, "meetup_date");
        get_json(&MeetUp::AccessGroupId,     meetup, &json_meetup, "group_id");

        json_meetups.push_back(json_meetup);
    }

    j[type_response] = json_meetups;

    res = j.dump();

    return res;
}
