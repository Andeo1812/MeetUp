#include <gtest/gtest.h>

#include "RouteImpl.hpp"
#include "DBManager.hpp"

TEST(Routing, functional) {
    RouteImpl<DBManager<pqxx::connection>> route;
}

