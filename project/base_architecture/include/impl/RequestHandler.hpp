

#ifndef HTTP_REQUEST_HANDLER_HPP
#define HTTP_REQUEST_HANDLER_HPP

#include <string>

#include "HandlerServer.hpp"

//  Routing
// #include "RouteImpl.hpp"

namespace http {
namespace AsyncServer {

struct Reply;
struct HttpRequest;

struct RouteImpl {

    void InsertTask(std::string str) {
        std::cout << "---------->InsertTask(std::string str)" << std::endl;
    }

    std::tuple<int, std::string> GetResTask(std::string in) {
        std::string out;
        srand(time(NULL));
        int r = rand() % 3;
        if (r != 0) {
            std::cout << "NOT NOW" << std::endl;
            return std::make_tuple(0, "");
        }

        std::for_each(in.begin(), in.end(), [&out](unsigned char c){out.push_back(c);});
        return std::make_tuple(1, out);
    }
};


/// The common handler for all incoming requests.
class
RequestHandler : public Handler {
public:
    RequestHandler(const RequestHandler&) = delete;
    RequestHandler& operator=(const RequestHandler&) = delete;
    /// Construct with a directory containing files to be served.
    explicit RequestHandler(const std::string& file_storage);

    RouteImpl route;

    /// Handle a request and produce a reply.
    void handle_request(const HttpRequest& req, Reply& rep) override;

    // RouteImpl<pqxx::connection> route;

private:
    /// The directory containing the files to be served.
    std::string file_storage_;

};

} // namespace AsyncServer
} // namespace http

#endif // HTTP_REQUEST_HANDLER_HPP