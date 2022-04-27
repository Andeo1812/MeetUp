#pragma once  //  NOLINT

#include <string>

class DBContacts {
 public:
    virtual int Add(const std::string& user_id, const std::string& user_id_friend) const = 0;

    virtual int Delete(const std::string& user_id, const std::string& user_id_friend) const = 0;

    virtual ~DBContacts() = default;
};
