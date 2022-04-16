


#include <gtest/gtest.h>

#include <set>
#include "ClientConnection.hpp"
#include "ConnectionManager.hpp"
#include "AsyncServer.hpp"
#include <boost/asio.hpp>
#include <string>
#include "ClientConnection.hpp"
#include "ConnectionClientManager.hpp"
#include "RequestHandler.hpp"
#include "Server.hpp"



TEST(http::AsyncServer::ClientConnection, TestClientConnectionInvalidRequest) {

    std:string request(
        "GET / HTTP/1.1\r\n
        Host: 127.0.0.1:8000\r\n
        User-Agent: curl/7.68.0\r\n
        Accept: */*\r\n
        \r\n");

    http::AsyncServer::ClientConnection conn;

    conn.do_read();

    EXPECT_EQ(conn.buffer.data(), "GET / HTTP/1.1\nHost: 127.0.0.1:8000\nUser-Agent: curl/7.68.0\nAccept: */*\n");


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

    conn.do_write();

    EXPECT_EQ(conn.buffers[0], "HTTP/1.0 404 Not Found\r\n");

    EXPECT_EQ(conn.buffers[1], "Content-Length");
    EXPECT_EQ(conn.buffers[2], ": ");
    EXPECT_EQ(conn.buffers[3], "85");
    EXPECT_EQ(conn.buffers[4], "\r\n");

    EXPECT_EQ(conn.buffers[5], "Content-Type");
    EXPECT_EQ(conn.buffers[6], ": ");
    EXPECT_EQ(conn.buffers[7], "text/html");
    EXPECT_EQ(conn.buffers[8], "\r\n");

    EXPECT_EQ(conn.buffers[9], "\r\n");

    EXPECT_EQ(conn.buffers[10], "Closing connection 2
                                <html><head><title>Not
                                Found</title></head><body>
                                <h1>404 Not Found</h1>
                                </body></html>");



}


TEST(http::AsyncServer::ClientConnection, TestClientConnectionInvalidRequest) {

    std:string request(
        "GET /2.jpg HTTP/1.1\r\n
        Host: 127.0.0.1:8000\r\n
        User-Agent: curl/7.68.0\r\n
        Accept: */*\r\n
        \r\n");

    http::AsyncServer::ClientConnection conn;

    conn.do_read();

    EXPECT_EQ(conn.buffer.data(), "GET /2.jpg HTTP/1.1\nHost: 127.0.0.1:8000\nUser-Agent: curl/7.68.0\nAccept: */*");


    std:string expected_reply (
        "HTTP/1.0 200 OK
        Content-Length: 0
        Content-Type: image/jpeg");

    conn.do_write();

    EXPECT_EQ(conn.buffers[0], "HTTP/1.0 200 OK\r\n");

    EXPECT_EQ(conn.buffers[1], "Content-Length");
    EXPECT_EQ(conn.buffers[2], ": ");
    EXPECT_EQ(conn.buffers[3], "0");
    EXPECT_EQ(conn.buffers[4], "\r\n");

    EXPECT_EQ(conn.buffers[5], "Content-Type");
    EXPECT_EQ(conn.buffers[6], ": ");
    EXPECT_EQ(conn.buffers[7], "image/jpeg");
    EXPECT_EQ(conn.buffers[8], "\r\n");

    EXPECT_EQ(conn.buffers[9], "\r\n");

    EXPECT_EQ(conn.buffers[10], "");

}

