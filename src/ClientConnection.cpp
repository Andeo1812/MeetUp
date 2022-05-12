
#include <boost/bind/bind.hpp>
#include "ClientConnection.hpp"
#include <utility>
#include <vector>
#include "ConnectionClientManager.hpp"
#include "RequestHandler.hpp"

#include <iostream>

#define WAIT 0
#define READY 1

namespace http {
namespace AsyncServer {

ClientConnection::ClientConnection(boost::asio::io_context& io_context, boost::asio::ip::tcp::socket &&socket,
        ConnectionClientManager& manager, RequestHandler& handler) : socket_(std::move(socket)),
        connection_manager_(manager),
        request_handler_(handler),
        timer(io_context, boost::asio::chrono::milliseconds(100)) {
        //timer(static_cast<boost::asio::io_context&>((socket_.get_executor().context())), boost::asio::chrono::milliseconds(1000)) {
    // boost::asio::executor e = socket_.get_executor();
    // boost::asio::execution_context &e_context = e.context();
    // boost::asio::io_context &context_instance = static_cast<boost::asio::io_context&>(e_context);
    // boost::asio::steady_timer t(context_instance, boost::asio::chrono::milliseconds(1000));
    // timer = t;
}

void ClientConnection::start() {
    do_read();
}

void ClientConnection::stop() {
    socket_.close();
}

std::tuple<int, std::string> get_response(std::string in) {
    std::string out;
    srand(time(NULL));
    int r = rand() % 3;
    if (r != 1) {
        return std::make_tuple(WAIT, "\n");
    }

    std::for_each(in.begin(), in.end(), [&out](unsigned char c){out.push_back(c-32);});
    return std::make_tuple(READY, out);
}

void ClientConnection::async_get(std::string str, boost::asio::steady_timer* timer) {
    auto self(shared_from_this());
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
    // auto self(shared_from_this());
    // boost::asio::executor e = socket_.get_executor();
    // boost::asio::execution_context &e_context = e.context();
    // boost::asio::io_context &context_instance = static_cast<boost::asio::io_context&>(e_context);

    // timer.async_wait([this, self, str=std::string("azaza"), &timer] (boost::system::error_code ec) {
        // check_response(str, &timer);
        // std::string response;
        // int status_handle;
        // std::tie(status_handle, response) = get_response("aaas");
        // std::cout << "5" << std::endl;
        // if (status_handle == WAIT) {
            // timer.expires_at(timer.expiry() + boost::asio::chrono::milliseconds(2000));
            // auto a = static_cast<std::string>(std::string("strqwe"));
            // timer.async_wait([this, self, t = &timer] (boost::system::error_code ec) {
            //         check_response("zaazaa", t);}/*check_response, str, timer)*/); //check_response, str, timer
            timer.async_wait(boost::bind(&ClientConnection::async_get, this, "azaza", &timer));
            // boost::bind(&ClientConnetion::check_response, str, &timer, this)
            // sleep(1);
            // print(str, ex);
        //     return;
        // } else {
        //     std::cout << "8" << std::endl;
        //     std::cout << response << std::endl;

        //     request_handler_.handle_request(request_, reply_);
        //     std::cout << "9" << std::endl;
        //     do_write();
        // }

        // });
    //boost::bind(check_response, "azaza"/*reb.body*/, &timer)

    // context_instance.post();

    // context_instance.post(boost::bind(get_response, "azaza"));
    // boost::asio::post(context_instance, boost::bind(get_response, "azaza"));
    // context_instance.post([this, self/*, &context_instance*/](std::string& in) {
    //     std::string response;
    //     int status_handle;
    //     std::tie(status_handle, response) = get_response(in);

    //     if (status_handle == WAIT) {
    //         // do_handle(); // boost::bind(do_handle)
    //     } else {
    //         std::cout << "Выполнено!\n";
    //     }

    //     // if (status_handle == WAIT) {
    //     //     boost::asio::steady_timer timer(context_instance, boost::asio::chrono::milliseconds(2000));
    //     //     timer.async_wait(boost::bind(do_handle)); // boost::bind(do_handle)
    //     // }

    // });
}

void ClientConnection::do_read() {
    // boost::asio::executor e = socket_.get_executor();
    // boost::asio::execution_context &e_context = e.context();
    // boost::asio::io_context &context_instance = static_cast<boost::asio::io_context&>(e_context);

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
                    ///
                    // boost::asio::executor e = socket_.get_executor();
                    // boost::asio::execution_context &e_context = e.context();
                    // boost::asio::io_context &context_instance = static_cast<boost::asio::io_context&>(e_context);

                    // boost::asio::steady_timer timer(context_instance, boost::asio::chrono::milliseconds(200));
                    // timer.async_wait(boost::bind(do_handle));
                    // timer.async_wait(boost::bind(do_handle, "azaza", context_instance.get_executor(), &timer));
                    std::cout << "@ ";
                    request_.print_req();
                    do_handle();
                    // request_handler_.handle_request(request_, reply_);
                    // do_write();

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
    reply_.print_rep(); // print into console
    boost::asio::async_write(socket_, reply_.to_buffers(),
        [this, self](boost::system::error_code ec, std::size_t) {
            if (!ec) {
                // Initiate graceful connection closure.
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