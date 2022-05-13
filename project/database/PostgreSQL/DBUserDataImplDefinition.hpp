#pragma once  //  NOLINT

#include "DBUserDataImpl.hpp"

template<typename ClassConnection>
int DBUserDataImplDefinition<ClassConnection>::AddressDataReWrite(const AddressData &address_data, ClassConnection *connection) const {
    return EXIT_SUCCESS;
}

template<typename ClassConnection>
AddressData DBUserDataImplDefinition<ClassConnection>::GetAddressData(const std::string &user_id, ClassConnection *connection) const {
    AddressData res;
    return res;
}

template<typename ClassConnection>
int DBUserDataImplDefinition<ClassConnection>::PersonalDataReWrite(const PersonalData &personal_data, ClassConnection *connection) const {
    return EXIT_SUCCESS;
}

template<typename ClassConnection>
PersonalData DBUserDataImplDefinition<ClassConnection>::GetPersonalData(const std::string &user_id, ClassConnection *connection) const {
    PersonalData res;
    return res;
}

template<typename ClassConnection>
int DBUserDataImplDefinition<ClassConnection>::GeneralDataReWrite(const GeneralData &general_data, ClassConnection *connection) const {
    return EXIT_SUCCESS;
}

template<typename ClassConnection>
GeneralData DBUserDataImplDefinition<ClassConnection>::GetGeneralData(const std::string &user_id, ClassConnection *connection) const {
    GeneralData res;
    return res;
}

template<typename ClassConnection>
int DBUserDataImplDefinition<ClassConnection>::ReWritePassword(const std::string &user_id, ClassConnection *connection) const {
    return EXIT_SUCCESS;
}

template<typename ClassConnection>
int DBUserDataImplDefinition<ClassConnection>::ReWriteNickname(const std::string &user_id, ClassConnection *connection) const {
    return EXIT_SUCCESS;
}
