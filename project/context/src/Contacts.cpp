#include <iostream>

#include "Contacts.hpp"

bool Contacts::IsEmpty() const noexcept {
    if (this->user_id.empty() && this->contacts.empty()) {
        return true;
    }

    return false;
}

void Contacts::SetUserId(const std::string &user_id) noexcept {
    this->user_id = user_id;
}

void Contacts::SetContacts(const std::set<std::string> &contacts) noexcept {
    this->contacts = contacts;
}

std::string Contacts::GetUserId() const noexcept {
    return this->user_id;
}

std::set<std::string> Contacts::GetContacts() const noexcept {
    return this->contacts;
}

std::ostream&  operator<<(std::ostream &os, const Contacts &it) noexcept {
    os << "-------------------------------------------------------------------------" << std::endl;
    os << "Contacts" << std::endl;
    os << "user_id          :---: " << it.user_id << std::endl;
    for (auto &contact: it.contacts) {
        os << "contacts :---:         " << contact << std::endl;
    }

    return os;
}
