#pragma once  //  NOLINT

#include "Handler.hpp"

class SynchroClientEvents : public Handler {
 public:
    Context process(const Context &request_body) const override;
};

class SynchroClientContacts : public Handler {
 public:
    Context process(const Context &request_body) const override;
};

class SynchroClientGroups : public Handler {
 public:
    Context process(const Context &request_body) const override;
};
