#include <gtest/gtest.h>

#include <string>
#include <fstream>
#include <boost/asio.hpp>

#include "AsyncServer.hpp"
#include "ClientConnection.hpp"
#include "ConnectionClientManager.hpp"
#include "RequestHandler.hpp"
#include "Server.hpp"

TEST(true_request, TestRequestServIntInvalidRequest) {
    std::string host_name = "127.0.0.1 8000";

    std::string test_file = "tests/integrated_tests/InvalidRequest.txt";
    std::string gold_file = "tests/integrated_tests/InvalidRequest_gold.txt";

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
    EXPECT_EQ(result, false);
}

TEST(case_1, TestRequestServIntInvalidRequest) {
    std::string host_name = "127.0.0.1 8000";

    std::string test_file = "tests/integrated_tests/InvalidRequest.txt";
    std::string gold_file = "tests/integrated_tests/InvalidRequest_gold.txt";

    std::string command = "echo 'POST / http/1.1Host: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n*CONTENT BODY*:{[\"a\" : \"b\"]}\r\n' | netcat "
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

TEST(case_2, TestRequestServIntInvalidRequest) {
    std::string host_name = "127.0.0.1 8000";

    std::string test_file = "tests/integrated_tests/InvalidRequest.txt";
    std::string gold_file = "tests/integrated_tests/InvalidRequest_gold.txt";

    std::string command = "echo 'POST / HTTP/1.1\nHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n*CONTENT BODY*:{[\"a\" : \"b\"]}\r\n' | netcat "
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

TEST(case_3, TestRequestServIntInvalidRequest) {
    std::string host_name = "127.0.0.1 8000";

    std::string test_file = "tests/integrated_tests/InvalidRequest.txt";
    std::string gold_file = "tests/integrated_tests/InvalidRequest_gold.txt";

    std::string command = "echo 'POST / HTTP/1.1\r\nHost: localhost\r\nUser-Agent: my-custom-agent\r\n*CONTENT BODY*:{[\"a\" : \"b\"]}\r\n' | netcat "
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

TEST(case_4, TestRequestServIntInvalidRequest) {
    std::string host_name = "127.0.0.1 8000";

    std::string test_file = "tests/integrated_tests/InvalidRequest.txt";
    std::string gold_file = "tests/integrated_tests/InvalidRequest_gold.txt";

    std::string command = "echo 'POST / HTTP/1.1\r\nHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n*CONTENT BODY*:{[\"a\" : \"b\"]}' | netcat "
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

TEST(case_5, TestRequestServIntInvalidRequest) {
    std::string host_name = "127.0.0.1 8000";

    std::string test_file = "tests/integrated_tests/InvalidRequest.txt";
    std::string gold_file = "tests/integrated_tests/InvalidRequest_gold.txt";

    std::string command = "echo 'POST / TTP/1.1\r\nHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n*CONTENT BODY*:{[\"a\" : \"b\"]}\r\n' | netcat "
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

TEST(case_6, TestRequestServIntInvalidRequest) {
    std::string host_name = "127.0.0.1 8000";

    std::string test_file = "tests/integrated_tests/InvalidRequest.txt";
    std::string gold_file = "tests/integrated_tests/InvalidRequest_gold.txt";

    std::string command = "echo 'POST / HTTP/1.1\n\rHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n*CONTENT BODY*:{[a : b]}\r\n' | netcat "
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

TEST(case_7, TestRequestServIntInvalidRequest) {
    std::string host_name = "127.0.0.1 8000";

    std::string test_file = "tests/integrated_tests/InvalidRequest.txt";
    std::string gold_file = "tests/integrated_tests/InvalidRequest_gold.txt";

    std::string command = "echo 'POST / HTTP/1.1\rHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n*CONTENT BODY*:{[\"a\" : \"b\"]}\r\n' | netcat "
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