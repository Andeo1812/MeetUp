project(Server)

find_package( Boost COMPONENTS system thread filesystem REQUIRED )

set(CMAKE_CXX_FLAGS "-std=c++20 -fcoroutines -lpthread")

file(GLOB SOURCES
        src/*.cpp)

set(Include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include/virtual/
        ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/)

file(GLOB INCLUDE_DIRS ${Include_dir})

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Include_dir} ${Routing_lib_include})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES} ${Context_lib_libs} ${Parsing_lib_libs} ${Database_lib_libs} ${Handling_lib_libs} ${Routing_lib_libs})

set(Base_lib_libs ${PROJECT_NAME} CACHE FILEPATH "" FORCE)
set(Base_lib_include ${Include_dir} CACHE FILEPATH "" FORCE)

