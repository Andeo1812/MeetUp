#include <nlohmann/json.hpp>

#include "ParserAddressData.hpp"

Context ParserAddressData::StrToObject(const std::string& parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json value = j[j.begin().key()];

    AddressData address_data;

    get_data<std::string>(&AddressData::SetUserId,   &address_data, value, "user_id");
    get_data<std::string>(&AddressData::SetBuilding, &address_data, value, "building");
    get_data<std::string>(&AddressData::SetHousing,  &address_data, value, "housing");
    get_data<std::string>(&AddressData::SetStreet,   &address_data, value, "street");
    get_data<std::string>(&AddressData::SetCity,     &address_data, value, "city");
    get_data<std::string>(&AddressData::SetDistrict, &address_data, value, "district");
    get_data<std::string>(&AddressData::SetIndex,    &address_data, value, "index");
    get_data<std::string>(&AddressData::SetCountry,  &address_data, value, "country");

    return address_data;
}

std::string ParserAddressData::ObjectToStr(const std::string type_response, const Context& other) const {
    nlohmann::json j;

    std::string res;

    if (!other.AccessError().empty()) {
        j[type_response] = other.AccessError();

        res = j.dump();

        return res;
    }

    if (type_response == WRITE_ADDRESS) {
        j[type_response] = "OK";

        res = j.dump();

        return res;
    }

    AddressData address_data = other.AccessAddressData();

    nlohmann::json value;

    get_json(&AddressData::AccessUserId,   address_data, &value, "user_id");
    get_json(&AddressData::AccessBuilding, address_data, &value, "building");
    get_json(&AddressData::AccessHousing,  address_data, &value, "housing");
    get_json(&AddressData::AccessStreet,   address_data, &value, "street");
    get_json(&AddressData::AccessCity,     address_data, &value, "city");
    get_json(&AddressData::AccessDistrict, address_data, &value, "district");
    get_json(&AddressData::AccessIndex,    address_data, &value, "index");
    get_json(&AddressData::AccessCountry,  address_data, &value, "country");

    j[type_response] = value;

    res = j.dump();

    return res;
}
