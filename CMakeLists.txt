cmake_minimum_required(VERSION 3.16.3)
project(server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "g++-10")
set(CMAKE_CXX_FLAGS "-std=c++20 -fcoroutines -lpthread")

find_package( Boost COMPONENTS system thread filesystem REQUIRED )

include_directories( include/virtual )
include_directories( include/impl )

set(SOURCES
    src/main.cpp
    src/ConnectionClientManager.cpp
    src/ClientConnection.cpp
    src/MimeTypes.cpp
    src/Reply.cpp
    src/RequestHandler.cpp
    src/RequestParser.cpp
    src/AsyncServer.cpp)


add_executable( ${PROJECT_NAME} ${SOURCES} )
target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )

# add_subdirectory(tests)