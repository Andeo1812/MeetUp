#include <HandlerGroup.hpp>

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context AddUserGroup<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    int res = db_worker->db_methods.Group.AddMember(request_body.AccessGroups().begin()->AccessUserId(),
                                                    request_body.AccessGroups().begin()->AccessId(),
                                                    &(db_worker->connection));
    switch (res) {
        case NOT_ADD_GROUP_MEMBER: {
            response_body.SetError("Not found add group member");
            break;
        }
        case ERROR_ADD_GROUP_MEMBER: {
            response_body.SetError("Error add group member");
            break;
        }
        case EXIT_SUCCESS: {
            break;
        }
        default: {
            response_body.SetError("Bad add group member");
            break;
        }
    }


    return response_body;
}

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context RmUserGroup<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    int res = db_worker->db_methods.Group.RmMember(request_body.AccessGroups().begin()->AccessUserId(),
                                                    request_body.AccessGroups().begin()->AccessId(),
                                                    &(db_worker->connection));
    switch (res) {
        case NOT_RM_GROUP_MEMBER: {
            response_body.SetError("Not found rm group member");
            break;
        }
        case ERROR_ADD_GROUP_MEMBER: {
            response_body.SetError("Error rm group member");
            break;
        }
        case EXIT_SUCCESS: {
            break;
        }
        default: {
            response_body.SetError("Bad rm group member");
            break;
        }
    }

    return response_body;
}
