#include <iostream>

#include "User.hpp"

bool User::IsEmpty() const noexcept {
    if (this->user_id.empty() && this->password.empty() &&
        this->nickname.empty()) {
            return true;
    }

    return false;
}

void User::SetUserId(const std::string &user_id) noexcept {
    this->user_id = user_id;
}

void User::SetPassword(const std::string &password) noexcept {
    this->password = password;
}

void User::SetNickname(const std::string &nickname) noexcept {
    this->nickname = nickname;
}

std::string User::GetUserId() const noexcept {
    return this->user_id;
}

std::string User::GetPassword() const noexcept {
    return this->password;
}

std::string User::GetNickname() const noexcept {
    return this->nickname;
}

void operator<<(std::ostream &os, const User &it) noexcept {
    os << "-------------------------------------------------------------------------" << std::endl;
    os << "User" << std::endl;
    os << "user_id           :---: " << it.user_id << std::endl;
    os << "password          :---: " << it.password << std::endl;
    os << "nickname          :---: " << it.nickname << std::endl;
}
