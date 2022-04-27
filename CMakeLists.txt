CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

PROJECT(HttpServer)

ADD_SUBDIRECTORY(project)

option(DEBUG "no release" ON)
option(RELEASE "in production" OFF)

if (DEBUG)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_FLAGS "-g -O0 -lpq -fprofile-arcs -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -Wlogical-op -Wredundant-decls -Wsign-conversion -Wcast-align -Wcast-qual -Wconversion -Wduplicated-branches -Wduplicated-cond -Wfloat-equal")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")
endif(DEBUG)

#add_subdirectory(gtest)
