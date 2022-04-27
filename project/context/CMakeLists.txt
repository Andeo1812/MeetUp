project(Context)

file(GLOB SOURCES src/*.cpp)

set(Include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include/)

file(GLOB INCLUDE_DIRS Include_dir)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Include_dir})

set(Context_lib_libs ${PROJECT_NAME} PARENT_SCOPE)
set(Context_lib_include ${INCLUDE_DIRS} PARENT_SCOPE)

