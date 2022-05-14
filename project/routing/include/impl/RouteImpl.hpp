#pragma once  //  NOLINT

#include "Route.hpp"

template<class ClassDBManager>
class RouteImpl : public Route<ClassDBManager> {
 public:
    std::queue<std::string> tasks;

    std::map<std::string, NodeMap> route_map;

    const ClassDBManager db_manager;

    std::vector<std::thread> workers;

    std::queue<NodeResponse> responses;

    void InsertTask(const std::string &task) override;

    std::string GetHeadRequest(const std::string &request_body) const override;

    std::string HandlingTask(const std::string &request_body) const override;

    std::string GetResTask(const std::string &request_body) override;

    RouteImpl();
    RouteImpl(const RouteImpl &other) = default;
    ~RouteImpl() = default;
};

#include "RouteImplDefinition.hpp"

