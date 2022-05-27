#pragma once  //  NOLINT

#include "Route.hpp"

#include <queue>
#include <thread>  //  NOLINT
#include <vector>

template<typename connection>
struct NodeMap {
    std::unique_ptr<const Parser> parser;
    std::unique_ptr<const Handler<connection>> handler;

    NodeMap(const Parser *parser, const Handler<connection> *handler) : parser(parser), handler(handler) {}
};

struct NodeResponse {
    const std::string request;
    std::string response;

    explicit NodeResponse(const std::string &request) : request(request) {}
};


template<typename T,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = AllDBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>,
        class ClassDBManager = DBManager<T, ClassConnection, ClassDBMethods, ClassDBWorker>>
class RouteImpl : public Route<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager> {
    std::queue<std::string> tasks;

    std::map<const std::string_view, NodeMap<T>> route_map;

    const ClassDBManager db_manager;

    std::vector<std::thread> workers;

    std::queue<NodeResponse> responses;

 public:
    void InsertTask(const std::string &task) override;

    std::string GetHeadRequest(const std::string &request_body) const override;

    std::string HandlingTask(const std::string &request_body, const ClassDBWorker &db_worker) const override;

    std::string GetResTask(const std::string &request_body) override;

    RouteImpl();
    RouteImpl(const RouteImpl &other) = default;
    ~RouteImpl() = default;
};

#include "RouteImplDefinition.hpp"
