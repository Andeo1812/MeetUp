#pragma once  //  NOLINT

#include "Handler.hpp"

class AddEvent: public Handler {
public:
    Context process(const Context& request_body) const override;
};

class WriteEvent: public Handler {
public:
    Context process(const Context& request_body) const override;
};

class RmEvent: public Handler {
public:
    Context process(const Context& request_body) const override;

};
