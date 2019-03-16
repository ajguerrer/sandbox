cmake_minimum_required(VERSION 3.13)

project(Algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CMake/FetchGoogleTest.cmake)
include(CMake/FetchAbseil.cmake)

include(CTest)
enable_testing()

add_subdirectory(binary-search)
add_subdirectory(selection-sort)