#include <nlohmann/json.hpp>

#include "ParserEvent.hpp"

Context ParserEvent::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json value = j[j.begin().key()];

    std::set<Event> events;

    for (auto &element : value) {
        Event event;

        get_data<std::string>(&Event::SetId,           &event, element, "event_id");
        get_data<std::string>(&Event::SetName,         &event, element, "event_name");
        get_data<std::string>(&Event::SetDate,         &event, element, "event_date");
        get_data<std::string>(&Event::SetDescription,  &event, element, "description");
        get_data<std::string>(&Event::SetTimeBegin,    &event, element, "time_begin");
        get_data<std::string>(&Event::SetTimeEnd,      &event, element, "time_end");
        get_data<std::string>(&Event::SetUserId,       &event, element, "user_id");

        events.insert(event);
    }

    return events;
}

std::string ParserEvent::ObjectToStr(const std::string type_response, const Context &other) const {
    nlohmann::json j;

    std::string res;

    if (!other.AccessError().empty()) {
        j[type_response] = other.AccessError();

        res = j.dump();

        return res;
    }

    if (type_response == WRITE_EVENT || type_response == RM_EVENT) {
        j[type_response] = "OK";

        res = j.dump();

        return res;
    }

    std::set<Event> events = other.AccessEvents();

    nlohmann::json json_events;

    for (auto &event : events) {
        nlohmann::json json_event;

        get_json(&Event::AccessId,          event, &json_event, "event_id");
        get_json(&Event::AccessName,        event, &json_event, "event_name");
        get_json(&Event::AccessTimeBegin,   event, &json_event, "time_begin");
        get_json(&Event::AccessTimeEnd,     event, &json_event, "time_end");
        get_json(&Event::AccessDescription, event, &json_event, "description");
        get_json(&Event::AccessDate,        event, &json_event, "event_date");
        get_json(&Event::AccessUserId,      event, &json_event, "user_id");

        json_events.push_back(json_event);
    }

    j[type_response] = json_events;

    res = j.dump();

    return res;
}
