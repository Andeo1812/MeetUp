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

        if (!meetup.GetId().empty()) {
            json_meetup["meetup_id"] = meetup.GetId();
        }

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

        if (!meetup.GetGroupId().empty()) {
            json_meetup["group_id"] = meetup.GetGroupId();
        }

        json_meetups.push_back(json_meetup);
    }

    j[type_response] = json_meetups;

    res = j.dump();

    return res;
}
