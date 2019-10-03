cmake_minimum_required(VERSION 3.14)
project(lr2)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SRCS
    "include/*.h"
    "src/lib/*.cpp"
)

file(GLOB_RECURSE TEST_SRCS
    "include/*.h"
    "tests/*.cpp"
)

include_directories(AFTER "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(lr2_lib ${SRCS})

add_executable(lr2 src/main.cpp)
add_executable(lr2_test ${TEST_SRCS})

target_link_libraries(lr2 lr2_lib)
target_link_libraries(lr2_test lr2_lib)