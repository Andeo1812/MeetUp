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

    if (!other.GetError().empty()) {
        j[type_response] = other.GetError();

        res = j.dump();

        return res;
    }

    if (type_response == WRITE_ADDRESS) {
        j[type_response] = "OK";

        res = j.dump();

        return res;
    }

    AddressData address_data = other.GetAddressData();

    nlohmann::json value;

    if (!address_data.GetUserId().empty()) {
        value["user_id"] = address_data.GetUserId();
    }

    if (!address_data.GetBuilding().empty()) {
        value["building"] = address_data.GetBuilding();
    }

    if (!address_data.GetHousing().empty()) {
        value["housing"] = address_data.GetHousing();
    }

    if (!address_data.GetStreet().empty()) {
        value["street"] = address_data.GetStreet();
    }

    if (!address_data.GetCity().empty()) {
        value["city"] = address_data.GetCity();
    }

    if (!address_data.GetDistrict().empty()) {
        value["district"] = address_data.GetDistrict();
    }

    if (!address_data.GetIndex().empty()) {
        value["index"] = address_data.GetIndex();
    }

    if (!address_data.GetCountry().empty()) {
        value["country"] = address_data.GetCountry();
    }

    j[type_response] = value;

    res = j.dump();

    return res;
}
