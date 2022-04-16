#pragma once  //  NOLINT

#include "Handler.hpp"

class WritePersonalData: public Handler {
public:
    Context process(const Context& request_body) const override;
};

class GetPersonalData: public Handler {
public:
    Context process(const Context& request_body) const override;
};


