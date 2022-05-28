#include <HandlerContacts.hpp>

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context AddUserContacts<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    int res = db_worker->db_methods.Contacts.Add(request_body.AccessContacts().AccessUserId(),
                                                 request_body.AccessContacts().AccessContacts().begin()->data(),
                                                 &(db_worker->connection));
    switch (res) {
        case NOT_ADD_CONTACT: {
            response_body.SetError("Not found add contact");
            break;
        }
        case ERROR_RM_CONTACT: {
            response_body.SetError("Error add contact");
            break;
        }
        case EXIT_SUCCESS: {
            break;
        }
        default: {
            response_body.SetError("Bad add contact");
            break;
        }
    }

    return response_body;
}

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context RmUserContacts<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    int res = db_worker->db_methods.Contacts.Add(request_body.AccessContacts().AccessUserId(),
                                                 request_body.AccessContacts().AccessContacts().begin()->data(),
                                                 &(db_worker->connection));
    switch (res) {
        case NOT_ADD_CONTACT: {
            response_body.SetError("Not found rm contact");
            break;
        }
        case ERROR_RM_CONTACT: {
            response_body.SetError("Error rm contact");
            break;
        }
        case EXIT_SUCCESS: {
            break;
        }
        default: {
            response_body.SetError("Bad rm contact");
            break;
        }
    }

    return response_body;
}
