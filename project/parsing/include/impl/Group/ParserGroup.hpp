#pragma once  //  NOLINT

#include "Parser.hpp"

class ParserGroup: public Parser {
 public:
    Context StrToObject(const std::string& parser_str) const override;

    std::string ObjectToStr(const std::string type_response, const Context& other) const override;

    ~ParserGroup() = default;
};

class ParserUserGroup: public Parser {
 public:
    Context StrToObject(const std::string& parser_str) const override;

    std::string ObjectToStr(const std::string type_response, const Context& other) const override;

    ~ParserUserGroup() = default;
};
