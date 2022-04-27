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

    std::string GetUserId() const noexcept;
    std::string GetName() const noexcept;
    std::string GetSurname() const noexcept;
    std::string GetEmail() const noexcept;
    std::string GetDateBirth() const noexcept;
    std::string GetPhoneNumber() const noexcept;

    PersonalData() = default;
    virtual ~PersonalData() = default;

    friend void operator<<(std::ostream &os, const PersonalData &it) noexcept;
};
