#include <nlohmann/json.hpp>

#include "ParserEvent.hpp"

Context ParserEvent::StrToObject(const std::string &parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    std::set<Event> events;

    for (auto &element : value) {
        Event event;

        if (element.contains("id")) {
            event.SetId(element["id"].get<std::string>());
        }

        if (element.contains("name")) {
            event.SetName(element["name"].get<std::string>());
        }

        if (element.contains("date")) {
            event.SetDate(element["date"].get<std::string>());
        }

        if (element.contains("description")) {
            event.SetDescription(element["description"].get<std::string>());
        }

        if (element.contains("time_begin")) {
            event.SetTimeBegin(element["time_begin"].get<std::string>());
        }

        if (element.contains("time_end")) {
            event.SetTimeEnd(element["time_end"].get<std::string>());
        }

        if (element.contains("user_id")) {
            event.SetUserId(element["user_id"].get<std::string>());
        }

        events.insert(event);
    }

    Context res;

    res = events;

    return res;
}

std::string ParserEvent::ObjectToStr(const std::string type_response, const Context &other) const {
    nlohmann::json j;

    std::string res;

    if (type_response == WRITE_EVENT || type_response == RM_EVENT) {
        if (other.GetError().empty()) {
            j[type_response] = "OK";

            res = j.dump();
        } else {
            j[type_response] = other.GetError();

            res = j.dump();
        }

        return res;
    }

    std::set<Event> events = other.GetEvents();

    if (events.empty()) {
        j[type_response] = "Not found events";

        res = j.dump();

        return res;
    }

    nlohmann::json json_events;

    for (auto &event : events) {
        nlohmann::json json_event;

        if (!event.GetId().empty()) {
            json_event["id"] = event.GetId();
        }

        if (!event.GetName().empty()) {
            json_event["name"] = event.GetName();
        }

        if (!event.GetDate().empty()) {
            json_event["date"] = event.GetDate();
        }

        if (!event.GetDescription().empty()) {
            json_event["description"] = event.GetDescription();
        }

        if (!event.GetTimeBegin().empty()) {
            json_event["time_begin"] = event.GetTimeBegin();
        }

        if (!event.GetTimeEnd().empty()) {
            json_event["time_end"] = event.GetTimeEnd();
        }

        if (!event.GetUserId().empty()) {
            json_event["user_id"] = event.GetUserId();
        }

        json_events.push_back(json_event);
    }

    j[type_response] = json_events;

    res = j.dump();

    return res;
}
