cmake_minimum_required(VERSION 3.5)

project(03_hello_world_gui LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(03_hello_world_gui
  main.cpp
)
target_link_libraries(03_hello_world_gui Qt5::Core)
