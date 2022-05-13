#pragma once  //  NOLINT

#include <string>
#include <set>

class DBContacts {
 public:
    virtual int Add(const std::string &user_id, const std::string &user_id_contact) const = 0;

    virtual int Rm(const std::string &user_id, const std::string &user_id_contact) const = 0;

    virtual int GetSet(const std::string &user_id, std::set<std::string> &contacts, const size_t count, const size_t page) const = 0;

    virtual ~DBContacts() = default;
};
