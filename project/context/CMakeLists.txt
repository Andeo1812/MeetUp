project(Context)

file(GLOB SOURCES src/*.cpp)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(Context_lib_libs ${PROJECT_NAME} PARENT_SCOPE)
set(Context_lib_include ${INCLUDE_DIRS} PARENT_SCOPE)

