project(Parsing)

file(GLOB SOURCES JSON/src/*.cpp
                JSON/src/Data/*.cpp
                JSON/src/Group/*.cpp)

set(Parser_lib ${CMAKE_CURRENT_SOURCE_DIR}/JSON/single_include/nlohmann/)

set(Include_dir Parser_lib
                ${CMAKE_CURRENT_SOURCE_DIR}/include/virtual/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/Data/)

file(GLOB INCLUDE_DIRS Include_dir)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC Include_dir)
target_link_libraries(${PROJECT_NAME} ${Context_lib_libs})

set(Parsing_lib_libs ${PROJECT_NAME} PARENT_SCOPE)
set(Parsing_lib_include ${INCLUDE_DIRS} PARENT_SCOPE)

