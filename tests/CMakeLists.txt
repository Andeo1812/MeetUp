cmake_minimum_required(VERSION 3.16.3)
project(test_server)


find_package(GTest REQUIRED)


file(GLOB SOURCES
    integrated_tests/TestAsynhGetSeq.cpp
    integrated_tests/TestInvalidRequest.cpp
    integrated_tests/TestGoodRequest.cpp)


add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${server_lib_include})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${GTEST_BOTH_LIBRARIES} GTest::GTest GTest::Main)
