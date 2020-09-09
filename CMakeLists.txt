cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDLGrid)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(SDLGrid src/main.cpp src/renderer.cpp src/game_objects.h src/controller.cpp src/game.cpp src/grid.cpp src/random_point.cpp src/random_point.h)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(SDLGrid   ${SDL2_LIBRARIES})
