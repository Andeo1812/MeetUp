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

    std::string &GetId() noexcept;
    std::string &GetPassword() noexcept;
    std::string &GetNickname() noexcept;

    const std::string &AccessId() const noexcept;
    const std::string &AccessPassword() const noexcept;
    const std::string &AccessNickname() const noexcept;

    User() = default;
    virtual ~User() = default;

    friend std::ostream&  operator<<(std::ostream &os, const User &it) noexcept;
};
