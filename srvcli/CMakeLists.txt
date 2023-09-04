cmake_minimum_required(VERSION 3.4.1)

set(top_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)

include_directories(inc src)
add_library(comm STATIC src/comm.cpp)
add_executable(srv src/srv.cpp)
add_executable(cli src/cli.cpp)
if(WIN32)
  target_link_libraries(srv comm wsock32 ws2_32 )
  target_link_libraries(cli comm wsock32 ws2_32 )
else()
target_link_libraries(comm)
target_link_libraries(comm)
endif()

