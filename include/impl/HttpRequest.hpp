

#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <string>
#include <vector>
#include "Header.hpp"

namespace http {
namespace AsyncServer {

/// A request received from a client.
struct HttpRequest {
    std::string method;
    std::string uri;
    int http_version_major;
    int http_version_minor;
    std::vector<Header> headers;
};

} // namespace AsyncServer
} // namespace http

#endif // HTTP_REQUEST_HPP