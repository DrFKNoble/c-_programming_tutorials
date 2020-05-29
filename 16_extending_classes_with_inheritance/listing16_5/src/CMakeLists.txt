cmake_minimum_required(VERSION 3.17.2)

# Set the project name
project(listing)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add executable target to be built
add_executable(listing16_5 listing16_5.cpp)

# Install built executable to "bin" sub-directory
install(TARGETS listing16_5 DESTINATION ${PROJECT_SOURCE_DIR}/bin)


