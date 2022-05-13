

#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <set>
#include "ClientConnection.hpp"

namespace http {
namespace AsyncServer {

/// Interface of connection's manager
class ConnectionManager {
public:
    ConnectionManager(const ConnectionManager&) = delete;
    ConnectionManager& operator=(const ConnectionManager&) = delete;

    ConnectionManager() = default;

    /// Add the specified connection to the manager and start it.
    virtual void open_connection(connection_ptr c) = 0;

    /// Stop the specified connection.
    virtual void close_connection(connection_ptr c) = 0;

    /// Stop all connections.
    virtual void stop_all() = 0;

};

} // namespace AsyncServer
} // namespace http

#endif // MANAGER_HPP