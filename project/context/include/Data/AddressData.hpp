#pragma once  //  NOLINT

#include <string>

class AddressData {
    std::string user_id;
    std::string building;
    std::string housing;
    std::string street;
    std::string city;
    std::string district;
    std::string index;
    std::string country;

 public:
    bool IsEmpty() const noexcept;

    void SetUserId(const std::string &user_id) noexcept;
    void SetBuilding(const std::string &building) noexcept;
    void SetHousing(const std::string &housing) noexcept;
    void SetStreet(const std::string &street) noexcept;
    void SetCity(const std::string &city) noexcept;
    void SetDistrict(const std::string &district) noexcept;
    void SetIndex(const std::string &index) noexcept;
    void SetCountry(const std::string &country) noexcept;

    std::string GetUserId() const noexcept;
    std::string GetBuilding() const noexcept;
    std::string GetHousing() const noexcept;
    std::string GetStreet() const noexcept;
    std::string GetCity() const noexcept;
    std::string GetDistrict() const noexcept;
    std::string GetIndex() const noexcept;
    std::string GetCountry() const noexcept;

    AddressData() = default;
    virtual ~AddressData() = default;

    friend std::ostream&  operator<<(std::ostream &os, const AddressData &it) noexcept;
};
