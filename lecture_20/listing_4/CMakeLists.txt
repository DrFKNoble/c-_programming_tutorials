cmake_minimum_required(VERSION 3.17.2)

# Set the project name
project(listing)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add executable target to be built
add_executable(listing listing.cpp)

target_include_directories(listing PUBLIC "${PROJECT_SOURCE_DIR}/")

# Install built executable to "bin" sub-directory
install(TARGETS listing DESTINATION ${PROJECT_SOURCE_DIR}/bin)


