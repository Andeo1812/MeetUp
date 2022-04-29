#pragma once  //  NOLINT

#include "Handler.hpp"

class Registration : public Handler {
 public:
    Context process(const Context &request_body) const override;
};

class Authentication : public Handler {
 public:
    Context process(const Context &request_body) const override;
};
