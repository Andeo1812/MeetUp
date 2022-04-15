cmake_minimum_required(VERSION 3.16.3)
project(http)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "g++-10")
set(CMAKE_CXX_FLAGS "-std=c++20 -fcoroutines -lpthread")

# set(CMAKE_CXX_COMPILER "clang++")
# set(CMAKE_CXX_FLAGS "-fcoroutines-ts --stdlib=libc++ -Xclang -std=c++20")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi ")
# set (CMAKE_CXX_STANDARD 20)

find_package( Boost COMPONENTS system thread filesystem REQUIRED )
# file(GLOB SOURCES
#                 connection_manager.cpp.c
#                 connection.cpp
#                 mime_types.cpp
#                 reply.cpp
#                 request_handler.cpp
#                 request_parser.cpp
#                 server.cpp )

file(GLOB SOURCES *.c)
# file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})


include_directories( ${CMAKE_CURRENT_SOURCE_DIR})
# set(PRINTER_LIB_INCLUDE_DIRS))
# add_library(${PROJECT_NAME} STATIC ${SOURCES})
# set(PRINTER_LIB_LIBRARIE
# set(PRINTER_LIB_INCLUDE_DIRS)

add_executable( ${PROJECT_NAME} main.cpp )
target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )