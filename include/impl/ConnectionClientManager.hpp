

#ifndef HTTP_CONNECTION_MANAGER_HPP
#define HTTP_CONNECTION_MANAGER_HPP

#include <set>
#include "ClientConnection.hpp"
#include "ConnectionManager.hpp"

namespace http {
namespace AsyncServer {

/// Manages open connections so that they may be cleanly stopped when the server
/// needs to shut down.
class ConnectionClientManager : public ConnectionManager{
public:
    ConnectionClientManager(const ConnectionClientManager&) = delete;
    ConnectionClientManager& operator=(const ConnectionClientManager&) = delete;

    /// Construct a connection manager.
    ConnectionClientManager();

    /// Add the specified connection to the manager and start it.
    void open_connection(connection_ptr c);

    /// Stop the specified connection.
    void close_connection(connection_ptr c);

    /// Stop all connections.
    void stop_all();

private:
    /// The managed connections.
    std::set<connection_ptr> connections_;
};

} // namespace AsyncServer
} // namespace http

#endif // HTTP_CONNECTION_MANAGER_HPP