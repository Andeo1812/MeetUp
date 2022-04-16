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
    bool IsEmpty();

    void SetUserId(const std::string &user_id);
    void SetBuilding(const std::string &building);
    void SetHousing(const std::string &housing);
    void SetCity(const std::string &city);
    void SetDistrict(const std::string &district);
    void SetIndex(const std::string &index);
    void SetCountry(const std::string &country);

    std::string GetUserId() const;
    std::string GetBuilding() const;
    std::string GetHousing() const;
    std::string GetCity() const;
    std::string GetDistrict() const;
    std::string GetIndex() const;
    std::string GetCountry() const;

    AddressData() = default;
    virtual ~AddressData() = default;

    void Print() const;
};


