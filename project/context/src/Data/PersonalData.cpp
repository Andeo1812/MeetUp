#include <iostream>

#include "PersonalData.hpp"

bool PersonalData::IsEmpty() const noexcept {
    return this->user_id.empty() && this->name.empty() &&
           this->surname.empty() && this->email.empty() &&
           this->date_birth.empty() && this->phone_number.empty();
}

void PersonalData::SetUserId(const std::string &user_id) noexcept {
    this->user_id = user_id;
}

void PersonalData::SetName(const std::string &name) noexcept {
    this->name = name;
}

void PersonalData::SetSurname(const std::string &surname) noexcept {
    this->surname = surname;
}

void PersonalData::SetEmail(const std::string &email) noexcept {
    this->email = email;
}

void PersonalData::SetDateBirth(const std::string &date_birth) noexcept {
    this->date_birth = date_birth;
}

void PersonalData::SetPhoneNumber(const std::string &phone_number) noexcept {
    this->phone_number = phone_number;
}

std::string &PersonalData::GetUserId() noexcept {
    return this->user_id;
}

std::string &PersonalData::GetName() noexcept {
    return this->name;
}

std::string &PersonalData::GetSurname() noexcept {
    return this->surname;
}

std::string &PersonalData::GetEmail() noexcept {
    return this->email;
}

std::string &PersonalData::GetDateBirth() noexcept {
    return this->date_birth;
}

std::string &PersonalData::GetPhoneNumber() noexcept {
    return this->phone_number;
}

std::ostream& operator<<(std::ostream &os, const PersonalData &it) noexcept {
    os << "-------------------------------------------------------------------------" << std::endl;
    os << "Personal Data" << std::endl;
    os << "user_id          :---: " << it.user_id << std::endl;
    os << "name             :---: " << it.name << std::endl;
    os << "email            :---: " << it.email << std::endl;
    os << "surname          :---: " << it.surname << std::endl;
    os << "age              :---: " << it.date_birth << std::endl;
    os << "phone_number     :---: " << it.phone_number << std::endl;

    return os;;
}
