project(Routing)

file(GLOB SOURCES definition/*.cpp)

set(Include_dir ${Config}
                ${CMAKE_CURRENT_SOURCE_DIR}/definition/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/virtual/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Include_dir})
target_link_libraries(${PROJECT_NAME} ${Context_lib_libs} ${Parsing_lib_libs} ${Database_lib_libs} ${Handling_lib_libs})

set(Routing_lib_libs ${PROJECT_NAME} CACHE FILEPATH "" FORCE)
set(Routing_lib_include ${Include_dir} CACHE FILEPATH "" FORCE)

