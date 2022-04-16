#include <iostream>

#include "Event.hpp"

void Event::Print() const {
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "Event" << std::endl;
    std::cout << "event_id          :---: " << event_id << std::endl;
    std::cout << "user_id           :---: " << user_id << std::endl;
    std::cout << "event_name        :---: " << event_name << std::endl;
    std::cout << "date              :---: " << date << std::endl;
    std::cout << "description       :---: " << description << std::endl;
    std::cout << "time_begin        :---: " << time_begin << std::endl;
    std::cout << "time_end          :---: " << time_end << std::endl;
}

bool Event::operator<(const Event &other) const {
    if (date == other.date) {
        if (time_begin == other.time_begin) {
            if (time_end == other.time_end) {
                if (event_name == other.event_name) {
                    return description < other.description;
                }
                return event_name < other.event_name;
            }
            return time_end < other.time_end;
        }
        return time_begin < other.time_begin;
    }
    return date < other.date;
}
