#pragma once  //  NOLINT

#include <string>
#include <cstddef>

size_t StrToTime(const std::string &time);

std::string TimeToStr(const size_t time);
