#pragma once  //  NOLINT

#include "Handler.hpp"
#include "Parser.hpp"

template<class ClassDBManager>
class Route {
 public:
    virtual void InsertTask(const std::string &task) = 0;

    virtual std::string GetHeadRequest(const std::string &request_body) const = 0;

    virtual std::string HandlingTask(const std::string &request_body) const = 0;

    virtual std::string GetResTask(const std::string &request_body) = 0;

    virtual ~Route() = default;
};
