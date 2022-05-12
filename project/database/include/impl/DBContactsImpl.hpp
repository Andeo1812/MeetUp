#pragma once  //  NOLINT

#include "DBContacts.hpp"

static enum result_add_contact {NOT_ADD_CONTACT = 5, ERROR_ADD_CONTACT} ADD_CONTACT;

static enum result_delete_contact  {NOT_DELETE_CONTACT = 10, ERROR_DELETE_CONTACT} DELETE_CONTACT;

class DBContactsImpl : public DBContacts {
 public:
    int Add(const std::string &user_id, const std::string &user_id_friend) const override;

    int Delete(const std::string &user_id, const std::string &user_id_friend) const override;

    int GetSet(const std::string &user_id, std::set<std::string> &contacts, const size_t count, const size_t page) const override;

    DBContactsImpl() = default;
    ~DBContactsImpl() = default;
};
