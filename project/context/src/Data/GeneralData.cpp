#include <iostream>

#include "GeneralData.hpp"

bool GeneralData::IsEmpty() const noexcept {
    if (this->user_id.empty() && this->status.empty() &&
        this->tags.empty() && this->description.empty() &&
        this->nickname.empty()) {
            return true;
    }

    return false;
}

void GeneralData::SetUserId(const std::string &user_id) noexcept {
    this->user_id = user_id;
}

void GeneralData::SetStatus(const std::string &status) noexcept {
    this->status = status;
}

void GeneralData::SetTags(const std::string &tags) noexcept {
    this->tags = tags;
}

void GeneralData::SetDescription(const std::string &description) noexcept {
    this->description = description;
}

void GeneralData::SetNickname(const std::string &nickname) noexcept {
    this->nickname = nickname;
}

std::string GeneralData::GetUserId() const noexcept {
    return this->user_id;
}

std::string GeneralData::GetStatus() const noexcept {
    return this->status;
}

std::string GeneralData::GetTags() const noexcept {
    return this->tags;
}

std::string GeneralData::GetDescription() const noexcept {
    return this->description;
}

std::string GeneralData::GetNickname() const noexcept {
    return this->nickname;
}

void operator<<(std::ostream &os, const GeneralData &it) noexcept {
    os << "-------------------------------------------------------------------------" << std::endl;
    os << "General Data" << std::endl;
    os << "user_id          :---: " << it.user_id << std::endl;
    os << "status           :---: " << it.status << std::endl;
    os << "label            :---: " << it.tags << std::endl;
    os << "description      :---: " << it.description << std::endl;
    os << "nickname         :---: " << it.nickname << std::endl;
}
