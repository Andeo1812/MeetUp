#pragma once  //  NOLINT

#include <map>

#include "Handler.hpp"

#include "Parser.hpp"

class Route {
 public:
    std::map <std::string, std::pair<Parser*, Handler*>> route_map;

    virtual std::string get_head(const std::string request_body) = 0;

    virtual std::string get_response(const std::string request_body) = 0;

    virtual ~Route() = default;
};
