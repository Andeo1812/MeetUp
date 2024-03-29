

#ifndef HTTP_CONNECTION_HPP
#define HTTP_CONNECTION_HPP

#include <array>
#include <memory>
#include <boost/asio.hpp>

#include "Reply.hpp"
#include "HttpRequest.hpp"
#include "RequestHandler.hpp"
#include "RequestParser.hpp"
#include "Connection.hpp"

namespace http {
namespace AsyncServer {

class ConnectionClientManager;

/// Represents a single connection from a client.
class ClientConnection : public std::enable_shared_from_this<ClientConnection> , public Connection {
public:
    ClientConnection(const ClientConnection&) = delete;
    ClientConnection& operator=(const ClientConnection&) = delete;

    /// Construct a connection with the given socket.
    explicit ClientConnection(boost::asio::io_context& io_context, boost::asio::ip::tcp::socket&& socket,
        ConnectionClientManager& manager, RequestHandler& handler);

    /// Start the first asynchronous operation for the connection.
    void start() override;

    /// Stop all asynchronous operations associated with the connection.
    void stop() override;

private:
    /// Perform an asynchronous read operation.
    void do_read() override;

    /// Perform an asynchronous handle operation.
    void do_handle() override;
    boost::asio::steady_timer timer;
    void async_get(std::string& str, boost::asio::steady_timer* timer);
    /// Perform an asynchronous write operation.
    void do_write() override;

    /// Socket for the connection.
    boost::asio::ip::tcp::socket socket_;

    /// The manager for this connection.
    ConnectionClientManager& connection_manager_;

    /// The handler used to process the incoming request.
    RequestHandler& request_handler_;

    /// Buffer for incoming data.
    std::array<char, 8192> buffer_;

    /// The incoming request.
    HttpRequest request_;

    /// The parser for the incoming request.
    RequestParser request_parser_;

    /// The reply to be sent back to the client.
    Reply reply_;
};

typedef std::shared_ptr<ClientConnection> connection_ptr;

} // namespace AsyncServer
} // namespace http

#endif // HTTP_CONNECTION_HPP