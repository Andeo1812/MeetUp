#pragma once  //  NOLINT

#include "Handler.hpp"

class WritePassword : public Handler {
public:
    Context process(const Context& request_body) const override;
};

class WriteNickname : public Handler {
public:
    Context process(const Context& request_body) const override;
};
