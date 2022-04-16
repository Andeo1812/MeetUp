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
    bool IsEmpty();

    void SetUserId(const std::string &user_id);
    void SetName(const std::string &name);
    void SetSurname(const std::string &surname);
    void SetEmail(const std::string &email);
    void SetDateBirth(const std::string &date_birth);
    void SetPhoneNumber(const std::string &phone_number);

    std::string SetUserId() const;
    std::string SetName() const;
    std::string SetSurname() const;
    std::string SetEmail() const;
    std::string SetDateBirth() const;
    std::string SetPhoneNumber() const;

    PersonalData() = default;
    virtual ~PersonalData() = default;

    void Print() const;
};
