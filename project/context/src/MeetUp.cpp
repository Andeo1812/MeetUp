#include <iostream>

#include "MeetUp.hpp"

void MeetUp::Print() const {
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "MeetUp" << std::endl;
    std::cout << "user_id           :---: " << meetup_id << std::endl;
    std::cout << "meetup_name       :---: " << meetup_name << std::endl;
    std::cout << "date              :---: " << date << std::endl;
    std::cout << "description       :---: " << description << std::endl;
    std::cout << "time_begin        :---: " << time_begin << std::endl;
    std::cout << "time_end          :---: " << time_end << std::endl;
}

bool MeetUp::operator<(const MeetUp &other) const {
    if (date == other.date) {
        if (time_begin == other.time_begin) {
            if (time_end == other.time_end) {
                if (meetup_name == other.meetup_name) {
                    return description < other.description;
                }
                return meetup_name < other.meetup_name;
            }
            return time_end < other.time_end;
        }
        return time_begin < other.time_begin;
    }
    return date < other.date;
}