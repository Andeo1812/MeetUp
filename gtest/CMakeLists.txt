cmake_minimum_required(VERSION 3.14)

find_package(GTest REQUIRED)

if (DEBUG)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_FLAGS "-g -O0 -lpthread -fprofile-arcs -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -Wlogical-op -Wredundant-decls -Wsign-conversion -Wcast-align -Wcast-qual -Wconversion -Wduplicated-branches -Wduplicated-cond -Wfloat-equal")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")
endif(DEBUG)


project(gtest_dataclass)

file(GLOB SOURCES dataclass.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${GENERAL_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GENERAL_LIB_LIBRARIES} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})


project(gtest_parsing)

file(GLOB SOURCES parsing.cpp)


add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${GENERAL_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GENERAL_LIB_LIBRARIES} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(${PROJECT_NAME} PUBLIC ${IMPERATIVE_MODEL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${IMPERATIVE_MODEL_LIB_LIBRARIES} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})


project(gtest_database)

file(GLOB SOURCES database.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${GENERAL_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GENERAL_LIB_LIBRARIES} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(${PROJECT_NAME} PUBLIC ${MULTI_THREADED_MODEL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${MULTI_THREADED_MODEL_LIB_LIBRARIES} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})


project(gtest_handler)

file(GLOB SOURCES handler.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${GENERAL_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GENERAL_LIB_LIBRARIES} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(${PROJECT_NAME} PUBLIC ${MULTI_THREADED_MODEL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${MULTI_THREADED_MODEL_LIB_LIBRARIES} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})


project(gtest_routing)

file(GLOB SOURCES routing.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${GENERAL_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GENERAL_LIB_LIBRARIES} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(${PROJECT_NAME} PUBLIC ${MULTI_THREADED_MODEL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${MULTI_THREADED_MODEL_LIB_LIBRARIES} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})