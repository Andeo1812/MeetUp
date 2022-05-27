#include <iostream>

#include "AddressData.hpp"

bool AddressData::IsEmpty() const noexcept {
    return this->user_id.empty() && this->building.empty() &&
           this->housing.empty() && this->street.empty() &&
           this->city.empty() && this->district.empty() &&
           this->index.empty() && this->country.empty();
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

void AddressData::SetStreet(const std::string &street) noexcept {
    this->street = street;
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

std::string &AddressData::GetUserId() noexcept {
    return this->user_id;
}

std::string &AddressData::GetBuilding() noexcept {
    return this->building;
}

std::string &AddressData::GetHousing() noexcept {
    return this->housing;
}

std::string &AddressData::GetStreet() noexcept {
    return this->street;
}

std::string &AddressData::GetCity() noexcept {
    return this->city;
}

std::string &AddressData::GetDistrict() noexcept {
    return this->district;
}

std::string &AddressData::GetIndex() noexcept {
    return this->index;
}

std::string &AddressData::GetCountry() noexcept {
    return this->country;
}

std::ostream&  operator<<(std::ostream &os, const AddressData &it) noexcept {
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

    return os;
}

const std::string &AddressData::AccessUserId() const noexcept {
    return this->user_id;
}

const std::string &AddressData::AccessBuilding() const noexcept {
    return this->building;
}

const std::string &AddressData::AccessHousing() const noexcept {
    return this->housing;
}

const std::string &AddressData::AccessStreet() const noexcept {
    return this->street;
}

const std::string &AddressData::AccessCity() const noexcept {
    return this->city;
}

const std::string &AddressData::AccessDistrict() const noexcept {
    return this->district;
}

const std::string &AddressData::AccessIndex() const noexcept {
    return this->index;
}

const std::string &AddressData::AccessCountry() const noexcept {
    return this->country;
}
