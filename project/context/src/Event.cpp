#include <iostream>

#include "Event.hpp"

bool Event::IsEmpty() const noexcept {
    if (this->id.empty() && this->name.empty() &&
        this->date.empty() && this->description.empty() &&
        this->time_begin.empty() && this->time_end.empty() &&
        this->user_id.empty()) {
        return true;
    }

    return false;
}

void Event::SetId(const std::string &id) noexcept {
    this->id = id;
}

void Event::SetName(const std::string &name) noexcept {
    this->name = name;
}

void Event::SetDate(const std::string &date) noexcept {
    this->date = date;
}

void Event::SetDescription(const std::string &description) noexcept {
    this->description = description;
}

void Event::SetTimeBegin(const std::string &time_begin) noexcept {
    this->time_begin = time_begin;
}

void Event::SetTimeEnd(const std::string &time_end) noexcept {
    this->time_end = time_end;
}

void Event::SetUserId(const std::string &user_id) noexcept {
    this->user_id = user_id;
}

std::string Event::GetId() const noexcept {
    return this->id;
}

std::string Event::GetName() const noexcept {
    return this->name;
}

std::string Event::GetDate() const noexcept {
    return this->date;
}

std::string Event::GetDescription() const noexcept {
    return this->description;
}

std::string Event::GetTimeBegin() const noexcept {
    return this->time_begin;
}

std::string Event::GetTimeEnd() const noexcept {
    return this->time_end;
}

std::string Event::GetUserId() const noexcept {
    return this->user_id;
}

std::ostream& operator<<(std::ostream &os, const Event &it) noexcept {
    os << "-------------------------------------------------------------------------" << std::endl;
    os << "Event" << std::endl;
    os << "event_id          :---: " << it.id << std::endl;
    os << "event_name        :---: " << it.name << std::endl;
    os << "date              :---: " << it.date << std::endl;
    os << "description       :---: " << it.description << std::endl;
    os << "time_begin        :---: " << it.time_begin << std::endl;
    os << "time_end          :---: " << it.time_end << std::endl;
    os << "user_id           :---: " << it.user_id << std::endl;

    return os;
}

bool Event::operator<(const Event &other) const noexcept {
    if (!this->id.empty()) {
        return this->id < other.id;
    }

    return this->name < other.name;
}

bool Event::operator==(const Event &other) const noexcept {
    return this->id == other.id;
}
