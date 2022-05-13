

#ifndef HTTP_HEADER_HPP
#define HTTP_HEADER_HPP

#include <string>

namespace http {
namespace AsyncServer {

struct Header {
    std::string name;
    std::string value;
};

} // namespace AsyncServer
} // namespace http

#endif // HTTP_HEADER_HPP