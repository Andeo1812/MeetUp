#pragma once  //  NOLINT

#include "Handler.hpp"

class WriteAddressData : public Handler {
 public:
    Context process(const Context &request_body) const override;
};

class GetAddressData : public Handler {
 public:
    Context process(const Context &request_body) const override;
};
