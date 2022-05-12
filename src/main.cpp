// #define BOOST_ASIO_ENABLE_HANDLER_TRACKING

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "AsyncServer.hpp"

int main(int argc, char* argv[]) {
    try {
        // Check command line arguments.
        // curl POST /1.txt 127.0.0.1:8000 --verbose
        // ./server 127.0.0.1 8000 send
        if (argc != 4) {
            std::cerr << "Usage: http_server <address> <port> <doc_root>\n";
            std::cerr << "  For IPv4, try:\n";
            std::cerr << "    receiver 0.0.0.0 80 .\n";
            std::cerr << "  For IPv6, try:\n";
            std::cerr << "    receiver 0::0 80 .\n";
            return 1;
        }

        // Initialise the server.
        http::AsyncServer::AsyncServer s(argv[1], argv[2], argv[3]);

        // Run the server until stopped.
        std::cout << getpid() << ": PID CURRENT PROCESS" << std::endl;
        s.run();
    }
    catch (std::exception& e) {
        std::cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}