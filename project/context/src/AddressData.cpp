#include <iostream>

#include "AddressData.hpp"

bool AddressData::IsEmpty() const noexcept {
    if (this->user_id.empty() && this->building.empty() &&
        this->housing.empty() && this->street.empty() &&
        this->city.empty() && this->district.empty() &&
        this->index.empty() && this->country.empty()) {
            return true;
    }

    return false;
}

void AddressData::SetUserId(const std::string &user_id) noexcept {
    this->user_id = user_id;
}

void AddressData::SetBuilding(const std::string &building) noexcept {
    this->building = building;
}

void AddressData::SetHousing(const std::string &housing) noexcept {
    this->housing = housing;
}

void AddressData::SetCity(const std::string &city) noexcept {
    this->city = city;
}

void AddressData::SetDistrict(const std::string &district) noexcept {
    this->district = district;
}

void AddressData::SetIndex(const std::string &index) noexcept {
    this->index = index;
}

void AddressData::SetCountry(const std::string &country) noexcept {
    this->country = country;
}

std::string AddressData::GetUserId() const noexcept {
    return this->user_id;
}

std::string AddressData::GetBuilding() const noexcept {
    return this->building;
}

std::string AddressData::GetHousing() const noexcept {
    return this->housing;
}

std::string AddressData::GetStreet() const noexcept {
    return this->street;
}

std::string AddressData::GetCity() const noexcept {
    return this->city;
}

std::string AddressData::GetDistrict() const noexcept {
    return this->district;
}

std::string AddressData::GetIndex() const noexcept {
    return this->index;
}

std::string AddressData::GetCountry() const noexcept {
    return this->country;
}

void operator<<(std::ostream &os, const AddressData &it) noexcept {
    os << "-------------------------------------------------------------------------" << std::endl;
    os << "Address Data" << std::endl;
    os << "user_id          :---: " << it.user_id << std::endl;
    os << "building         :---: " << it.building << std::endl;
    os << "housing          :---: " << it.housing << std::endl;
    os << "street           :---: " << it.street << std::endl;
    os << "city             :---: " << it.city << std::endl;
    os << "district         :---: " << it.district << std::endl;
    os << "index            :---: " << it.index << std::endl;
    os << "country          :---: " << it.country << std::endl;
}
