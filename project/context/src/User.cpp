#include <iostream>

#include "User.hpp"

bool User::IsEmpty() const noexcept {
    return this->id.empty() && this->password.empty() &&
           this->nickname.empty();
}

void User::SetId(const std::string &id) noexcept {
    this->id = id;
}

void User::SetPassword(const std::string &password) noexcept {
    this->password = password;
}

void User::SetNickname(const std::string &nickname) noexcept {
    this->nickname = nickname;
}

std::string User::GetId() const noexcept {
    return this->id;
}

std::string User::GetPassword() const noexcept {
    return this->password;
}

std::string User::GetNickname() const noexcept {
    return this->nickname;
}

std::ostream&  operator<<(std::ostream &os, const User &it) noexcept {
    os << "-------------------------------------------------------------------------" << std::endl;
    os << "User" << std::endl;
    os << "user_id           :---: " << it.id << std::endl;
    os << "password          :---: " << it.password << std::endl;
    os << "nickname          :---: " << it.nickname << std::endl;

    return os;
}
