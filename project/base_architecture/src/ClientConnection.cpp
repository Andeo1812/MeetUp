
#include <boost/bind/bind.hpp>
#include <utility>
#include <vector>
#include <iostream>

#include "ClientConnection.hpp"
#include "ConnectionClientManager.hpp"
#include "RequestHandler.hpp"


#define WAIT 0
#define READY 1

namespace http {
namespace AsyncServer {

ClientConnection::ClientConnection(boost::asio::io_context& io_context, boost::asio::ip::tcp::socket &&socket,
        ConnectionClientManager& manager, RequestHandler& handler) : socket_(std::move(socket)),
        connection_manager_(manager),
        request_handler_(handler),
        timer(io_context, boost::asio::chrono::milliseconds(200)) {}

void ClientConnection::start() {
    do_read();
}

void ClientConnection::stop() {
    socket_.close();
}

//Modulate back-end's work
std::tuple<int, std::string> get_response(std::string in) {
    std::string out;
    srand(time(NULL));
    int r = rand() % 3;
    if (r != 0) {
        return std::make_tuple(WAIT, "\n");
    }

    std::for_each(in.begin(), in.end(), [&out](unsigned char c){out.push_back(c-32);});
    return std::make_tuple(READY, out);
}

void ClientConnection::async_get(std::string str, boost::asio::steady_timer* timer) {
    std::string response;
    int status_handle;
    std::tie(status_handle, response) = get_response(str);

    if (status_handle == WAIT) {
        timer->expires_at(timer->expiry() + boost::asio::chrono::milliseconds(200));
        timer->async_wait(boost::bind(&ClientConnection::async_get, this, str, timer));
        return;
    } else {
        std::cout << response << std::endl;

        request_handler_.handle_request(request_, reply_);
        do_write();
    }

}

void ClientConnection::do_handle() {
    timer.async_wait(boost::bind(&ClientConnection::async_get, this,
            "send_this_string_to_back_end_and_wait_the_response", &timer));
}

void ClientConnection::do_read() {
    auto self(shared_from_this());
    socket_.async_read_some(boost::asio::buffer(buffer_),
        [this, self](boost::system::error_code ec, std::size_t bytes_transferred) {
            if (!ec) {
                RequestParser::result_type result;
                std::tie(result, std::ignore) = request_parser_.parse(
                                                    request_,
                                                    buffer_.data(),
                                                    buffer_.data() + bytes_transferred);

                if (result == RequestParser::good) {
                    std::cout << "@ ";
                    request_.print_req();
                    do_handle();
                } else if (result == RequestParser::bad) {
                    reply_ = Reply::stock_reply(Reply::bad_request);
                    do_write();
                } else {
                    do_read();
                }
            } else if (ec != boost::asio::error::operation_aborted) {
                connection_manager_.close_connection(shared_from_this());
            }
        });
}

void ClientConnection::do_write() {
    auto self(shared_from_this());
    reply_.print_rep();

    boost::asio::async_write(socket_, reply_.to_buffers(),
        [this, self](boost::system::error_code ec, std::size_t) {
            if (!ec) {
                boost::system::error_code ignored_ec;
                socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
            }

            if (ec != boost::asio::error::operation_aborted) {
                connection_manager_.close_connection(shared_from_this());
            }
        });
}

} // namespace AsyncServer
} // namespace http