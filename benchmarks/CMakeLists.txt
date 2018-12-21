set(target "${BENCH}")
file(GLOB srcs "bench*.cpp")


foreach(BENCHMARK avl;decard;splay)
    add_executable("${target}${BENCHMARK}" ${srcs} run_bench${BENCHMARK}.cpp)
    target_link_libraries("${target}${BENCHMARK}" ${LIBRARY})
endforeach(BENCHMARK)




