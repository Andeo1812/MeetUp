// #define BOOST_ASIO_ENABLE_HANDLER_TRACKING

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "AsyncServer.hpp"

int main(int argc, char* argv[]) {
    try {
        // Check command line arguments.
        // curl POST 1.txt 127.0.0.1:8000 --verbose
        // curl -d 'SIMPLE JSON {["a" : "b"]}\\r\\n' POST /1.txt 127.0.0.1:8000 --verbose
        // curl -X POST -F 'name=andreyex' -F 'email=andreyex@example.ru' -I 127.0.0.1:8000
        // curl -H 'Content-Type: application/json' --data '{"param1":"test1","param2":"test2"}' 127.0.0.1:8000
        // echo -en "POST / HTTP/1.1\r\nHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n*CONTENT BODY*:{[\"a\" : \"b\"]}\r\n" | ncat  127.0.0.1 8000
        // echo -en "GET /1.txt HTTP/1.1\r\nHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n*CONTENT BODY*:{[\"a\" : \"b\"]}\r\n" | ncat  127.0.0.1 8000
        // *CONTENT BODY*:{["a" : "b"]}
        // telnet http://x.x.x.x yyyy
        // GET /service=test&par=1&par=2&val=1 HTTP/1.1
        // echo -e "GET http://x.x.x.x:yyyy/service=test&par=1&par=2&val=1 HTTP/1.1\n\n" | nc x.x.x.x 80
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