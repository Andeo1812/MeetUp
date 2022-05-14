#pragma once  //  NOLINT

#include <map>
#include <queue>
#include <thread>

#include "Handler.hpp"

#include "Parser.hpp"

struct NodeMap {
    const Parser *parser;
    const Handler *handler;

    NodeMap(const Parser *parser, const Handler *handler) : parser(parser), handler(handler) {};
};

struct NodeResponse {
    const std::string request;
    const std::string response;

    NodeResponse(const std::string &request, const Handler *handler) : request(request) {};
};

template<class ClassDBManager>
class Route {
 public:
    virtual void InsertTask(const std::string &task) = 0;

    virtual std::string GetHeadRequest(const std::string &request_body) const = 0;

    virtual std::string HandlingTask(const std::string &request_body) const = 0;

    virtual std::string GetResTask(const std::string &request_body) = 0;

    virtual ~Route() = default;
};
