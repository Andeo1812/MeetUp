#include <iostream>

#include "Context.hpp"

bool Context::IsEmpty() const noexcept {
    if (this->user.IsEmpty() && this->personal_data.IsEmpty() &&
        this->general_data.IsEmpty() && this->address_data.IsEmpty() &&
        this->events.empty() && this->groups.empty() &&
        this->meetups.empty() && this->contacts.IsEmpty()) {
            return true;
    }

    return false;
}

Context& Context::operator=(const User other) noexcept {
    this->user = other;
    return *this;
}

Context& Context::operator=(const PersonalData other) noexcept {
    this->personal_data = other;
    return *this;
}

Context& Context::operator=(const AddressData other) noexcept {
    this->address_data = other;
    return *this;
}

Context& Context::operator=(const GeneralData other) noexcept {
    this->general_data = other;
    return *this;
}

Context& Context::operator=(const std::set<Event> other) noexcept {
    this->events = other;
    return *this;
}

Context& Context::operator=(const std::set<Group> other) noexcept {
    this->groups = other;
    return *this;
}

Context& Context::operator=(const std::set<MeetUp> other) noexcept {
    this->meetups = other;
    return *this;
}

Context& Context::operator=(const Contacts other) noexcept {
    this->contacts = other;
    return *this;
}

void Context::SetError(const std::string &error) noexcept {
    this->error = error;
}

User Context::GetUser() const noexcept {
    return this->user;
}

PersonalData Context::GetPersonalData() const noexcept {
    return this->personal_data;
}

GeneralData Context::GetGeneralData() const noexcept {
    return this->general_data;
}

AddressData Context::GetAddressData() const noexcept {
    return this->address_data;
}


std::set<Event> Context::GetEvents() const noexcept {
    return this->events;
}


std::set<Group> Context::GetGroups() const noexcept {
    return this->groups;
}


std::set<MeetUp> Context::GetMeetUp() const noexcept {
    return this->meetups;
}


Contacts Context::GetContacts() const noexcept {
    return this->contacts;
}


std::string Context::GetError() const noexcept {
    return this->error;
}
