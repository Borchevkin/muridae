###############################################################################
# CMake header
###############################################################################

cmake_minimum_required(VERSION 3.14)

###############################################################################
# Project
###############################################################################

project(muridae)

###############################################################################
# Options
###############################################################################

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

###############################################################################
# Libraries
###############################################################################

add_library(
    Snippeter SHARED
    src/snippeter.cpp
    inc/snippeter.hpp
)

target_include_directories(
    Snippeter PRIVATE
    inc/
    src/
)

add_library(
    Cli SHARED
    src/cli.cpp
    inc/cli.hpp 
)

target_include_directories(
    Cli PRIVATE
    inc/
    src/ 
)

###############################################################################
# Executable
###############################################################################

add_executable(
    muridae
    src/main.cpp
)

target_include_directories(
    muridae PUBLIC
    "${PROJECT_BINARY_DIR}"
    inc/
)

target_link_libraries(
    muridae
    Snippeter
    Cli
)

###############################################################################
# Tests
###############################################################################

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    test_unit_base
    ./tests/unit_cpp/test_unit_base.cpp
)

target_include_directories(
    test_unit_base PUBLIC
    "${PROJECT_BINARY_DIR}"
    inc/
    src/
)

target_link_libraries(
    test_unit_base
    Snippeter
    Cli
    GTest::gtest_main
)

add_executable(
    test_int_base
    ./tests/integration_cpp/test_int_base.cpp
)

target_include_directories(
    test_int_base PUBLIC
    "${PROJECT_BINARY_DIR}"
    inc/
    src/
)

target_link_libraries(
    test_int_base
    Snippeter
    Cli
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_unit_base)
gtest_discover_tests(test_int_base)

###############################################################################
# End of CMake file
###############################################################################
