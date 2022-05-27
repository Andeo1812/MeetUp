#pragma once  //  NOLINT

#include <string>
#include <functional>

#include "Context.hpp"

#include "APIKeys.hpp"

template<typename T>
constexpr auto get_data = [](auto method, auto *object, const auto &json, const auto &field) -> void {
    if (json.contains(field)) {
        (object->*method)(json[field].template get<T>());
    }
};

constexpr auto get_json = [](auto method, const auto &object, auto *json, const auto &field) -> void {
    std::string field_data = (object.*method)();

    if (!field_data.empty()) {
        (*json)[field] = field_data;
    }
};

class Parser {
 public:
    virtual Context StrToObject(const std::string &parser_str) const = 0;

    virtual std::string ObjectToStr(const std::string type_response, const Context &other) const = 0;

    virtual ~Parser() = default;
};
