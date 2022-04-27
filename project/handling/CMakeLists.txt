project(Handling)

file(GLOB SOURCES src/*.cpp
                src/Data/*.cpp
                src/Group/Base/*.cpp
                src/Group/MeetUp/*.cpp
                src/Group/MeetUp/SupportMeetUp/src/*.cpp
                src/Group/User/*.cpp)

set(Include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include/virtual/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/Data/
                ${CMAKE_CURRENT_SOURCE_DIR}/include/impl/Group/)

file(GLOB INCLUDE_DIRS Include_dir)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Include_dir})
target_link_libraries(${PROJECT_NAME} ${Context_lib_libs} ${Database_lib_libs})

set(Handling_lib_libs ${PROJECT_NAME} PARENT_SCOPE)
set(Handling_lib_include ${INCLUDE_DIRS} PARENT_SCOPE)

