

#ifndef SERVER_HPP
#define SERVER_HPP

#include <boost/asio.hpp>
#include <string>
#include "ClientConnection.hpp"
#include "ConnectionClientManager.hpp"
#include "RequestHandler.hpp"

class Server {
public:
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;

    virtual ~Server() = default;
    Server() = default;

    /// Run the server's io_context loop.
    virtual void run() = 0;

protected:
    virtual void do_accept() = 0;

    virtual void do_await_stop() = 0;
};

#endif // HTTP_SERVER_HPP
