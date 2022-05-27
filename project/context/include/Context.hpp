#pragma once  //  NOLINT

#include "Data/AddressData.hpp"
#include "Contacts.hpp"
#include "Event.hpp"
#include "Data/GeneralData.hpp"
#include "Group/Group.hpp"
#include "Group/MeetUp.hpp"
#include "Data/PersonalData.hpp"
#include "User.hpp"

class Context {
    User                       user;
    PersonalData      personal_data;
    GeneralData        general_data;
    AddressData        address_data;
    std::set<Event>          events;
    std::set<Group>          groups;
    std::set<MeetUp>        meetups;
    Contacts               contacts;
    size_t                     left;
    size_t                    right;
    std::string               error;

 public:
    bool IsEmpty() const noexcept;

    Context& operator=(const User& other) noexcept;
    Context& operator=(const PersonalData& other) noexcept;
    Context& operator=(const AddressData& other) noexcept;
    Context& operator=(const GeneralData& other) noexcept;
    Context& operator=(const std::set<Event>& other) noexcept;
    Context& operator=(const std::set<Group>& other) noexcept;
    Context& operator=(const std::set<MeetUp>& other) noexcept;
    Context& operator=(const Contacts& other) noexcept;

    void SetLeftBorder(const size_t left) noexcept;
    void SetRightBorder(const size_t right) noexcept;
    void SetError(const std::string& error) noexcept;

    User &GetUser() noexcept;
    PersonalData &GetPersonalData() noexcept;
    GeneralData &GetGeneralData() noexcept;
    AddressData &GetAddressData() noexcept;
    std::set<Event> &GetEvents() noexcept;
    std::set<Group> &GetGroups() noexcept;
    std::set<MeetUp> &GetMeetUp() noexcept;
    Contacts &GetContacts() noexcept;
    std::string &GetError() noexcept;
    size_t GetLeftBorder() const noexcept;
    size_t GetRightBorder() const noexcept;

    const User &AccessUser() const noexcept;
    const PersonalData &AccessPersonalData() const noexcept;
    const GeneralData &AccessGeneralData() const noexcept;
    const AddressData &AccessAddressData() const noexcept;
    const std::set<Event> &AccessEvents() const noexcept;
    const std::set<Group> &AccessGroups() const noexcept;
    const std::set<MeetUp> &AccessMeetUp() const noexcept;
    const Contacts &AccessContacts() const noexcept;
    const std::string &AccessError() const noexcept;

    Context() : left(0), right(0) {} ;
    Context(const Context& other) = default;
    Context(const User& other) noexcept;
    Context(const PersonalData& other) noexcept;
    Context(const AddressData& other) noexcept;
    Context(const GeneralData& other) noexcept;
    Context(const std::set<Event>& other) noexcept;
    Context(const std::set<Group>& other) noexcept;
    Context(const std::set<MeetUp>& other) noexcept;
    Context(const Contacts& other) noexcept;
    ~Context() = default;
};
