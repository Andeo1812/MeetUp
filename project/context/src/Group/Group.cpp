#include <iostream>

#include "Group.hpp"

bool Group::IsEmpty() const noexcept {
    return this->id.empty() && this->title.empty() &&
           this->description.empty() && this->members.empty() &&
           this->user_id.empty();
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

std::string &Group::GetId() noexcept {
    return this->id;
}

std::string &Group::GetTitle() noexcept {
    return this->title;
}

std::string &Group::GetDescription() noexcept {
    return this->description;
}

std::set<std::string> &Group::GetMembers() noexcept {
    return this->members;
}

std::string &Group::GetUserId() noexcept {
    return this->user_id;
}

std::ostream&  operator<<(std::ostream &os, const Group &it) noexcept {
    os << "-------------------------------------------------------------------------" << std::endl;
    os << "Group" << std::endl;
    os << "group_id         :---: " << it.id << std::endl;
    os << "title            :---: " << it.title << std::endl;
    os << "description      :---: " << it.description << std::endl;
    for (auto &member : it.members) {
        os << "member           :---: " << member << std::endl;
    }

    return os;
}

bool Group::operator<(const Group &other) const noexcept {
    if (!this->id.empty()) {
        return this->id < other.id;
    }

    return this->title < other.title;
}

bool Group::operator==(const Group &other) const noexcept {
    if (!this->id.empty()) {
        return this->id == other.id;
    }

    return this->title == other.title;
}


const std::string &Group::AccessId() const noexcept {
    return this->id;
}

const std::string &Group::AccessTitle() const noexcept {
    return this->title;
}

const std::string &Group::AccessDescription() const noexcept {
    return this->description;
}

const std::set<std::string> &Group::AccessMembers() const noexcept {
    return this->members;
}

const std::string &Group::AccessUserId() const noexcept {
    return this->user_id;
}
