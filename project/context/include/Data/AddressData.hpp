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

    std::string &GetUserId() noexcept;
    std::string &GetBuilding() noexcept;
    std::string &GetHousing() noexcept;
    std::string &GetStreet() noexcept;
    std::string &GetCity() noexcept;
    std::string &GetDistrict() noexcept;
    std::string &GetIndex() noexcept;
    std::string &GetCountry() noexcept;

    const std::string &AccessUserId() const noexcept;
    const std::string &AccessBuilding() const noexcept;
    const std::string &AccessHousing() const noexcept;
    const std::string &AccessStreet() const noexcept;
    const std::string &AccessCity() const noexcept;
    const std::string &AccessDistrict() const noexcept;
    const std::string &AccessIndex() const noexcept;
    const std::string &AccessCountry() const noexcept;

    AddressData() = default;
    virtual ~AddressData() = default;

    friend std::ostream&  operator<<(std::ostream &os, const AddressData &it) noexcept;
};
