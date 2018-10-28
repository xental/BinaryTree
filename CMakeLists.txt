cmake_minimum_required(VERSION 3.10)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SUBDIRS "${CMAKE_CURRENT_SOURCE_DIR}/third_party/*")
include_directories(${SUBDIRS})
add_subdirectory(${SUBDIRS})


set(MODULE      "BinaryTree")
set(LIBRARY     "Lib${MODULE}")
set(TESTS       "run_tests")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory("src")
add_subdirectory("test")
enable_testing()
