#pragma once  //  NOLINT

#include "Handler.hpp"

class AddUserContacts: public Handler {
 public:
    Context process(const Context& request_body) const override;
};

class RmUserContacts: public Handler {
 public:
    Context process(const Context& request_body) const override;
};
