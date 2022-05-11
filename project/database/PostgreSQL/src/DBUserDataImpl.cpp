#include "DBUserDataImpl.hpp"

int DBUserDataImpl::AddressDataReWrite(const AddressData &address_data) const {
    return EXIT_SUCCESS;
}

AddressData DBUserDataImpl::GetAddressData(const std::string &user_id) const {
    AddressData res;
    return res;
}

int DBUserDataImpl::PersonalDataReWrite(const PersonalData &personal_data) const {
    return EXIT_SUCCESS;
}

PersonalData DBUserDataImpl::GetPersonalData(const std::string &user_id) const {
    PersonalData res;
    return res;
}

int DBUserDataImpl::GeneralDataReWrite(const GeneralData &general_data) const {
    return EXIT_SUCCESS;
}

GeneralData DBUserDataImpl::GetGeneralData(const std::string &user_id) const {
    GeneralData res;
    return res;
}

int DBUserDataImpl::ReWritePassword(const std::string &user_id) const {
    return EXIT_SUCCESS;
}

int DBUserDataImpl::ReWriteNickname(const std::string &user_id) const {
    return EXIT_SUCCESS;
}
