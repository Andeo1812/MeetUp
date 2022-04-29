#pragma once  //  NOLINT

#include <string>

#include "AddressData.hpp"
#include "PersonalData.hpp"
#include "GeneralData.hpp"

class DBUserData {
 public:
    virtual int AddressDataReWrite(const AddressData &address_data) const = 0;
    virtual AddressData GetAddressData(const std::string &user_id) const = 0;

    virtual int PersonalDataReWrite(const PersonalData &personal_data) const = 0;
    virtual PersonalData GetPersonalData(const std::string &user_id) const = 0;

    virtual int GeneralDataReWrite(const GeneralData &general_data) const = 0;
    virtual GeneralData GetGeneralData(const std::string &user_id) const = 0;

    virtual int ReWritePassword(const std::string &user_id) const = 0;
    virtual int ReWriteNickname(const std::string &user_id) const = 0;

    virtual ~DBUserData() = default;
};
