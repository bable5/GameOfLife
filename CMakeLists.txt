project(gameoflife)
cmake_minimum_required (VERSION 2.8) 

add_executable(gameoflife main.cpp)

add_library(gameboard gameboard.cpp)

target_link_libraries(gameoflife gameboard)