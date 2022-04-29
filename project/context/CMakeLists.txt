project(Context)

file(GLOB SOURCES src/*.cpp)

set(Include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/Data/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/Group/)

file(GLOB INCLUDE_DIRS Include_dir)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Include_dir})

set(Context_lib_libs ${PROJECT_NAME} CACHE FILEPATH "" FORCE)
set(Context_lib_include ${Include_dir} CACHE FILEPATH "" FORCE)
