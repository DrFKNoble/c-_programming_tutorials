cmake_minimum_required(VERSION 3.5)

project(lisitng20_9 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(lisitng20_9
  main.cpp
)
target_link_libraries(lisitng20_9 Qt5::Core)
