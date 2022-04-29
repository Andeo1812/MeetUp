#include <iostream>

#include "MeetUp.hpp"

bool MeetUp::IsEmpty() const noexcept {
    if (this->id.empty() && this->name.empty() &&
        this->date.empty() && this->description.empty() &&
        this->time_begin.empty() && this->time_end.empty() &&
        this->group_id.empty()) {
        return true;
    }

    return false;
}

void MeetUp::SetId(const std::string &id) noexcept {
    this->id = id;
}

void MeetUp::SetName(const std::string &name) noexcept {
    this->name = name;
}

void MeetUp::SetDate(const std::string &date) noexcept {
    this->date = date;
}

void MeetUp::SetDescription(const std::string &description) noexcept {
    this->description = description;
}

void MeetUp::SetTimeBegin(const std::string &time_begin) noexcept {
    this->time_begin = time_begin;
}

void MeetUp::SetTimeEnd(const std::string &time_end) noexcept {
    this->time_end = time_end;
}

void MeetUp::SetGroupId(const std::string &group_id) noexcept {
    this->group_id = group_id;
}

std::string MeetUp::GetId() const noexcept {
    return this->id;
}

std::string MeetUp::GetName() const noexcept {
    return this->name;
}

std::string MeetUp::GetDate() const noexcept {
    return this->date;
}

std::string MeetUp::GetDescription() const noexcept {
    return this->description;
}

std::string MeetUp::GetTimeBegin() const noexcept {
    return this->time_begin;
}

std::string MeetUp::GetTimeEnd() const noexcept {
    return this->time_end;
}

std::string MeetUp::GetGroupId() const noexcept {
    return this->group_id;
}

void operator<<(std::ostream &os, const MeetUp &it) noexcept {
    os << "-------------------------------------------------------------------------" << std::endl;
    os << "MeetUp" << std::endl;
    os << "user_id           :---: " << it.id << std::endl;
    os << "meetup_name       :---: " << it.name << std::endl;
    os << "date              :---: " << it.date << std::endl;
    os << "description       :---: " << it.description << std::endl;
    os << "time_begin        :---: " << it.time_begin << std::endl;
    os << "time_end          :---: " << it.time_end << std::endl;
}

bool MeetUp::operator<(const MeetUp &other) const noexcept {
    if (this->date == other.date) {
        if (this->time_begin == other.time_begin) {
            if (this->time_end == other.time_end) {
                if (this->name == other.name) {
                    return this->description < other.description;
                }
                return this->name < other.name;
            }
            return this->time_end < other.time_end;
        }
        return this->time_begin < other.time_begin;
    }
    return this->date < other.date;
}
