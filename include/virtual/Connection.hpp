

#ifndef CONNECTION_HPP
#define CONNECTION_HPP


namespace http {
namespace AsyncServer {

class ConnectionManager;

/// Interface of a single connection from a client.
class Connection {
public:
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;
    Connection() = default;
    virtual void start() = 0;

    virtual void stop() = 0;

protected:
    virtual void do_read() = 0;

    // virtual void do_handle() = 0;

    virtual void do_write() = 0;

    HttpRequest request_;

    Reply reply_;
};


} // namespace AsyncServer
} // namespace http

#endif // CONNECTION_HPP