#include <nlohmann/json.hpp>

#include "ParserAddressData.hpp"

Context ParserAddressData::StrToObject(const std::string& parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json value = j[j.begin().key()];

    AddressData address_data;

    if (value.contains("user_id")) {
        address_data.SetUserId(value["user_id"].get<std::string>());
    }

    if (value.contains("building")) {
        address_data.SetBuilding(value["building"].get<std::string>());
    }

    if (value.contains("housing")) {
        address_data.SetHousing(value["housing"].get<std::string>());
    }

    if (value.contains("street")) {
        address_data.SetStreet(value["street"].get<std::string>());
    }

    if (value.contains("city")) {
        address_data.SetCity(value["city"].get<std::string>());
    }

    if (value.contains("district")) {
        address_data.SetDistrict(value["district"].get<std::string>());
    }

    if (value.contains("index")) {
        address_data.SetIndex(value["index"].get<std::string>());
    }

    if (value.contains("country")) {
        address_data.SetCountry(value["country"].get<std::string>());
    }

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
