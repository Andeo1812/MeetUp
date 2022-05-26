#include <nlohmann/json.hpp>

#include "ParserMeetUp.hpp"

Context ParserMeetUp::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json value = j[j.begin().key()];

    std::set<MeetUp> meetups;

    for (auto &element : value) {
        MeetUp meetup;

        if (element.contains("meetup_id")) {
            meetup.SetId(element["meetup_id"].get<std::string>());
        }

        if (element.contains("meetup_name")) {
            meetup.SetName(element["meetup_name"].get<std::string>());
        }

        if (element.contains("meetup_date")) {
            meetup.SetDate(element["meetup_date"].get<std::string>());
        }

        if (element.contains("description")) {
            meetup.SetDescription(element["description"].get<std::string>());
        }

        if (element.contains("time_begin")) {
            meetup.SetTimeBegin(element["time_begin"].get<std::string>());
        }

        if (element.contains("time_end")) {
            meetup.SetTimeEnd(element["time_end"].get<std::string>());
        }

        if (element.contains("group_id")) {
            meetup.SetGroupId(element["group_id"].get<std::string>());
        }

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
