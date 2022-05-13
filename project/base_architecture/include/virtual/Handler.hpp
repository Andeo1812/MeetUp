

#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <string>

namespace http {
namespace AsyncServer {

struct Reply;
struct HttpRequest;

///  The handler's interface for all incoming requests.
class Handler {
public:
    Handler(const Handler&) = delete;
    Handler& operator=(const Handler&) = delete;

    Handler() = default;
    virtual ~Handler() = default;

    /// Handle a request and produce a reply.
    virtual void handle_request(const HttpRequest& req, Reply& rep) = 0;
};

} // namespace AsyncServer
} // namespace http

#endif // HANDLER_HPP