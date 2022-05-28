#include "Time.hpp"

size_t StrToTime(const std::string &time) {
    size_t delimiter = time.find(':');

    std::string hour = time.substr(0, delimiter);

    std::string minutes = time.substr(delimiter + 1, time.size() - hour.size());

    return std::stoul(hour) * 60 + std::stoul(minutes);
}

std::string TimeToStr(const size_t time) {
    size_t hour = time / 60;

    std::string hour_str;
    if (hour) {
        hour_str = std::to_string(hour);
    } else {
        hour_str = {"00"};
    }

    size_t minutes = time % 60;

    std::string minutes_str;
    if (minutes) {
        minutes_str = std::to_string(minutes);
    } else {
        minutes_str = {"00"};
    }

    std::string res = hour_str + ":" + minutes_str;

    return res;
}
