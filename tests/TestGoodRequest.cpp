#include <gtest/gtest.h>

#include "AsyncServer.hpp"
#include <boost/asio.hpp>
#include <string>
#include "ClientConnection.hpp"
#include "ConnectionClientManager.hpp"
#include "RequestHandler.hpp"
#include "Server.hpp"

#include <fstream>

TEST(case_1, TestRequestServIntGoodRequest) {
    std::string host_name = "127.0.0.1 8000";
    std::string test_file = "GoodRequest.txt";

    std::string command = "echo 'POST / HTTP/1.1\r\nHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n*CONTENT BODY*:{[\"a\" : \"b\"]}\r\n' | ncat "
        + host_name + " > " + test_file;

    system(command.c_str());


    std::ifstream fin1(test_file);
    std::ifstream fin2("GoodRequest_1.gold");
    ASSERT_TRUE(fin1);
    ASSERT_TRUE(fin2);

    char ch1, ch2;
    bool result = true;
    while (fin1.get(ch1) && fin2.get(ch2)) {
        if (ch1 != ch2) {
            result = false;
            break;
        }
    }
    ASSERT_FALSE(result == true);
}