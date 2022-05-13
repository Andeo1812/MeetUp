#pragma once  //  NOLINT

#include "DBContacts.hpp"

static enum result_add_contact {NOT_ADD_CONTACT = 5, ERROR_ADD_CONTACT} ADD_CONTACT;

static enum result_delete_contact  {NOT_RM_CONTACT = 10, ERROR_RM_CONTACT} DELETE_CONTACT;

static enum result_get_set_contact  {NOT_GET_SET_CONTACT = 15, ERROR_GET_SET_CONTACT} GET_SET_CONTACT;

class DBContactsImpl : public DBContacts {
 public:
    int Add(const std::string &user_id, const std::string &user_id_contact) const override;

    int Rm(const std::string &user_id, const std::string &user_id_contact) const override;

    int GetSet(const std::string &user_id, std::set<std::string> *contacts, const size_t &left, const size_t &right) const override;

    DBContactsImpl() = default;
    ~DBContactsImpl() = default;
};
