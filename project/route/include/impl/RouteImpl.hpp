#pragma once

#include <Route.hpp>

class RouteImpl : Route {
public:
    std::string get_head(const std::string request_body) override;

    std::string get_response(const std::string request_body) override;

    RouteImpl();
    RouteImpl(const RouteImpl& other) = default;
    ~RouteImpl() = default;
};
