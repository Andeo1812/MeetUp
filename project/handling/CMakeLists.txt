project(Handling)

file(GLOB SOURCES definition/Group/MeetUp/SupportMeetUp/src/*.cpp)

set(Include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include/virtual/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/Data/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/Group/
                ${CMAKE_CURRENT_SOURCE_DIR}/definition/Group/MeetUp/SupportMeetUp/include
                ${CMAKE_CURRENT_SOURCE_DIR}/definition/
                ${CMAKE_CURRENT_SOURCE_DIR}/definition/Data/
                ${CMAKE_CURRENT_SOURCE_DIR}/definition/Group/Base/
                ${CMAKE_CURRENT_SOURCE_DIR}/definition/Group/MeetUp/
                ${CMAKE_CURRENT_SOURCE_DIR}/definition/Group/User/)

file(GLOB INCLUDE_DIRS Include_dir)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Include_dir})
target_link_libraries(${PROJECT_NAME} ${Context_lib_libs} ${Database_lib_libs})

set(Handling_lib_libs ${PROJECT_NAME} CACHE FILEPATH "" FORCE)
set(Handling_lib_include ${Include_dir} CACHE FILEPATH "" FORCE)

