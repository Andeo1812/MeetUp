#pragma once  //  NOLINT

//template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
//std::string &RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::GetTask() {
//    std::string task = tasks.front();
//    tasks.pop();
//
//    responses.insert({task, NodeResponse()});
//
//    return task;
//}
//
//template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
//void RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::InsertResponse(const std::string &response, const std::string &task) {
//    auto needed_node = responses.find(task);
//
//    needed_node->second.response = response;
//}

//template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker, class ClassDBManager>
//void RouteImpl<T, ClassConnection, ClassDBMethods, ClassDBWorker, ClassDBManager>::run_thread() {
//    while (true) {
//        std::unique_lock<std::mutex> ul(queue_lock);
//
//        cv.wait(ul, [=]() { return !tasks.empty(); });
//
//        task_lock.lock();
//
//        std::string task = GetTask();
//
//        task_lock.unlock();
//
//        std::string response = HandlingTask(task, db_worker);
//
//        response_lock.lock();
//
//        InsertResponse(response, task);
//
//        response_lock.unlock();
//    }
//}
