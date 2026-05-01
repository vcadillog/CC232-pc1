cmake_minimum_required(VERSION 3.20)
project(Semana3 LANGUAGES CXX)
include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(algorithms STATIC
    "src/DLList.cpp"
    "src/MultiLevelDLList.cpp"
)

add_compile_options(-Wall -Wextra -Wpedantic)

target_include_directories(algorithms PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(pc2_demo_create_adt "demos/create_adt.cpp")
target_link_libraries(pc2_demo_create_adt PRIVATE algorithms)

add_executable(test_internal "tests/test_internal.cpp")
target_link_libraries(test_internal PRIVATE algorithms)

add_test(NAME pc2_test_internal COMMAND test_internal)
