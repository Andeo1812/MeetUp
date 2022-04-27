CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

PROJECT(HttpServer)

option(DEBUG "no release" ON)
option(RELEASE "in production" OFF)

#-Wall -Wextra -Werror -Wpedantic

if (DEBUG)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_FLAGS "-g -O0 -lpq -fprofile-arcs -fprofile-arcs -ftest-coverage -Wlogical-op -Wredundant-decls -Wsign-conversion -Wcast-align -Wcast-qual -Wconversion -Wduplicated-branches -Wduplicated-cond -Wfloat-equal")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")
endif(DEBUG)

ADD_SUBDIRECTORY(project)

add_subdirectory(gtest)

message("Base_lib_libs = ${Base_lib_libs}")
message("Base_lib_include = ${Base_lib_include}")

message("Context_lib_libs = ${Context_lib_libs}")
message("Context_lib_include = ${Context_lib_include}")

message("Parsing_lib_libs = ${Parsing_lib_libs}")
message("Parsing_lib_include = ${Parsing_lib_include}")

message("Database_lib_libs = ${Database_lib_libs}")
message("Database_lib_include = ${Database_lib_include}")

message("Handling_lib_libs = ${Handling_lib_libs}")
message("Handling_lib_include = ${Handling_lib_include}")

message("Routing_lib_libs = ${Routing_lib_libs}")
message("Routing_lib_include = ${Routing_lib_include}")
