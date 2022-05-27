#include <HandlerGroup.hpp>

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context AddGroup<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    return response_body;
}

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context WriteGroup<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    return response_body;
}

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context RmGroup<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    return response_body;
}

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context GetGroupMembers<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    return response_body;
}

/*Context SearchGroup::process(const Context& request_body) const {
    Context response_body;

    return response_body;
}*/
