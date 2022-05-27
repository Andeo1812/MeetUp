#include <iostream>

#include "Context.hpp"

bool Context::IsEmpty() const noexcept {
    return this->user.IsEmpty() && this->personal_data.IsEmpty() &&
           this->general_data.IsEmpty() && this->address_data.IsEmpty() &&
           this->events.empty() && this->groups.empty() &&
           this->meetups.empty() && this->contacts.IsEmpty();
}

Context &Context::operator=(const User& other) noexcept {
    this->user = other;
    return *this;
}

Context &Context::operator=(const PersonalData& other) noexcept {
    this->personal_data = other;
    return *this;
}

Context &Context::operator=(const AddressData& other) noexcept {
    this->address_data = other;
    return *this;
}

Context &Context::operator=(const GeneralData& other) noexcept {
    this->general_data = other;
    return *this;
}

Context &Context::operator=(const std::set<Event>& other) noexcept {
    this->events = other;
    return *this;
}

Context &Context::operator=(const std::set<Group>& other) noexcept {
    this->groups = other;
    return *this;
}

Context &Context::operator=(const std::set<MeetUp>& other) noexcept {
    this->meetups = other;
    return *this;
}

Context &Context::operator=(const Contacts& other) noexcept {
    this->contacts = other;
    return *this;
}

void Context::SetError(const std::string& error) noexcept {
    this->error = error;
}

void Context::SetLeftBorder(const size_t left) noexcept {
    this->left = left;
}

void Context::SetRightBorder(const size_t right) noexcept {
    this->right = right;
}

User &Context::GetUser() noexcept {
    return this->user;
}

PersonalData &Context::GetPersonalData() noexcept {
    return this->personal_data;
}

GeneralData &Context::GetGeneralData() noexcept {
    return this->general_data;
}

AddressData &Context::GetAddressData() noexcept {
    return this->address_data;
}


std::set<Event> &Context::GetEvents() noexcept {
    return this->events;
}


std::set<Group> &Context::GetGroups() noexcept {
    return this->groups;
}


std::set<MeetUp> &Context::GetMeetUp() noexcept {
    return this->meetups;
}


Contacts &Context::GetContacts() noexcept {
    return this->contacts;
}


std::string &Context::GetError() noexcept {
    return this->error;
}

size_t Context::GetLeftBorder() const noexcept {
    return this->left;
}

size_t Context::GetRightBorder() const noexcept {
    return this->right;
}

Context::Context(const User& other) noexcept : Context::Context() {
    *this = other;
}

Context::Context(const PersonalData& other) noexcept : Context::Context() {
    *this = other;
}

Context::Context(const GeneralData& other) noexcept : Context::Context() {
    *this = other;
}

Context::Context(const AddressData& other) noexcept : Context::Context() {
    *this = other;
}

Context::Context(const std::set<Event>& other) noexcept : Context::Context() {
    *this = other;
}

Context::Context(const std::set<Group>& other) noexcept : Context::Context() {
    *this = other;
}

Context::Context(const std::set<MeetUp>& other) noexcept : Context::Context() {
    *this = other;
}

Context::Context(const Contacts& other) noexcept : Context::Context() {
    *this = other;
}

const User &Context::AccessUser() const noexcept {
    return this->user;
}

const PersonalData &Context::AccessPersonalData() const noexcept {
    return this->personal_data;
}

const GeneralData &Context::AccessGeneralData() const noexcept {
    return this->general_data;
}

const AddressData &Context::AccessAddressData() const noexcept {
    return this->address_data;
}


const std::set<Event> &Context::AccessEvents() const noexcept {
    return this->events;
}


const std::set<Group> &Context::AccessGroups() const noexcept {
    return this->groups;
}


const std::set<MeetUp> &Context::AccessMeetUp() const noexcept {
    return this->meetups;
}


const Contacts &Context::AccessContacts() const noexcept {
    return this->contacts;
}


const std::string &Context::AccessError() const noexcept {
    return this->error;
}

