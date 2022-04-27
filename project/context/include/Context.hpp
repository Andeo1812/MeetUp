#pragma once  //  NOLINT

#include "AddressData.hpp"
#include "Contacts.hpp"
#include "Event.hpp"
#include "GeneralData.hpp"
#include "Group.hpp"
#include "MeetUp.hpp"
#include "PersonalData.hpp"
#include "User.hpp"

class Context {
 public:
    User                       user;
    PersonalData      personal_data;
    GeneralData        general_data;
    AddressData        address_data;
    std::set<Event>          events;
    std::set<Group>          groups;
    std::set<MeetUp>        meetups;
    Contacts               contacts;

    std::string               error;

    Context() = default;
    Context(const Context& other) = default;
    ~Context() = default;

    Context& operator=(const User other)                     { this->user = other;                return *this; }
    Context& operator=(const PersonalData other)             { this->personal_data = other;       return *this; }
    Context& operator=(const AddressData other)              { this->address_data = other;        return *this; }
    Context& operator=(const GeneralData other)              { this->general_data = other;        return *this; }
    Context& operator=(const std::set<Event> other)          { this->events = other;              return *this; }
    Context& operator=(const std::set<Group> other)          { this->groups = other;              return *this; }
    Context& operator=(const std::set<MeetUp> other)         { this->meetups = other;             return *this; }
    Context& operator=(const Contacts other)                 { this->contacts = other;            return *this; }
};
