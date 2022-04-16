

#include <gtest/gtest.h>

#include "AsyncServer.hpp"


TEST(main, StartServer) {

    char address[] = "127.0.0.1";
    char port[] = "8000";
    char dock_root[] = "../send";

    EXPECT_NO_THROW(http::AsyncServer::AsyncServer s(address, port, dock_root));


}
