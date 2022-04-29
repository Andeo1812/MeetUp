#pragma once  //  NOLINT

#include "Context.hpp"

class Handler {
 public:
    virtual Context process(const Context &request_body) const = 0;

    virtual ~Handler() = default;
};
