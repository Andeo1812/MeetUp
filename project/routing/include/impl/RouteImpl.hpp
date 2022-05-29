#pragma once  //  NOLINT

#include "Route.hpp"

#include <queue>
#include <thread>  //  NOLINT
#include <vector>
#include <condition_variable>  //  NOLINT
#include <mutex>  //  NOLINT
#include <unordered_map>

template<typename connection_>
struct NodeMap {
    std::unique_ptr<const Parser> parser;
    std::unique_ptr<const Handler<connection_>> handler;

    NodeMap(const Parser *parser, const Handler<connection_> *handler) : parser(parser), handler(handler) {}
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

    std::unordered_map<std::string, std::string> responses;

    std::string GetHeadRequest(const std::string &request_body) const;
    std::string HandlingTask(const std::string &request_body, ClassDBWorker *db_worker) const;

    void run_thread(ClassDBWorker *db_worker);

    std::string GetTask();

    void InsertResponse(const std::string &response, const std::string &task);

    std::atomic<bool> status_work{ false };

    std::condition_variable cv;
    std::mutex queue_mtx;

    std::condition_variable completed_task_cv;
    std::mutex completed_task_mtx;

    void WaitAll();

 public:
    void InsertTask(const std::string &task) override;

    std::tuple<int, std::string> GetResTask(const std::string &request_body) override;

    RouteImpl();
    RouteImpl(const RouteImpl &other) = default;
    ~RouteImpl();
};

#include "RouteImplDefinition.hpp"
#include "MultithreadingRouteImplDefinition.hpp"
