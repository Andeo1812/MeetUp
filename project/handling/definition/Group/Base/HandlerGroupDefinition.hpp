#include <HandlerGroup.hpp>

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
Context AddGroup<T, ClassConnection, ClassDBMethods, ClassDBWorker>::operator()(const Context &request_body, ClassDBWorker *db_worker) const {
    Context response_body;

    std::string new_group_id;

    int res = db_worker->db_methods.Group.Create(*request_body.AccessGroups().begin(),
                                              &new_group_id,
                                              &(db_worker->connection));
    switch (res) {
        case NOT_CREATE_GROUP: {
            response_body.SetError("Not found add group");
            break;
        }
        case ERROR_CREATE_GROUP: {
            response_body.SetError("Error add group");
            break;
        }
        case EXIT_SUCCESS: {
            Group group;

            group.SetId(new_group_id);

            response_body.GetGroups().insert(group);
            break;
        }
        default: {
            response_body.SetError("Bad add group");
            break;
        }
    }

    return response_body;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
Context WriteGroup<T, ClassConnection, ClassDBMethods, ClassDBWorker>::operator()(const Context &request_body, ClassDBWorker *db_worker) const {
    Context response_body;

    return response_body;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
Context RmGroup<T, ClassConnection, ClassDBMethods, ClassDBWorker>::operator()(const Context &request_body, ClassDBWorker *db_worker) const {
    Context response_body;

    int res_rm_members = db_worker->db_methods.Group.RmAllMembers(request_body.AccessGroups().begin()->AccessId(),
                                                 &(db_worker->connection));
    switch (res_rm_members) {
        case NOT_RM_GROUP_ALL_MEMBER: {
            response_body.SetError("Not found rm all group members");
            break;
        }
        case ERROR_RM_GROUP_ALL_MEMBER: {
            response_body.SetError("Error rm all group members");
            break;
        }
        case EXIT_SUCCESS: {
            break;
        }
        default: {
            response_body.SetError("Bad rm all group members");
            break;
        }
    }

    if (!response_body.AccessError().empty()) {
        return response_body;
    }

    int res_rm_group = db_worker->db_methods.Group.Rm(request_body.AccessGroups().begin()->AccessId(),
                                                                  &(db_worker->connection));
    switch (res_rm_group) {
        case NOT_RM_GROUP: {
            response_body.SetError("Not found rm group");
            break;
        }
        case ERROR_RM_GROUP: {
            response_body.SetError("Error rm group");
            break;
        }
        case EXIT_SUCCESS: {
            break;
        }
        default: {
            response_body.SetError("Bad rm group");
            break;
        }
    }

    return response_body;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
Context GetGroupMembers<T, ClassConnection, ClassDBMethods, ClassDBWorker>::operator()(const Context &request_body, ClassDBWorker *db_worker) const {
    Context response_body;

    return response_body;
}

/*Context SearchGroup::process(const Context& request_body) const {
    Context response_body;

    return response_body;
}*/
