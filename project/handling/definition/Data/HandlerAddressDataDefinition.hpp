#include <HandlerAddressData.hpp>

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
Context WriteAddressData<T, ClassConnection, ClassDBMethods, ClassDBWorker>::operator()(const Context &request_body, ClassDBWorker *db_worker) const {
    Context response_body;

    return response_body;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
Context GetAddressData<T, ClassConnection, ClassDBMethods, ClassDBWorker>::operator()(const Context &request_body, ClassDBWorker *db_worker) const {
    Context response_body;

    return response_body;
}


