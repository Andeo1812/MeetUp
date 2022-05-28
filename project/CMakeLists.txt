#add_subdirectory(base_architecture)

set(Config_include ${CMAKE_CURRENT_SOURCE_DIR}/configs/)

set(Config ${Config_include} CACHE FILEPATH "" FORCE)
message("Config = ${Config}")

add_subdirectory(context)

add_subdirectory(database)

add_subdirectory(handling)

add_subdirectory(parsing)

add_subdirectory(routing)

file(GLOB SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
#target_link_libraries(${PROJECT_NAME} ${Base_lib_libs} ${Routing_lib_libs})
