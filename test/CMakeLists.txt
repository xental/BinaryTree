set(target ${TESTS})
file(GLOB srcs "*.cpp")

add_executable(${target} ${srcs})
if (UNIX)
    target_link_libraries(${target} gtest ${CMAKE_THREAD_LIBS_INIT}  pthread)
endif (UNIX)
target_link_libraries(${target} gtest ${LIBRARY})