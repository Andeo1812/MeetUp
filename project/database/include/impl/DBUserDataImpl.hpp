#pragma once  //  NOLINT

#include "DBUserData.hpp"

class DBUserDataImpl : public DBUserData {
 public:
    int AddressDataReWrite(const AddressData &address_data) const override;
    AddressData GetAddressData(const std::string &user_id) const override;

    int PersonalDataReWrite(const PersonalData &personal_data) const override;
    PersonalData GetPersonalData(const std::string &user_id) const override;

    int GeneralDataReWrite(const GeneralData &general_data) const override;
    GeneralData GetGeneralData(const std::string &user_id) const override;

    int ReWritePassword(const std::string &user_id) const override;
    int ReWriteNickname(const std::string &user_id) const override;

    DBUserDataImpl() = default;
    ~DBUserDataImpl() = default;
};
