#include <gtest/gtest.h>

#include <string>
#include <fstream>
#include <boost/asio.hpp>

#include "AsyncServer.hpp"
#include "ClientConnection.hpp"
#include "ConnectionClientManager.hpp"
#include "RequestHandler.hpp"
#include "Server.hpp"

TEST(case_1, TestRequestServIntGoodRequest) {
    std::string host_name = "127.0.0.1 8000";

    std::string test_file = "tests/integrated_tests/GoodRequest.txt";
    std::string gold_file = "tests/integrated_tests/GoodRequest_1_gold.txt";

    std::string command = "echo 'POST / HTTP/1.1\r\nHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n*CONTENT BODY*:{[\"a\" : \"b\"]}\r\n' | netcat "
        + host_name + " > " + test_file;

    system(command.c_str());


    std::ifstream fin1(test_file);
    std::ifstream fin2(gold_file);
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
    EXPECT_EQ(result, true);
}

TEST(case_2, TestRequestServIntGoodRequest) {
    std::string host_name = "127.0.0.1 8000";
    std::string test_file = "tests/integrated_tests/GoodRequest.txt";
    std::string gold_file = "tests/integrated_tests/GoodRequest_2_gold.txt";

    std::string command = "echo 'POST / HTTP/1.1\r\nHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n{\"name\": \"Иван\",\"age\": 37,\"mother\": {\"name\": \"Ольга\",\"age\": 58},\"children\": [\"Маша\",\"Игорь\",\"Таня\"],\"married\": true,\"dog\": null}\r\n' | netcat "
        + host_name + " > " + test_file;

    system(command.c_str());


    std::ifstream fin1(test_file);
    std::ifstream fin2(gold_file);
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
    EXPECT_EQ(result, true);
}

TEST(case_3, TestRequestServIntGoodRequest) {
    std::string host_name = "127.0.0.1 8000";
    std::string test_file = "tests/integrated_tests/GoodRequest.txt";
    std::string gold_file = "tests/integrated_tests/GoodRequest_3_gold.txt";

    std::string command = "echo 'POST / HTTP/1.1\r\nHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n{\"Comment\":\"My comment\",\"Count\":10,\"DiskParam\":{\"DB\":10.000000,\"DBAngle\":1.234000},\"Range\":true,\"Blades\":[{\"Caption\":\"A\",\"Value\":65},{\"Caption\":\"B\",\"Value\":66},{\"Caption\":\"C\",\"Value\":67}],\"Slots\":[0,1,2]}\r\n' | netcat "
        + host_name + " > " + test_file;

    system(command.c_str());


    std::ifstream fin1(test_file);
    std::ifstream fin2(gold_file);
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
    EXPECT_EQ(result, true);
}

TEST(case_4, TestRequestServIntGoodRequest) {
    std::string host_name = "127.0.0.1 8000";
    std::string test_file = "tests/integrated_tests/GoodRequest.txt";
    std::string gold_file = "tests/integrated_tests/GoodRequest_4_gold.txt";

    std::string command = "echo 'GET / HTTP/1.1\r\nHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n' | netcat "
        + host_name + " > " + test_file;

    system(command.c_str());


    std::ifstream fin1(test_file);
    std::ifstream fin2(gold_file);
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
    EXPECT_EQ(result, true);
}
