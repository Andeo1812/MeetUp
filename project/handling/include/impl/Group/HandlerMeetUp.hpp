#pragma once

#include <Handler.hpp>

class GetMeetUps: public Handler {
public:
    Context process(const Context& request_body) const override;
};

/*
class GetHistoryMeetUp: public Handler {
public:
    Context process(const Context& request_body) const override;
};
*/
