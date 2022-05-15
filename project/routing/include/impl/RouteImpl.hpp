#pragma once  //  NOLINT

#include "Route.hpp"

#include <queue>
#include <thread>
#include <vector>

struct NodeMap {
    std::unique_ptr<const Parser> parser;
    std::unique_ptr<const Handler> handler;

    NodeMap(const Parser *parser, const Handler *handler) : parser(parser), handler(handler) {};
};

struct NodeResponse {
    const std::string request;
    std::string response;

    NodeResponse(const std::string &request) : request(request) {};
};


template<class ClassDBManager>
class RouteImpl : public Route<ClassDBManager> {
    std::queue<std::string> tasks;

    std::map<const std::string, NodeMap> route_map;

    const ClassDBManager db_manager;

    std::vector<std::thread> workers;

    std::queue<NodeResponse> responses;

 public:
    void InsertTask(const std::string &task) override;

    std::string GetHeadRequest(const std::string &request_body) const override;

    std::string HandlingTask(const std::string &request_body) const override;

    std::string GetResTask(const std::string &request_body) override;

    RouteImpl();
    RouteImpl(const RouteImpl &other) = default;
    ~RouteImpl() = default;
};

#include "RouteImplDefinition.hpp"

