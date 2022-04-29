#pragma once  //  NOLINT

#include "DBContacts.hpp"

class DBContactsImpl : public DBContacts {
 public:
    int Add(const std::string &user_id, const std::string &user_id_friend) const override;

    int Delete(const std::string &user_id, const std::string &user_id_friend) const override;

    ~DBContactsImpl() = default;
};
