#include <HandlerAddressData.hpp>

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context WriteAddressData<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, const DBWorker &db_worker) const {
    Context response_body;

    return response_body;
}

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context GetAddressData<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, const DBWorker &db_worker) const {
    Context response_body;

    return response_body;
}


