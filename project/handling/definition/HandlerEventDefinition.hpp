#include <HandlerEvent.hpp>

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
Context AddEvent<T, ClassConnection, ClassDBMethods, ClassDBWorker>::operator()(const Context &request_body, ClassDBWorker *db_worker) const {
    Context response_body;

    for (auto &event: request_body.AccessEvents()) {
        std::string new_event_id;

        int res = db_worker->db_methods.Event.Add(event,
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
    }

    return response_body;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
Context WriteEvent<T, ClassConnection, ClassDBMethods, ClassDBWorker>::operator()(const Context &request_body, ClassDBWorker *db_worker) const {
    Context response_body;

    return response_body;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
Context RmEvent<T, ClassConnection, ClassDBMethods, ClassDBWorker>::operator()(const Context &request_body, ClassDBWorker *db_worker) const {
    Context response_body;

    for (auto &event: request_body.AccessEvents()) {
        int res = db_worker->db_methods.Event.Rm(event,
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
    }

    return response_body;
}
