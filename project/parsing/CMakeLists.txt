project(Parsing)

find_package(nlohmann_json 3.10.5 REQUIRED)

file(GLOB SOURCES JSON/src/*.cpp
                JSON/src/Data/*.cpp
                JSON/src/Group/*.cpp)

set(Include_dir ${Config}
                ${CMAKE_CURRENT_SOURCE_DIR}/include/virtual/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/Data/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/Group/)

file(GLOB INCLUDE_DIRS ${Include_dir})

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Include_dir})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Context_lib_libs}  nlohmann_json::nlohmann_json)

set(Parsing_lib_libs ${PROJECT_NAME} CACHE FILEPATH "" FORCE)
set(Parsing_lib_include ${Include_dir} CACHE FILEPATH "" FORCE)
