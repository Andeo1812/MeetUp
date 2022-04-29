#pragma once  //  NOLINT

#include "Handler.hpp"

class WriteGeneralData : public Handler {
 public:
    Context process(const Context &request_body) const override;
};

class GetGeneralData : public Handler {
 public:
    Context process(const Context &request_body) const override;
};



