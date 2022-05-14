

#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <string>
#include <vector>

#include "Header.hpp"
#include <iostream>

namespace http {
namespace AsyncServer {

/// A request received from a client.
struct HttpRequest {
    std::string method;
    std::string uri;
    int http_version_major;
    int http_version_minor;
    std::vector<Header> headers;
    std::string content;

    void print_req() const {
        std::cout << "***REQUEST***" << std::endl;
        std::cout << "method: " << method << std::endl;
        std::cout << "uri: " << uri << std::endl;
        std::cout << "http_version_major: " << http_version_major << std::endl;
        std::cout << "http_version_minor: " << http_version_minor << std::endl;

        std::cout << "--------headers---------" << std::endl;
        for (auto &i : headers) {
            std::cout << i.name << ": " << i.value << std::endl;
        }
        std::cout << "------end_headers-------" << std::endl;
    }
};

} // namespace AsyncServer
} // namespace http

#endif // HTTP_REQUEST_HPP