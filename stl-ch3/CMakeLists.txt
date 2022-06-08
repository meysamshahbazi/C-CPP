
# cmake needs this line
cmake_minimum_required(VERSION 3.1)

# Define project name
project(stl-ch3)


# include_directories(${CMAKE_SOURCE_DIR}/src/)
# add_subdirectory(src)

# Declare the executable target built from your sources

set (CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp)
