#pragma once  //  NOLINT

#include <string>
#include <set>

class Contacts {
    std::string user_id;
    std::set<std::string> contacts;
public:
    bool IsEmpty();

    void SetUserId(const std::string &user_id);
    void SetContacts(const std::set<std::string> &contacts);

    std::string GetUserId();
    std::set<std::string> GetContacts() const;

    Contacts() = default;
    virtual ~Contacts() = default;


    void Print() const;
};
