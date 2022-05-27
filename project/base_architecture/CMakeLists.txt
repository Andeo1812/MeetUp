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

set(Include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include/virtual/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/
                )
file(GLOB INCLUDE_DIRS Include_dir)

add_executable( ${PROJECT_NAME} ${SOURCES} )
target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )

set(server_lib_include ${Include_dir} CACHE FILEPATH "" FORCE)

# add_subdirectory(../../tests)

# project(Context)

# file(GLOB SOURCES src/*.cpp src/Data/*.cpp src/Group/*.cpp)

# set(Include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include/
#                 ${CMAKE_CURRENT_SOURCE_DIR}/include/Data/
#                 ${CMAKE_CURRENT_SOURCE_DIR}/include/Group/)

# file(GLOB INCLUDE_DIRS Include_dir)

# add_library(${PROJECT_NAME} STATIC ${SOURCES})
# target_include_directories(${PROJECT_NAME} PUBLIC ${Include_dir})

# set(Context_lib_libs ${PROJECT_NAME} CACHE FILEPATH "" FORCE)
# set(Context_lib_include ${Include_dir} CACHE FILEPATH "" FORCE)