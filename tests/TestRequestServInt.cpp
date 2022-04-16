#include <gtest/gtest.h>

#include "AsyncServer.hpp"
#include <boost/asio.hpp>
#include <string>
#include "ClientConnection.hpp"
#include "ConnectionClientManager.hpp"
#include "RequestHandler.hpp"
#include "Server.hpp"

TEST(http::AsyncServer::AsyncServer, TestRequestServIntInvalidRequest) {

    std:string request(
    "GET / HTTP/1.1\r\n
    Host: 127.0.0.1:8000\r\n
    User-Agent: curl/7.68.0\r\n
    Accept: */*\r\n
    \r\n");


    std::string expected_method = "GET";
    std::string expected_uri = "/";
    int expected_http_version_major = 1;
    int expected_http_version_minor = 1;
    std::vector<Header> expected_headers;

    Header expected_header { "Host" , "127.0.0.1:8000" }
    expected_headers.push_back(expected_header);

    expected_header.name = "User-Agent";
    expected_header.value = "curl/7.68.0";
    expected_headers.push_back(expected_header);

    expected_header.name = "Accept";
    expected_header.value = "*/*";
    expected_headers.push_back(expected_header);


    //run

    EXPECT_EQ(expected_method, request.method);
    EXPECT_EQ(expected_uri, request.uri);
    EXPECT_EQ(expected_http_version_major, request.http_version_major);
    EXPECT_EQ(expected_http_version_minor, request.http_version_minor);

    EXPECT_EQ(expected_headers[0].name, request.headers[0].name);
    EXPECT_EQ(expected_headers[0].value, request.headers[0].value);

    EXPECT_EQ(expected_headers[1].name, request.headers[1].name);
    EXPECT_EQ(expected_headers[1].value, request.headers[1].value);

    EXPECT_EQ(expected_headers[2].name, request.headers[2].name);
    EXPECT_EQ(expected_headers[2].value, request.headers[2].value);


    std:string expected_reply (
    "HTTP/1.0 404 Not Found\r\n
    Content-Length: 85\r\n
    Content-Type: text/html\r\n
    \r\n
    Closing connection 2\r\n
    <html><head><title>Not\r\n
    Found</title></head><body>\r\n
    <h1>404 Not Found</h1>\r\n
    </body></html>\r\n");

    EXPECT_EQ(status, 404);
    EXPECT_EQ(reply.headers[0].name, "HTTP/1.0");
    EXPECT_EQ(reply.headers[0].value, "404 Not Found");

    EXPECT_EQ(reply.headers[1].name, "Content-Length");
    EXPECT_EQ(reply.headers[1].value, "85");

    EXPECT_EQ(reply.headers[2].name, "Content-Type");
    EXPECT_EQ(reply.headers[2].value, "text/html");

    EXPECT_EQ(reply.content, "<html><head><title>Not Found</title></head><body><h1>404 Not Found</h1></body></html>");

}

TEST(http::AsyncServer::AsyncServer, TestRequestServIntGetJpg) {

     std:string request(
        "GET /1.txt HTTP/1.1\r\n
        Host: 127.0.0.1:8000\r\n
        User-Agent: curl/7.68.0\r\n
        Accept: */*\r\n
        \r\n")


    std::string expected_method = "GET";
    std::string expected_uri = "/1.txt";
    int expected_http_version_major = 1;
    int expected_http_version_minor = 1;
    std::vector<Header> expected_headers;

    Header expected_header { "Host" , "127.0.0.1:8000" }
    expected_headers.push_back(expected_header);

    expected_header.name = "User-Agent";
    expected_header.value = "curl/7.68.0";
    expected_headers.push_back(expected_header);

    expected_header.name = "Accept";
    expected_header.value = "*/*";
    expected_headers.push_back(expected_header);


    //run

    EXPECT_EQ(expected_method, request.method);
    EXPECT_EQ(expected_uri, request.uri);
    EXPECT_EQ(expected_http_version_major, request.http_version_major);
    EXPECT_EQ(expected_http_version_minor, request.http_version_minor);

    EXPECT_EQ(expected_headers[0].name, request.headers[0].name);
    EXPECT_EQ(expected_headers[0].value, request.headers[0].value);

    EXPECT_EQ(expected_headers[1].name, request.headers[1].name);
    EXPECT_EQ(expected_headers[1].value, request.headers[1].value);

    EXPECT_EQ(expected_headers[2].name, request.headers[2].name);
    EXPECT_EQ(expected_headers[2].value, request.headers[2].value);


    std:string expected_reply (
        "HTTP/1.0 200 OK\r\n
        Content-Length: 574\r\n
        Content-Type: text/plain\r\n
        \r\n
        Lorem Ipsum is simply dummy text of the printing and typesetting industry.
        Lorem Ipsum has been the industry's standard dummy text ever since the 1500s,
        when an unknown printer took a galley of type and scrambled it to make a type specimen book.
        It has survived not only five centuries, but also the leap into electronic typesetting, remaining
        ssentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing
        Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker
        including versions of Lorem Ipsum.");

    EXPECT_EQ(status, 200);
    EXPECT_EQ(reply.headers[0].name, "HTTP/1.0");
    EXPECT_EQ(reply.headers[0].value, "200 OK");

    EXPECT_EQ(reply.headers[1].name, "Content-Length");
    EXPECT_EQ(reply.headers[1].value, "574");

    EXPECT_EQ(reply.headers[2].name, "Content-Type");
    EXPECT_EQ(reply.headers[2].value, "text/plain");

    EXPECT_EQ(reply.content, "Lorem Ipsum is simply dummy text of the printing and typesetting industry.
        Lorem Ipsum has been the industry's standard dummy text ever since the 1500s,
        when an unknown printer took a galley of type and scrambled it to make a type specimen book.
        It has survived not only five centuries, but also the leap into electronic typesetting, remaining
        ssentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing
        Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker
        including versions of Lorem Ipsum.");

}

TEST(http::AsyncServer::AsyncServer, TestRequestServIntGetJpg) {

     std:string request(
        "GET /2.jpg HTTP/1.1\r\n
        Host: 127.0.0.1:8000\r\n
        User-Agent: curl/7.68.0\r\n
        Accept: */*\r\n
        \r\n");


    std::string expected_method = "GET";
    std::string expected_uri = "/2.jpg";
    int expected_http_version_major = 1;
    int expected_http_version_minor = 1;
    std::vector<Header> expected_headers;

    Header expected_header { "Host" , "127.0.0.1:8000" }
    expected_headers.push_back(expected_header);

    expected_header.name = "User-Agent";
    expected_header.value = "curl/7.68.0";
    expected_headers.push_back(expected_header);

    expected_header.name = "Accept";
    expected_header.value = "*/*";
    expected_headers.push_back(expected_header);


    //run

    EXPECT_EQ(expected_method, request.method);
    EXPECT_EQ(expected_uri, request.uri);
    EXPECT_EQ(expected_http_version_major, request.http_version_major);
    EXPECT_EQ(expected_http_version_minor, request.http_version_minor);

    EXPECT_EQ(expected_headers[0].name, request.headers[0].name);
    EXPECT_EQ(expected_headers[0].value, request.headers[0].value);

    EXPECT_EQ(expected_headers[1].name, request.headers[1].name);
    EXPECT_EQ(expected_headers[1].value, request.headers[1].value);

    EXPECT_EQ(expected_headers[2].name, request.headers[2].name);
    EXPECT_EQ(expected_headers[2].value, request.headers[2].value);


    std:string expected_reply (
    "HTTP/1.0 200 OK\r\n
    Content-Length: 0\r\n
    Content-Type: image/jpeg\r\n
    \r\n")

    EXPECT_EQ(status, 200);
    EXPECT_EQ(reply.headers[0].name, "HTTP/1.0");
    EXPECT_EQ(reply.headers[0].value, "200 OK");

    EXPECT_EQ(reply.headers[1].name, "Content-Length");
    EXPECT_EQ(reply.headers[1].value, "0");

    EXPECT_EQ(reply.headers[2].name, "Content-Type");
    EXPECT_EQ(reply.headers[2].value, "image/jpeg");

    EXPECT_EQ(reply.content, "");

}

TEST(http::AsyncServer::AsyncServer, TestRequestServIntGetJpg) {

     std:string request(
        "GET /3.html HTTP/1.1\r\n
        Host: 127.0.0.1:8000\r\n
        User-Agent: curl/7.68.0\r\n
        Accept: */*\r\n
        \r\n");


    std::string expected_method = "GET";
    std::string expected_uri = "/3.html";
    int expected_http_version_major = 1;
    int expected_http_version_minor = 1;
    std::vector<Header> expected_headers;

    Header expected_header { "Host" , "127.0.0.1:8000" }
    expected_headers.push_back(expected_header);

    expected_header.name = "User-Agent";
    expected_header.value = "curl/7.68.0";
    expected_headers.push_back(expected_header);

    expected_header.name = "Accept";
    expected_header.value = "*/*";
    expected_headers.push_back(expected_header);


    //run

    EXPECT_EQ(expected_method, request.method);
    EXPECT_EQ(expected_uri, request.uri);
    EXPECT_EQ(expected_http_version_major, request.http_version_major);
    EXPECT_EQ(expected_http_version_minor, request.http_version_minor);

    EXPECT_EQ(expected_headers[0].name, request.headers[0].name);
    EXPECT_EQ(expected_headers[0].value, request.headers[0].value);

    EXPECT_EQ(expected_headers[1].name, request.headers[1].name);
    EXPECT_EQ(expected_headers[1].value, request.headers[1].value);

    EXPECT_EQ(expected_headers[2].name, request.headers[2].name);
    EXPECT_EQ(expected_headers[2].value, request.headers[2].value);


    std:string expected_reply (
        "HTTP/1.0 200 OK\r\n
        Content-Length: 581\r\n
        Content-Type: text/html\r\n
        \r\n
        <b>Lorem Ipsum is simply dummy text of the printing and typesetting
        industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when
        an unknown printer took a galley of type and scrambled it to make a type specimen book.
        It has survived not only five centuries, but also the leap into electronic typesetting, remaining
        essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing
        Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker
        including versions of Lorem Ipsum.</b>");

    EXPECT_EQ(status, 200);
    EXPECT_EQ(reply.headers[0].name, "HTTP/1.0");
    EXPECT_EQ(reply.headers[0].value, "200 OK");

    EXPECT_EQ(reply.headers[1].name, "Content-Length");
    EXPECT_EQ(reply.headers[1].value, "581");

    EXPECT_EQ(reply.headers[2].name, "Content-Type");
    EXPECT_EQ(reply.headers[2].value, "text/html");

    EXPECT_EQ(reply.content, "<b>Lorem Ipsum is simply dummy text of the printing and typesetting
        industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when
        an unknown printer took a galley of type and scrambled it to make a type specimen book.
        It has survived not only five centuries, but also the leap into electronic typesetting, remaining
        essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing
        Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker
        including versions of Lorem Ipsum.</b>");

}