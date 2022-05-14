#pragma once  //  NOLINT

#include "Route.hpp"

typename<class ClassDBManager>
class RouteImpl : protected Route<ClassDBManager> {
 public:
    void InsertTask(const std::string &task) override;

    std::string GetHeadRequest(const std::string &request_body) const override;

    std::string HandlingTask(const std::string &request_body) const override;

    std::string GetResTask(const std::string &request_body) override;

    RouteImpl();
    RouteImpl(const RouteImpl &other) = default;
    ~RouteImpl() = default;
};
