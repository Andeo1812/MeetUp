#pragma once  //  NOLINT

#include <map>

#include "Handler.hpp"

#include "Parser.hpp"

struct Node {
    const Parser *parser;
    const Handler *handler;

    Node(const Parser *parser, const Handler *handler) : parser(parser), handler(handler) {};
};

class Route {
 public:
    std::map<std::string, Node> route_map;

    virtual std::string get_head(const std::string request_body) = 0;

    virtual std::string get_response(const std::string request_body) = 0;

    virtual ~Route() = default;
};
