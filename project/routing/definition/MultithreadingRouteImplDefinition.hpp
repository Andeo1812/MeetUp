#pragma once  //  NOLINT

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::~RouteImpl() {
    status_work = false;

    cv.notify_all();

    for (size_t i = 0; i < workers.size(); ++i) {
        workers[i].join();
    }
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
void RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::InsertTask(const std::string &task) {
    tasks.push(task);

    cv.notify_all();
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
std::string RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::GetResTask(const std::string &request_body) {
//    std::string result = HandlingTask(tasks.front(), db_manager.GetFreeWorker(0));
//
//    responses.insert({tasks.front(), NodeResponse(result)});
//
//    tasks.pop();

    auto needed_node = responses.find(tasks.front());

    std::string result = needed_node->second.response;

    if (!result.empty()) {
        responses.erase(needed_node);
    }

    return result;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
std::string RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::GetTask() {
    std::string task = tasks.front();
    tasks.pop();

    responses.insert({task, NodeResponse()});

    return task;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
void RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::InsertResponse(const std::string &response, const std::string &task) {
    auto needed_node = responses.find(task);

    needed_node->second.response = response;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
void RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::run_thread(ClassDBWorker *db_worker) {
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    while (status_work) {
        std::unique_lock<std::mutex> ul(queue_lock);
        cv.wait(ul, [&]() { return !tasks.empty() && status_work; });

        task_lock.lock();
        std::string task = GetTask();
        task_lock.unlock();

        std::string response = HandlingTask(task, db_worker);

        response_lock.lock();
        InsertResponse(response, task);
        response_lock.unlock();
    }
}
