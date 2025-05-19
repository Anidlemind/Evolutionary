cmake_minimum_required(VERSION 3.15)
project(Evolution)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SRC
    src/*.cpp
)

add_executable(main
    ${SRC}
    client/main.cpp
)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB TESTS
    "tests/*.cpp"
)

add_executable(tests ${TESTS} ${SRC})


target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(tests gtest_main)

target_include_directories(main PUBLIC include)
target_include_directories(main PRIVATE include)