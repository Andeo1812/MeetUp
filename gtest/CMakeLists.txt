cmake_minimum_required(VERSION 3.14)
find_package(GTest REQUIRED)

project(gtest_context)

file(GLOB SOURCES context.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Context_lib_include})
target_link_libraries(${PROJECT_NAME} ${Context_lib_libs} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})


project(gtest_parsing)

file(GLOB SOURCES parsing.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Context_lib_include})
target_link_libraries(${PROJECT_NAME} ${Context_lib_libs} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(${PROJECT_NAME} PUBLIC ${Parsing_lib_include})
target_link_libraries(${PROJECT_NAME} ${Parsing_lib_libs} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})


project(gtest_database)

file(GLOB SOURCES database.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Context_lib_include})
target_link_libraries(${PROJECT_NAME} ${Context_lib_libs} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(${PROJECT_NAME} PUBLIC ${Database_lib_include})
target_link_libraries(${PROJECT_NAME} ${Database_lib_libs} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})


project(gtest_handling)

file(GLOB SOURCES handler.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Context_lib_include})
target_link_libraries(${PROJECT_NAME} ${Context_lib_libs} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(${PROJECT_NAME} PUBLIC ${Handling_lib_include})
target_link_libraries(${PROJECT_NAME} ${Handling_lib_libs} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})


project(gtest_routing)

file(GLOB SOURCES routing.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Context_lib_include})
target_link_libraries(${PROJECT_NAME} ${Context_lib_libs} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(${PROJECT_NAME} PUBLIC ${Parsing_lib_include})
target_link_libraries(${PROJECT_NAME} ${Parsing_lib_libs} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(${PROJECT_NAME} PUBLIC ${Database_lib_include})
target_link_libraries(${PROJECT_NAME} ${Database_lib_libs} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(${PROJECT_NAME} PUBLIC ${Handling_lib_include})
target_link_libraries(${PROJECT_NAME} ${Handling_lib_libs} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(${PROJECT_NAME} PUBLIC ${Routing_lib_include})
target_link_libraries(${PROJECT_NAME} ${Routing_lib_libs} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})