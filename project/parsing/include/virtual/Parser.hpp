#pragma once  //  NOLINT

#include <string>

#include "Context.hpp"

#define GLOBAL_KEY_TEST_PARSER true

class Parser {
 public:
    virtual Context StrToObject(const std::string& parser_str) const = 0;

    virtual std::string ObjectToStr(const std::string type_response, const Context& other) const = 0;

    virtual ~Parser() = default;
};
