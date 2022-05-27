#include <HandlerEvent.hpp>

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context AddEvent<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    return response_body;
}

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context WriteEvent<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    return response_body;
}

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context RmEvent<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    return response_body;
}
