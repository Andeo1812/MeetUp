project(Database)

file(GLOB SOURCES PostgreSQL/*.cpp)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include/virtual/)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/PostgreSQL/)

set(Include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/
        ${CMAKE_CURRENT_SOURCE_DIR}/include/virtual/
        ${CMAKE_CURRENT_SOURCE_DIR}/PostgreSQL/)

file(GLOB INCLUDE_DIRS Include_dir)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Include_dir})
target_link_libraries(${PROJECT_NAME} ${Context_lib_libs})

set(Database_lib_libs ${PROJECT_NAME} CACHE FILEPATH "" FORCE)
set(Database_lib_include ${Include_dir} CACHE FILEPATH "" FORCE)
