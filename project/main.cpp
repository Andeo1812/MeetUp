// #define BOOST_ASIO_ENABLE_HANDLER_TRACKING

#include <iostream>
#include <string>
#include <boost/asio.hpp>

#include "AsyncServer.hpp"

int main(int argc, char* argv[]) {
    try {
        if (argc != 4) {
            std::cerr << "Usage: http_server <address> <port> <root_file_storage>\n";
            std::cerr << "  For IPv4, try:\n";
            std::cerr << "    receiver 0.0.0.0 80 .\n";
            std::cerr << "  For IPv6, try:\n";
            std::cerr << "    receiver 0::0 80 .\n";
            return 1;
        }

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