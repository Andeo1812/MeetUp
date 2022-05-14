
#include <signal.h>
#include <utility>
#include <iostream>

#include "AsyncServer.hpp"

namespace http {
namespace AsyncServer {

AsyncServer::AsyncServer(const std::string& address, const std::string& port,
                        const std::string& doc_root): io_context_(1),
                        signals_(io_context_),
                        acceptor_(io_context_),
                        connection_manager_(),
                        request_handler_(doc_root) {
    signals_.add(SIGINT);
    signals_.add(SIGTERM);
    signals_.add(SIGQUIT);

    do_await_stop();

    boost::asio::ip::tcp::resolver resolver(io_context_);
    boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve(address, port).begin();
    acceptor_.open(endpoint.protocol());
    acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    acceptor_.bind(endpoint);
    acceptor_.listen();

    do_accept();
}

void AsyncServer::run() {
    // The io_context::run() call will block until all asynchronous operations
    // have finished. While the server is running, there is always at least one
    // asynchronous operation outstanding: the asynchronous accept call waiting
    // for new incoming connections.
    io_context_.run();
}

void AsyncServer::do_accept() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket) {
            if (!acceptor_.is_open()) {
                return;
            }

            if (!ec) {
                connection_manager_.open_connection(std::make_shared<ClientConnection>(io_context_,
                    std::move(socket), connection_manager_, request_handler_));
            }

            do_accept();
        });
}

void AsyncServer::do_await_stop() {
    signals_.async_wait(
        [this](boost::system::error_code ec, int signo) {
            if (signo == SIGINT) {
                std::cout << "GET SIGINT " << signo << std::endl;
            }

            if (signo == SIGTERM) {
                std::cout << "GET SIGTERM " << signo << std::endl;
            }

            if (signo == SIGQUIT) {
                std::cout << "GET SIGQUIT " << signo << std::endl;

                // handler for future user command
                std::cout << "*DO LOGIC*" << std::endl;
                do_await_stop();
                return;
            }

            acceptor_.close();
            connection_manager_.stop_all();
        });
}

} // namespace AsyncServer
} // namespace http