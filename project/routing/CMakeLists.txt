project(Routing)

file(GLOB SOURCES src/*.cpp)

set(Include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include/virtual/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC Include_dir)
target_link_libraries(${PROJECT_NAME} ${Context_lib_libs} ${Parsing_lib_libs} ${Database_lib_libs} ${Handling_lib_libs})

set(Routing_lib_libs ${PROJECT_NAME} PARENT_SCOPE)
set(Routing_lib_include ${INCLUDE_DIRS} PARENT_SCOPE)

