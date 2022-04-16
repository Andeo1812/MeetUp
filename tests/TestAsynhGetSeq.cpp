

#include <gtest/gtest.h>

#include <set>
#include "ClientConnection.hpp"
#include "ConnectionManager.hpp"
#include "AsynhServer.hpp"
#include <boost/asio.hpp>
#include <string>
#include "ClientConnection.hpp"
#include "ConnectionClientManager.hpp"
#include "RequestHandler.hpp"
#include "Server.hpp"

TEST(main, StartServer) {
    TreatedPart *result = NULL;
    ASSERT_TRUE(result == NULL);

    char address[] = "127.0.0.1";
    char port[] = "8000";
    char dock_root[] = "../send";

    EXPECT_NO_THROW(http::AsyncServer::AsyncServer s(address, port, dock_root));


}
