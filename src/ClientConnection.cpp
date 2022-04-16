

#include "ClientConnection.hpp"
#include <utility>
#include <vector>
#include "ConnectionClientManager.hpp"
#include "RequestHandler.hpp"

#include <iostream>

namespace http {
namespace AsyncServer {

ClientConnection::ClientConnection(boost::asio::ip::tcp::socket socket,
    ConnectionClientManager& manager, RequestHandler& handler) : socket_(std::move(socket)),
    connection_manager_(manager),
    request_handler_(handler) {}

void ClientConnection::start() {
    do_read();
}

void ClientConnection::stop() {
    socket_.close();
}

void ClientConnection::do_read() {
    auto self(shared_from_this());
    socket_.async_read_some(boost::asio::buffer(buffer_),
        [this, self](boost::system::error_code ec, std::size_t bytes_transferred) {
            if (!ec) {
                RequestParser::result_type result;
                std::tie(result, std::ignore) = request_parser_.parse(
                    request_, buffer_.data(), buffer_.data() + bytes_transferred);

                if (result == RequestParser::good) {
                    request_handler_.handle_request(request_, reply_);
                    do_write();
                }
                else if (result == RequestParser::bad) {
                    reply_ = Reply::stock_reply(Reply::bad_request);
                    do_write();
                }
                else {
                    do_read();
                }
            }
            else if (ec != boost::asio::error::operation_aborted) {
                connection_manager_.close_connection(shared_from_this());
            }
        });
    std::cout << "In buffer:" << buffer_.data() << std::endl;
}

void ClientConnection::do_write() {
    auto self(shared_from_this());
    boost::asio::async_write(socket_, reply_.to_buffers(),
        [this, self](boost::system::error_code ec, std::size_t) {
            if (!ec) {
                // Initiate graceful connection closure.
                boost::system::error_code ignored_ec;
                socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both,
                ignored_ec);
            }

            if (ec != boost::asio::error::operation_aborted) {
                connection_manager_.close_connection(shared_from_this());
            }
        });
}

} // namespace AsyncServer
} // namespace http