#pragma once  //  NOLINT

#include <array>

#include "HandlerMeetUp.hpp"

struct Point {
    size_t value;
    int thickness;

    bool operator<(const Point &other) const {
        return this->value < other.value;
    }

    friend std::ostream& operator<<(std::ostream &os, const Point &it)  {
        return os << it.value << " " << it.thickness << std::endl;
    }

    Point() = default;

    Point(const size_t value, const int thickness) : value(value), thickness(thickness) {}
};

size_t convert(const std::string &time) {
    size_t delimiter = time.find(':');

    std::string hour = time.substr(0, delimiter);

    std::string minutes = time.substr(delimiter, time.size() - hour.size());

    std::cout << time << std::endl;

    std::cout << std::stoul(hour) << ":" << std::stoul(minutes) << std::endl;

    return 2;
}

int CreateSetMeetUps(const std::set<Event> &events_day, std::set<MeetUp> *meetups_day) {
    std::vector<Point> vector;

    vector.resize(events_day.size() * 2 + 1);

    auto iterator = events_day.cbegin();
    for (size_t i = 0; i < vector.size(); ++i) {
        vector[2 * i] = Point(convert(iterator->AccessTimeBegin()), 1);

        vector[2 * i + 1] = Point(convert(iterator->AccessTimeEnd()), -1);

        ++i;
    }

    return EXIT_SUCCESS;
}

template<typename T, class ClassConnection, class ClassDBMethods, class ClassDBWorker>
int GetMeetUps<T, ClassConnection, ClassDBMethods, ClassDBWorker>::GetDataSetEvents(const std::string &group_id, const std::string &date, ClassDBWorker *db_worker, std::set<Event> *events_day) const {
    Group group;

    int res_get_members = db_worker->db_methods.Group.GetMembers(group_id, group, &(db_worker->connection));
    if (res_get_members != EXIT_SUCCESS) {
        return res_get_members;
    }

    for (auto &member: group.AccessMembers()) {
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
