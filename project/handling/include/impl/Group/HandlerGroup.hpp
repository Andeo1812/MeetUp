#pragma once  //  NOLINT

#include "Handler.hpp"

class AddGroup : public Handler {
 public:
    Context process(const Context &request_body) const override;
};

class WriteGroup : public Handler {
 public:
    Context process(const Context &request_body) const override;
};

class RmGroup : public Handler {
 public:
    Context process(const Context &request_body) const override;
};


class GetGroupMembers : public Handler {
 public:
    Context process(const Context &request_body) const override;
};


class AddUserGroup : public Handler {
 public:
    Context process(const Context &request_body) const override;
};

class RmUserGroup : public Handler {
 public:
    Context process(const Context &request_body) const override;
};

/*
class SearchGroup: public Handler {
 public:
    Context* process(const Context* request_body) const override;
};
 */
