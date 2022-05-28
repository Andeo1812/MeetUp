#include <HandlerSynchroClient.hpp>

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
Context GetSetEvents<T, ClassConnection, ClassDBMethods, ClassDBWorker>::operator()(const Context &request_body, ClassDBWorker *db_worker) const {
    Context response_body;

    std::set<Event> events;

    int res = db_worker->db_methods.Event.GetSet(request_body.AccessEvents().begin()->AccessUserId(),
                                              &events,
                                              request_body.AccessEvents().begin()->AccessDate(),
                                              &(db_worker->connection));
    switch (res) {
        case NOT_GET_SET_EVENTS: {
            response_body.SetError("Not found get set events");
            break;
        }
        case ERROR_GET_SET_EVENTS: {
            response_body.SetError("Error get set events");
            break;
        }
        case EXIT_SUCCESS: {
            response_body.GetEvents() = events;
            break;
        }
        default: {
            response_body.SetError("Bad get set events");
            break;
        }
    }

    return response_body;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
Context GetSetContacts<T, ClassConnection, ClassDBMethods, ClassDBWorker>::operator()(const Context &request_body, ClassDBWorker *db_worker) const {
    Context response_body;

    std::set<Group> groups;

    int res = db_worker->db_methods.Group.GetSet(request_body.AccessEvents().begin()->AccessUserId(),
                                                 &groups,
                                                 request_body.GetLeftBorder(),
                                                 request_body.GetRightBorder(),
                                                 &(db_worker->connection));
    switch (res) {
        case NOT_GET_SET_GROUPS: {
            response_body.SetError("Not found get set groups");
            break;
        }
        case ERROR_GET_SET_GROUPS: {
            response_body.SetError("Error get set groups");
            break;
        }
        case EXIT_SUCCESS: {
            response_body.GetGroups() = groups;
            break;
        }
        default: {
            response_body.SetError("Bad get set groups");
            break;
        }
    }

    return response_body;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
Context GetSetGroups<T, ClassConnection, ClassDBMethods, ClassDBWorker>::operator()(const Context &request_body, ClassDBWorker *db_worker) const {
    Context response_body;

    std::set<std::string> contacts;

    int res = db_worker->db_methods.Contacts.GetSet(request_body.AccessEvents().begin()->AccessUserId(),
                                                 &contacts,
                                                 request_body.GetLeftBorder(),
                                                 request_body.GetRightBorder(),
                                                 &(db_worker->connection));
    switch (res) {
        case NOT_GET_SET_CONTACT: {
            response_body.SetError("Not found get set contacts");
            break;
        }
        case ERROR_GET_SET_CONTACT: {
            response_body.SetError("Error get set contacts");
            break;
        }
        case EXIT_SUCCESS: {
            response_body.GetContacts().GetContacts() = contacts;
            break;
        }
        default: {
            response_body.SetError("Bad get set groups");
            break;
        }
    }


    return response_body;
}
