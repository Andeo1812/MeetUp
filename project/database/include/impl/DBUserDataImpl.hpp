#pragma once  //  NOLINT

#include "DBUserData.hpp"

template<class ClassConnection>
class DBUserDataImplDefinition : public DBUserData<ClassConnection> {
 public:
    int AddressDataReWrite(const AddressData &address_data, ClassConnection *connection) const override;
    AddressData GetAddressData(const std::string &user_id, ClassConnection *connection) const override;

    int PersonalDataReWrite(const PersonalData &personal_data, ClassConnection *connection) const override;
    PersonalData GetPersonalData(const std::string &user_id, ClassConnection *connection) const override;

    int GeneralDataReWrite(const GeneralData &general_data, ClassConnection *connection) const override;
    GeneralData GetGeneralData(const std::string &user_id, ClassConnection *connection) const override;

    int ReWritePassword(const std::string &user_id, ClassConnection *connection) const override;
    int ReWriteNickname(const std::string &user_id, ClassConnection *connection) const override;

    DBUserDataImplDefinition() = default;
    ~DBUserDataImplDefinition() = default;
};

#include "DBUserDataImplDefinition.hpp"
