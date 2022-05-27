#include <HandlerUser.hpp>

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context Registration<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    std::string new_user_id;

    int res = db_worker->db_methods.User.Registration(request_body.AccessUser(), &new_user_id, &(db_worker->connection));
    switch (res) {
        case NOT_REGISTRATION: {
            response_body.SetError("Not found");
            break;
        }
        case ERROR_REGISTRATION: {
            response_body.SetError("Error registration");
            break;
        }
        case EXIT_SUCCESS: {
            response_body.GetUser().SetId(new_user_id);
            break;
        }
        default: {
            response_body.SetError("Bad registration");
            break;
        }
    }

    return response_body;
}

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context Authentication<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    std::string user_id;

    int res = db_worker->db_methods.User.Authentication(request_body.AccessUser(), &user_id, &(db_worker->connection));
    switch (res) {
        case NOT_RM_USER: {
            response_body.SetError("Not found");
            break;
        }
        case ERROR_RM_USER: {
            response_body.SetError("Error authentication");
            break;
        }
        case EXIT_SUCCESS: {
            response_body.GetUser().SetId(user_id);
            break;
        }
        default: {
            response_body.SetError("Bad authentication");
            break;
        }
    }

    return response_body;
}

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context RmUser<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    std::string new_user_id;

    int res = db_worker->db_methods.User.Rm(request_body.AccessUser(), &(db_worker->connection));
    switch (res) {
        case NOT_AUTHENTICATION: {
            response_body.SetError("Not found");
            break;
        }
        case ERROR_AUTHENTICATION: {
            response_body.SetError("Error authentication");
            break;
        }
        case EXIT_SUCCESS: {
            break;
        }
        default: {
            response_body.SetError("Bad authentication");
            break;
        }
    }

    return response_body;
}
