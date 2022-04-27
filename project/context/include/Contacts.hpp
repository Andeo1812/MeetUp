#pragma once  //  NOLINT

#include <string>
#include <set>

class Contacts {
    std::string user_id;
    std::set<std::string> contacts;
public:
    bool IsEmpty() const noexcept;

    void SetUserId(const std::string &user_id) noexcept;
    void SetContacts(const std::set<std::string> &contacts) noexcept;

    std::string GetUserId() const noexcept;
    std::set<std::string> GetContacts() const noexcept;

    Contacts() = default;
    virtual ~Contacts() = default;

    friend void operator<<(std::ostream &os, const Contacts &it) noexcept;
};
