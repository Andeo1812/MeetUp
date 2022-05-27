#pragma once  //  NOLINT

#include <string>

class PersonalData {
    std::string user_id;
    std::string name;
    std::string surname;
    std::string email;
    std::string date_birth;
    std::string phone_number;

 public:
    bool IsEmpty() const noexcept;

    void SetUserId(const std::string &user_id) noexcept;
    void SetName(const std::string &name) noexcept;
    void SetSurname(const std::string &surname) noexcept;
    void SetEmail(const std::string &email) noexcept;
    void SetDateBirth(const std::string &date_birth) noexcept;
    void SetPhoneNumber(const std::string &phone_number) noexcept;

    std::string &GetUserId() noexcept;
    std::string &GetName() noexcept;
    std::string &GetSurname() noexcept;
    std::string &GetEmail() noexcept;
    std::string &GetDateBirth() noexcept;
    std::string &GetPhoneNumber() noexcept;

    const std::string &AccessUserId() const noexcept;
    const std::string &AccessName() const noexcept;
    const std::string &AccessSurname() const noexcept;
    const std::string &AccessEmail() const noexcept;
    const std::string &AccessDateBirth() const noexcept;
    const std::string &AccessPhoneNumber() const noexcept;

    PersonalData() = default;
    virtual ~PersonalData() = default;

    friend std::ostream&  operator<<(std::ostream &os, const PersonalData &it) noexcept;
};
