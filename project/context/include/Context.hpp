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

    User GetUser() const noexcept;
    PersonalData GetPersonalData() const noexcept;
    GeneralData GetGeneralData() const noexcept;
    AddressData GetAddressData() const noexcept;
    std::set<Event> GetEvents() const noexcept;
    std::set<Group> GetGroups() const noexcept;
    std::set<MeetUp> GetMeetUp() const noexcept;
    Contacts GetContacts() const noexcept;
    std::string GetError() const noexcept;
    size_t GetLeftBorder() const noexcept;
    size_t GetRightBorder() const noexcept;

    Context() : left(0), right(0) {};
    Context(const Context& other) = default;
    ~Context() = default;
};
