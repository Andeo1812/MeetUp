#pragma once  //  NOLINT

#include "Context.hpp"

#define GLOBAL_KEY_TEST_PROCESSING true

class Handler {
public:
    virtual Context process(const Context& request_body) const = 0;

    virtual ~Handler() = default;
};
