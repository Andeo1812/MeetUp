project(Base)

file(GLOB SOURCES src/*.cpp)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include/virtual/)

find_package(Boost REQUIRED)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} ${BOOST} ${CMAKE_THREAD_LIBS_INIT})

set(Base_lib_libs ${PROJECT_NAME} PARENT_SCOPE)
set(Base_lib_include ${INCLUDE_DIRS} PARENT_SCOPE)

