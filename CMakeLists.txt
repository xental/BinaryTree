cmake_minimum_required(VERSION 3.9)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SUBDIRS "${CMAKE_CURRENT_SOURCE_DIR}/third_party/*")
include_directories(${SUBDIRS})
add_subdirectory(${SUBDIRS})


if ( UNIX )
    set(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Werror")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Werror")
endif( UNIX )

if ( MSVC )
    set(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} /WX")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /WX")
endif( MSVC )

set(MODULE      "BinaryTree")
set(LIBRARY     "Lib${MODULE}")
set(TESTS       "run_tests")
set(BENCH       "run_bench")


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory("src")
add_subdirectory("test")
add_subdirectory("benchmarks")
enable_testing()
