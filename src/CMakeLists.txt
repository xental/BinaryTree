set(target ${LIBRARY})

file(GLOB hrcs "../include/*.h*")
file(GLOB srcs "*.cpp")

add_library(${target} SHARED ${hrcs} ${srcs})
set_target_properties(${target}
        PROPERTIES OUTPUT_NAME ${MODULE})

if (UNIX)
    target_link_libraries(${target} ${CMAKE_THREAD_LIBS_INIT})
endif (UNIX)
target_link_libraries(${target} ${LIBRARY_DEPS})