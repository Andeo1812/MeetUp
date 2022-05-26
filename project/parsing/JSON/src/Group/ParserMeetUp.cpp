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

    if (!other.GetError().empty()) {
        j[type_response] = other.GetError();

        res = j.dump();

        return res;
    }

    std::set<MeetUp> meetups = other.GetMeetUp();

    nlohmann::json json_meetups;

    for (auto &meetup : meetups) {
        nlohmann::json json_meetup;

        get_json(&MeetUp::GetId,          meetup, &json_meetup, "meetup_id");
        get_json(&MeetUp::GetName,        meetup, &json_meetup, "meetup_name");
        get_json(&MeetUp::GetTimeBegin,   meetup, &json_meetup, "time_begin");
        get_json(&MeetUp::GetTimeEnd,     meetup, &json_meetup, "time_end");
        get_json(&MeetUp::GetDescription, meetup, &json_meetup, "description");
        get_json(&MeetUp::GetDate,        meetup, &json_meetup, "meetup_date");
        get_json(&MeetUp::GetGroupId,     meetup, &json_meetup, "group_id");

        json_meetups.push_back(json_meetup);
    }

    j[type_response] = json_meetups;

    res = j.dump();

    return res;
}
