#pragma once  //  NOLINT

//  RouteMapKeys
constexpr std::string_view REGISTRATION = {"registration"};
constexpr std::string_view AUTHENTICATION = {"authentication"};
constexpr std::string_view DELETE_USER = {"delete_user"};

constexpr std::string_view GET_EVENTS = {"get_events"};
constexpr std::string_view GET_CONTACTS = {"get_contacts"};
constexpr std::string_view GET_GROUPS = {"get_groups"};

constexpr std::string_view WRITE_GENERAL_DATA = {"write_general"};
constexpr std::string_view GET_GENERAL_DATA = {"get_general"};

constexpr std::string_view WRITE_PASSWORD = {"rewrite_password"};
constexpr std::string_view WRITE_NICKNAME = {"rewrite_nickname"};

constexpr std::string_view WRITE_PERSONAL_DATA = {"write_personal"};
constexpr std::string_view GET_PERSONAL_DATA = {"get_personal"};

constexpr std::string_view WRITE_ADDRESS = {"write_address"};
constexpr std::string_view GET_ADDRESS = {"get_address"};

constexpr std::string_view ADD_EVENT = {"add_event"};
constexpr std::string_view WRITE_EVENT = {"rewrite_event"};
constexpr std::string_view RM_EVENT = {"rm_event"};

constexpr std::string_view ADD_USER_CONTACTS = {"add_contact"};
constexpr std::string_view RM_USER_CONTACTS = {"rm_contact"};

constexpr std::string_view ADD_GROUP = {"create_group"};
constexpr std::string_view WRITE_GROUP = {"rewrite_group"};
constexpr std::string_view RM_GROUP = {"rm_group"};

constexpr std::string_view GET_MEMBERS = {"get_group_members"};

constexpr std::string_view ADD_USER_GROUP = {"invite"};
constexpr std::string_view RM_USER_GROUP = {"kick"};

constexpr std::string_view GET_MEETUP = {"get_meetup"};
