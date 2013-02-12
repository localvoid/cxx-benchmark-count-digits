cmake_minimum_required(VERSION 2.8)

project(benchmark-count-digits)


option(ENABLE_CPU_AFFINITY "Set CPU affinity in benchmark applications" OFF)
option(BUILD_TESTS "Build test applications" ON)


set(CXX_WARNING_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "-fvisibility=hidden -fno-rtti -pipe -std=gnu++11 ${CXX_WARNING_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG    "-O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE  "-mtune=native -march=native -O3 -g -DNDEBUG")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--as-needed -Wl,--hash-style=gnu")


if(ENABLE_CPU_AFFINITY)
  add_definitions( -DENABLE_CPU_AFFINITY )
endif()

function(add_benchmark_executable NAME)
  add_executable(${NAME} src/benchmark.cpp src/${NAME}.cpp)
  if(BUILD_TESTS)
    add_executable(test-${NAME} src/test.cpp src/${NAME}.cpp)
  endif()
endfunction()


add_benchmark_executable(naive)
add_benchmark_executable(cmp)
add_benchmark_executable(reverse_cmp)
add_benchmark_executable(range_case)
add_benchmark_executable(range_case2)
add_benchmark_executable(unroll4)
add_benchmark_executable(bchop)
add_benchmark_executable(bsearch)
add_benchmark_executable(bth-bsr)
add_benchmark_executable(bth-clz)
