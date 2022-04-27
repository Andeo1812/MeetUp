#pragma once  //  NOLINT

#include <string>

class User {
    std::string user_id;
    std::string password;
    std::string nickname;

 public:
    bool IsEmpty() const noexcept;

    void SetUserId(const std::string &user_id) noexcept;
    void SetPassword(const std::string &password) noexcept;
    void SetNickname(const std::string &nickname) noexcept;

    std::string GetUserId() const noexcept;
    std::string GetPassword() const noexcept;
    std::string GetNickname() const noexcept;

    User() = default;
    virtual ~User() = default;

    friend void operator<<(std::ostream &os, const User &it) noexcept;
};
