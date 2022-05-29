
#include <fstream>
#include <sstream>
#include <string>
#include <functional>
#include <iostream>
#include <cctype>

#include "RequestHandler.hpp"
#include "MimeTypes.hpp"
#include "Reply.hpp"
#include "HttpRequest.hpp"

#define DEFAULT_FILE "/index.html"

namespace http {
namespace AsyncServer {

RequestHandler::RequestHandler(const std::string& file_storage) : file_storage_(file_storage) {}

void RequestHandler::handle_request(const HttpRequest& req, Reply& rep) {
    std::string request_path = file_storage_ + DEFAULT_FILE;

    if (request_path.empty() || request_path[file_storage_.size()] != '/') {
        rep = Reply::stock_reply(Reply::bad_request);
        return;
    }

    std::size_t last_slash_pos = request_path.find_last_of("/");
    std::size_t last_dot_pos = request_path.find_last_of(".");
    std::string extension;
    if (last_dot_pos != std::string::npos && last_dot_pos > last_slash_pos) {
        extension = request_path.substr(last_dot_pos + 1);
    }

    rep.status = Reply::ok;
    char buf[512];

    if (req.method != "POST") {
        std::ifstream is(request_path.c_str(), std::ios::in | std::ios::binary);
        if (!is) {
            rep = Reply::stock_reply(Reply::not_found);
            return;
        }
        while (is.read(buf, sizeof(buf)).gcount() > 0) {
            rep.content.append(buf, is.gcount());
        }
    }

    rep.headers.resize(2);
    rep.headers[0].name = "Content-Length";
    rep.headers[0].value = std::to_string(rep.content.size());
    rep.headers[1].name = "Content-Type";
    rep.headers[1].value = (req.method == "POST") ? "application/json" : MimeTypes::extension_to_type(extension);
}


} // namespace AsyncServer
} // namespace http