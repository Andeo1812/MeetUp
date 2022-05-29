#pragma once  //  NOLINT

#include "Route.hpp"

#include <queue>
#include <thread>  //  NOLINT
#include <vector>
//    #include <condition_variable>
//    #include <mutex>

template<typename connection_>
struct NodeMap {
    std::unique_ptr<const Parser> parser;
    std::unique_ptr<const Handler<connection_>> handler;

    NodeMap(const Parser *parser, const Handler<connection_> *handler) : parser(parser), handler(handler) {}
};

struct NodeResponse {
    std::string response;

    explicit NodeResponse(const std::string &response) : response(response) {}
    NodeResponse() = default;
};


template<typename T = pqxx::connection,
        class ClassConnection = DBConnection<T>,
        class ClassDBMethods = DBMethods<T, ClassConnection>,
        class ClassDBWorker = DBWorker<T, ClassConnection, ClassDBMethods>,
        class ClassDBManager = DBManager<T, ClassConnection, ClassDBMethods, ClassDBWorker>>
class RouteImpl : public Route<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager> {
    std::queue<std::string> tasks;

    std::map<const std::string_view, NodeMap<T>> route_map;

    ClassDBManager db_manager;

    std::vector<std::thread> workers;

    std::map<const std::string, NodeResponse> responses;

//    void run_thread();
//
//    std::string &GetTask();
//
//    void InsertResponse(const std::string &response, const std::string &task);
//
//    bool data;
//
//    std::condition_variable cv;
//
//    std::mutex queue_lock;
//
//    std::mutex task_lock;
//
//    std::mutex response_lock;

 public:
    void InsertTask(const std::string &task) override;

    std::string GetHeadRequest(const std::string &request_body) const override;

    std::string HandlingTask(const std::string &request_body, ClassDBWorker *db_worker) const override;

    std::string GetResTask(const std::string &request_body) override;

    RouteImpl();
    RouteImpl(const RouteImpl &other) = default;
    ~RouteImpl() = default;
};

#include "RouteImplDefinition.hpp"
