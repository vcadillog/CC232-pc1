cmake_minimum_required(VERSION 3.20)
project(Semana3 LANGUAGES CXX)
include(CTest)
option(BUILD_BENCHMARKS "Build benchmark targets" ON)
option(ENABLE_SANITIZERS "Enable ASan and UBSan" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(algorithms STATIC
    "src/DLList.cpp"
    "src/MultiLevelDLList.cpp"
)

add_compile_options(-Wall -Wextra -Wpedantic)

target_include_directories(algorithms PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(pc2_demo_multileveldllist "demos/demo_multileveldllist.cpp")
target_link_libraries(pc2_demo_multileveldllist PRIVATE algorithms)

add_executable(test_internal "tests/test_internal.cpp")
target_link_libraries(test_internal PRIVATE algorithms)

add_executable(edge_cases "tests/edge_cases.cpp")
target_link_libraries(edge_cases PRIVATE algorithms)

add_test(NAME pc2_test_internal COMMAND test_internal)
add_test(NAME pc2_edge_cases COMMAND edge_cases)

if (BUILD_BENCHMARKS)
    add_executable(benchmark benchmark/benchmark.cpp)
    target_link_libraries(benchmark PRIVATE algorithms)
endif()
if (ENABLE_SANITIZERS)
    message(STATUS "Sanitizers enabled")

    add_compile_options(
        -fsanitize=address,undefined
        -fno-omit-frame-pointer
        -g
    )

    add_link_options(
        -fsanitize=address,undefined
    )
endif()
