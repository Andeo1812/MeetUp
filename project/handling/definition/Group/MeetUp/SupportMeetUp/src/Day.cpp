#include <Day.hpp>

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

    MeetUpRules(vector, meetups_day);

    return EXIT_SUCCESS;
}