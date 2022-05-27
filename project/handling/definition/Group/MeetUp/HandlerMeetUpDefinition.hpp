#include <HandlerMeetUp.hpp>

#include <MeetUp.hpp>

template<typename T, class ClassConnection, class DBMethods, class DBWorker>
Context GetMeetUps<T, ClassConnection, DBMethods, DBWorker>::operator()(const Context &request_body, DBWorker *db_worker) const {
    Context response_body;

    return response_body;
}
