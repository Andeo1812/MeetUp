#include <HandlerEvent.hpp>

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context AddEvent<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    std::string new_event_id;

    int res = db_worker->db_methods.Event.Add(*request_body.AccessEvents().begin(),
                                              &new_event_id,
                                              &(db_worker->connection));
    switch (res) {
        case NOT_ADD_EVENT: {
            response_body.SetError("Not found add event");
            break;
        }
        case ERROR_ADD_EVENT: {
            response_body.SetError("Error add event");
            break;
        }
        case EXIT_SUCCESS: {
            Event event;

            event.SetId(new_event_id);

            response_body.GetEvents().insert(event);
            break;
        }
        default: {
            response_body.SetError("Bad add event");
            break;
        }
    }

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

    int res = db_worker->db_methods.Event.Rm(*request_body.AccessEvents().begin(),
                                              &(db_worker->connection));
    switch (res) {
        case NOT_RM_EVENT: {
            response_body.SetError("Not found rm event");
            break;
        }
        case ERROR_RM_EVENT: {
            response_body.SetError("Error rm event");
            break;
        }
        case EXIT_SUCCESS: {
            break;
        }
        default: {
            response_body.SetError("Bad rm event");
            break;
        }
    }

    return response_body;
}
