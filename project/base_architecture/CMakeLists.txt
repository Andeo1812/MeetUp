project(Base)

file(GLOB SOURCES src/*.cpp)

set(Include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/
        ${CMAKE_CURRENT_SOURCE_DIR}/include/virtual/)

file(GLOB INCLUDE_DIRS Include_dir)

find_package(Boost REQUIRED)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Include_dir})
target_link_libraries(${PROJECT_NAME} ${BOOST} ${CMAKE_THREAD_LIBS_INIT})

set(Base_lib_libs ${PROJECT_NAME} PARENT_SCOPE)
set(Base_lib_include ${Include_dir} PARENT_SCOPE)

