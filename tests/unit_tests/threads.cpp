#include <gtest/gtest.h>

#include <queue>
#include <string>
#include <thread>  //  NOLINT
#include <condition_variable>  //  NOLINT
#include <mutex>  //  NOLINT
#include <cmath>
#include <unordered_map>

class RouteImpl {
    std::queue<std::string> tasks;

    std::map<const std::string, std::string> route_map;

    std::vector<std::thread> workers;

    std::unordered_map<std::string, std::string> responses;


    void run_thread(std::string *massage);
    std::string GetTask();
    void InsertResponse(const std::string &response, const std::string &task);

    std::atomic<bool> status_work{ false };

    std::condition_variable cv;
    std::mutex queue_mtx;

    std::condition_variable completed_task_cv;
    std::mutex completed_task_mtx;

    void WaitAll();

 public:
    std::string message;

    void InsertTask(const std::string &task);

    std::tuple<int, std::string>  GetResTask(const std::string &request_body);

    RouteImpl();
    RouteImpl(const RouteImpl &other) = default;
    ~RouteImpl();
};

RouteImpl::RouteImpl() {
    message = {"Created"};

    size_t count = 5;

    workers.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        workers.emplace_back(&RouteImpl::run_thread, this, &message);
    }
}

RouteImpl::~RouteImpl() {
    WaitAll();

    status_work = true;

    for (size_t i = 0; i < workers.size(); ++i) {
        cv.notify_all();
        workers[i].join();
    }
}

void RouteImpl::WaitAll() {
    std::unique_lock<std::mutex> lock(queue_mtx);

    completed_task_cv.wait(lock, [this](){
        std::lock_guard<std::mutex> task_lock(completed_task_mtx);
        return tasks.empty();
    });
}

void RouteImpl::InsertTask(const std::string &task) {
    std::lock_guard<std::mutex> q_lock(queue_mtx);
    tasks.push(task);

    responses.insert({task, {}});

    cv.notify_one();
}

std::tuple<int, std::string> RouteImpl::GetResTask(const std::string &request_body) {
    std::lock_guard<std::mutex> lock(completed_task_mtx);
    auto needed_node = responses.find(request_body);

    std::string result = needed_node->second;

    if (!result.empty()) {
        responses.erase(needed_node);

        return std::make_tuple(1, result);
    }

    return std::make_tuple(0, "");
}

void RouteImpl::InsertResponse(const std::string &response, const std::string &task) {
    auto needed_node = responses.find(task);

    needed_node->second = response;
}

std::string RouteImpl::GetTask() {
    std::string task = std::move(tasks.front());

    tasks.pop();

    return task;
}

void RouteImpl::run_thread(std::string *message) {
    while (!status_work) {
        std::unique_lock<std::mutex> lock(queue_mtx);
        cv.wait(lock, [this]() { return !tasks.empty() || status_work; });

        if (!tasks.empty()) {
            auto task = GetTask();
            lock.unlock();

            std::this_thread::sleep_for(std::chrono::milliseconds(std::stoul(task)));

            std::this_thread::sleep_for(std::chrono::milliseconds(std::stoul(task) * std::stoul(task) / 1000 / 100));

            std::cout << task << " " << "It completed - " << std::this_thread::get_id() << " Also wait - " << std::stoul(task) * std::stoul(task) / 1000 / 100 << std::endl;

            std::lock_guard<std::mutex> lock(completed_task_mtx);
            InsertResponse(task, task);

            completed_task_cv.notify_all();
        }
    }
}

int main(int argc, char* argv[]) {
    RouteImpl route;

    std::string task = {"{\"registration\":{\"nickname\":\"Sasha\",\"password\":\"123456asd64569898989\"}}"};

    for (int i = 9; i > -1; --i) {
        route.InsertTask(std::to_string(i * 1000));
    }

    std::tuple<int, std::string> answer;

    do {
        answer = route.GetResTask(std::to_string(8 * 1000));
    } while (!std::get<0>(answer));

    std::cout << std::get<1>(answer) << " DONE" << std::endl;

//    route.InsertTask(task);

//    std::string answer;

//    while (answer.empty()) {
//        std::cout << "I wait" << std::endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//        answer = route.GetResTask(task);
//    }
}
