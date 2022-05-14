
#include "ConnectionClientManager.hpp"

namespace http {
namespace AsyncServer {

ConnectionClientManager::ConnectionClientManager() {}

void ConnectionClientManager::open_connection(connection_ptr c) {
    connections_.insert(c);
    c->start();
}

void ConnectionClientManager::close_connection(connection_ptr c) {
    connections_.erase(c);
    c->stop();
}

void ConnectionClientManager::stop_all() {
    for (auto c: connections_) {
        c->stop();
    }
    connections_.clear();
}

} // namespace AsyncServer
} // namespace http