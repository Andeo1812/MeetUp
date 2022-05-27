#include <iostream>

#include "Contacts.hpp"

bool Contacts::IsEmpty() const noexcept {
    return this->user_id.empty() && this->contacts.empty();
}

void Contacts::SetUserId(const std::string &user_id) noexcept {
    this->user_id = user_id;
}

void Contacts::SetContacts(const std::set<std::string> &contacts) noexcept {
    this->contacts = contacts;
}

std::string &Contacts::GetUserId() noexcept {
    return this->user_id;
}

std::set<std::string> &Contacts::GetContacts() noexcept {
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

const std::string &Contacts::AccessUserId() const noexcept {
    return this->user_id;
}

const std::set<std::string> &Contacts::AccessContacts() const noexcept {
    return this->contacts;
}
