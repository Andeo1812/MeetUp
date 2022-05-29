#pragma once  //  NOLINT

#include "RouteImpl.hpp"

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
void RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::WaitAll() {
    std::unique_lock<std::mutex> lock(queue_mtx);

    completed_task_cv.wait(lock, [this](){
        std::lock_guard<std::mutex> task_lock(completed_task_mtx);
        return tasks.empty();
    });
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::~RouteImpl() {
    WaitAll();

    status_work = true;

    for (size_t i = 0; i < workers.size(); ++i) {
        cv.notify_all();
        workers[i].join();
    }
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
void RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::InsertTask(const std::string &task) {
    std::lock_guard<std::mutex> q_lock(queue_mtx);
    tasks.push(task);

    responses.insert({task, {}});

    cv.notify_one();
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
std::tuple<int, std::string>  RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::GetResTask(const std::string &request_body) {
    std::lock_guard<std::mutex> lock(completed_task_mtx);
    auto needed_node = responses.find(request_body);

    std::string result = needed_node->second;

    if (!result.empty()) {
        responses.erase(needed_node);

        return std::make_tuple(1, result);
    }

    return std::make_tuple(0, "");
}


template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
void RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::InsertResponse(const std::string &response, const std::string &task) {
    auto needed_node = responses.find(task);

    needed_node->second = response;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
std::string RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::GetTask() {
    std::string task = std::move(tasks.front());

    tasks.pop();

    return task;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
void RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::run_thread(ClassDBWorker *db_worker) {
    while (!status_work) {
        std::unique_lock<std::mutex> lock(queue_mtx);
        cv.wait(lock, [this]() { return !tasks.empty() || status_work; });

        if (!tasks.empty()) {
            auto task = GetTask();
            lock.unlock();

            std::string response = HandlingTask(task, db_worker);

            std::lock_guard<std::mutex> lock(completed_task_mtx);
            InsertResponse(response, task);

            completed_task_cv.notify_all();
        }
    }
}
