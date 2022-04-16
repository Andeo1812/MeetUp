cmake_minimum_required(VERSION 3.16.3)
project(test_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "g++-10")
set(CMAKE_CXX_FLAGS "-std=c++20 -fcoroutines -lpthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")


file(GLOB SOURCES *.cpp)

set(SOURCES
    TestAsynhGetSeq.cpp
    TestClientConnetion.cpp
    TestClientConnetion.cpp)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${SERVER_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} GTest::GTest GTest::Main)
