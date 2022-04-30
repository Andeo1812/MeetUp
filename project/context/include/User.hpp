#pragma once  //  NOLINT

#include <string>

class User {
    std::string id;
    std::string password;
    std::string nickname;

 public:
    bool IsEmpty() const noexcept;

    void SetId(const std::string &id) noexcept;
    void SetPassword(const std::string &password) noexcept;
    void SetNickname(const std::string &nickname) noexcept;

    std::string GetId() const noexcept;
    std::string GetPassword() const noexcept;
    std::string GetNickname() const noexcept;

    User() = default;
    virtual ~User() = default;

    friend std::ostream&  operator<<(std::ostream &os, const User &it) noexcept;
};
