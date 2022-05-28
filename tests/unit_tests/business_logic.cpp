#include <gtest/gtest.h>

#include "HandlerMeetUp.hpp"
#include "Day.hpp"

TEST(BusinessLogic, Meetup) {
    EXPECT_EQ(StrToTime({"16:48"}), 16 * 60 + 48);

    EXPECT_EQ(TimeToStr(16 * 60 + 48), "16:48");

    Event event_1;
    event_1.SetTimeBegin({"8:00"});
    event_1.SetTimeEnd({"9:00"});

    Event event_2;
    event_2.SetTimeBegin({"13:23"});
    event_2.SetTimeEnd({"16:58"});

    Event event_3;
    event_3.SetTimeBegin({"6:20"});
    event_3.SetTimeEnd({"7:40"});

    Event event_4;
    event_4.SetTimeBegin({"8:30"});
    event_4.SetTimeEnd({"14:20"});

    Event event_5;
    event_5.SetTimeBegin({"20:15"});
    event_5.SetTimeEnd({"21:20"});

    std::set<Event> events;

    events.insert(event_1);
    events.insert(event_2);
    events.insert(event_3);
    events.insert(event_4);
    events.insert(event_5);

    MeetUp meetup_1;
    meetup_1.SetTimeBegin({"00:00"});
    meetup_1.SetTimeEnd({"6:20"});

    MeetUp meetup_2;
    meetup_2.SetTimeBegin({"16:58"});
    meetup_2.SetTimeEnd({"20:15"});

    MeetUp meetup_3;
    meetup_3.SetTimeBegin({"21:20"});
    meetup_3.SetTimeEnd({"24::00"});

    std::set<MeetUp> expected_meetups;

    expected_meetups.insert(meetup_1);
    expected_meetups.insert(meetup_2);
    expected_meetups.insert(meetup_3);

    std::set<MeetUp> get_meetups;

    CreateSetMeetUps(events, &get_meetups);

    EXPECT_EQ(get_meetups, expected_meetups);
}
