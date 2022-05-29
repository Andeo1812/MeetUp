

#ifndef HTTP_REQUEST_HANDLER_HPP
#define HTTP_REQUEST_HANDLER_HPP

#include <string>

#include "HandlerServer.hpp"

namespace http {
namespace AsyncServer {

struct Reply;
struct HttpRequest;

/// The common handler for all incoming requests.
class
RequestHandler : public Handler {
public:
    RequestHandler(const RequestHandler&) = delete;
    RequestHandler& operator=(const RequestHandler&) = delete;
    /// Construct with a directory containing files to be served.
    explicit RequestHandler(const std::string& file_storage);

    // RouteImpl route;

    /// Handle a request and produce a reply.
    void handle_request(const HttpRequest& req, Reply& rep) override;


private:
    /// The directory containing the files to be served.
    std::string file_storage_;

};

} // namespace AsyncServer
} // namespace http

#endif // HTTP_REQUEST_HANDLER_HPP