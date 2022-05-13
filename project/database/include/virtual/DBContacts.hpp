#pragma once  //  NOLINT

#include <string>
#include <set>

template<class ClassConnection>
class DBContacts {
 public:
    virtual int Add(const std::string &user_id, const std::string &user_id_contact, ClassConnection *connection) const = 0;

    virtual int Rm(const std::string &user_id, const std::string &user_id_contact, ClassConnection *connection) const = 0;

    virtual int GetSet(const std::string &user_id, std::set<std::string> *contacts, const size_t &left, const size_t &right, ClassConnection *connection) const = 0;

    virtual ~DBContacts() = default;
};
