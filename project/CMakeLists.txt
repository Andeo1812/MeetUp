#add_subdirectory(base_architecture)

add_subdirectory(context)

add_subdirectory(database)

add_subdirectory(handling)

add_subdirectory(parsing)

add_subdirectory(routing)

file(GLOB SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${Routing_lib_libs})
