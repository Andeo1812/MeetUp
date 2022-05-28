#pragma once  //  NOLINT

#include <array>

#include "HandlerMeetUp.hpp"
#include "MeetUpConfig.hpp"

struct Point {
    size_t value;
    int thickness;

    bool operator<(const Point &other) const {
        return this->value < other.value;
    }

    friend std::ostream& operator<<(std::ostream &os, const Point &it)  {
        return os << TimeToStr(it.value) << " " << it.thickness << std::endl;
    }

    Point() = default;

    Point(const size_t value, const int thickness) : value(value), thickness(thickness) {}
};

int MeetUpRules(const std::vector<Point> &events_day, std::set<MeetUp> *meetups_day) {
    int cur_thickness = 0;
    for (size_t i = 0; i < events_day.size(); ++i) {
        cur_thickness += events_day[i].thickness;

        if (!cur_thickness) {
            MeetUp meetup;

            if (events_day[i + 1].value - events_day[i].value > MinMeetUp) {
                meetup.SetTimeBegin(TimeToStr(events_day[i].value));

                meetup.SetTimeEnd(TimeToStr(events_day[i + 1].value));

                meetups_day->insert(meetup);
            }
        }
    }

    auto iterator = meetups_day->end();
    --iterator;

    meetups_day->erase(iterator);

    return EXIT_SUCCESS;
}

int CreateSetMeetUps(const std::set<Event> &events_day, std::set<MeetUp> *meetups_day) {
    std::vector<Point> vector;

    vector.resize(events_day.size() * 2 + 2);

    vector[0] = Point(0, 0);

    auto iterator = events_day.cbegin();
    for (size_t i = 0; i < events_day.size(); ++i) {
        vector[2 * i + 1] = Point(StrToTime(iterator->AccessTimeBegin()), 1);

        vector[2 * i + 2] = Point(StrToTime(iterator->AccessTimeEnd()), -1);

        ++iterator;
    }

    vector[vector.size() - 1] = Point(24 * 60, 0);

    std::sort(vector.begin(), vector.end());

    for (auto &value: vector) {
        std::cout << value << std::endl;
    }

    MeetUpRules(vector, meetups_day);


    return EXIT_SUCCESS;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
int GetMeetUps<T, ClassConnection, ClassDBMethods, ClassDBWorker>::GetDataSetEvents(const std::string &group_id, const std::string &date, ClassDBWorker *db_worker, std::set<Event> *events_day) const {
    Group group;

    int res_get_members = db_worker->db_methods.Group.GetMembers(group_id, group, &(db_worker->connection));
    if (res_get_members != EXIT_SUCCESS) {
        return res_get_members;
    }

    for (auto &member : group.AccessMembers()) {
        std::set<Event> events_member;

        int res_get_events_member = db_worker->db_methods.Events.GetSet(member, &events_member, date, &(db_worker->connection));
        if (res_get_events_member != EXIT_SUCCESS) {
            return res_get_members;
        }

        events_day->template merge(events_member);
    }

    return EXIT_SUCCESS;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
int GetMeetUps<T, ClassConnection, ClassDBMethods, ClassDBWorker>::GetMeetUpSet(const std::string &group_id, const std::string &date, ClassDBWorker *db_worker, std::set<MeetUp> *meetups_day) const {
    std::set<Event> events_day;

    int res_get_events_day = GetDataSetEvents(group_id, date, &(db_worker->connection), events_day);
    if (res_get_events_day != EXIT_SUCCESS) {
        return res_get_events_day;
    }

    int res_create_set_meetups = CreateSetMeetUps(events_day, meetups_day);
    if (res_create_set_meetups != EXIT_SUCCESS) {
        return res_create_set_meetups;
    }

    return EXIT_SUCCESS;
}
