#include <iostream>

#include "Group.hpp"

bool Group::IsEmpty() const noexcept {
    if (this->id.empty() && this->title.empty() &&
        this->description.empty() && this->members.empty() &&
        this->user_id.empty()) {
        return true;
    }

    return false;
}

void Group::SetId(const std::string &id) noexcept {
    this->id = id;
}

void Group::SetTitle(const std::string &title) noexcept {
    this->title = title;
}

void Group::SetDescription(const std::string &description) noexcept {
    this->description = description;
}

void Group::SetMembers(const std::set<std::string> &members) noexcept {
    this->members = members;
}

void Group::SetUserId(const std::string &user_id) noexcept {
    this->user_id = user_id;
}

std::string Group::GetId() const noexcept {
    return this->id;
}

std::string Group::GetTitle() const noexcept {
    return this->title;
}

std::string Group::GetDescription() const noexcept {
    return this->description;
}

std::set<std::string> Group::GetMembers() const noexcept {
    return this->members;
}

std::string Group::GetUserId() const noexcept {
    return this->user_id;
}

void operator<<(std::ostream &os, const Group &it) noexcept {
    os << "-------------------------------------------------------------------------" << std::endl;
    os << "Group" << std::endl;
    os << "group_id         :---: " << it.id << std::endl;
    os << "title            :---: " << it.title << std::endl;
    os << "description      :---: " << it.description << std::endl;
    for (auto &member : it.members) {
        os << "member           :---: " << member << std::endl;
    }
}

bool Group::operator<(const Group &other) const noexcept {
    return this->id < other.id;
}
