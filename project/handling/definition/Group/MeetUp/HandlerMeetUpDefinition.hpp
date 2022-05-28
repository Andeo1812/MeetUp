#include <HandlerMeetUp.hpp>

#include <MeetUp.hpp>

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
Context GetMeetUps<T, ClassConnection, ClassDBMethods, ClassDBWorker>::operator()(const Context &request_body, ClassDBWorker *db_worker) const {
    Context response_body;

    std::set<MeetUp> meetups_day;

    int res_get_meetup = GetMeetUpSet(request_body.AccessMeetUps().begin()->AccessId(), request_body.AccessMeetUps().begin()->AccessDate(), db_worker, &meetups_day);
    if (res_get_meetup != EXIT_SUCCESS) {
        response_body.SetError("Bat get meetups");
        return response_body;
    }

    response_body.GetMeetUps() = meetups_day;

    return response_body;
}
