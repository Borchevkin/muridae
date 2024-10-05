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

add_executable(
    test_int_base
    ./tests/integration_cpp/test_int_base.cpp
)

target_link_libraries(
    test_unit_base
    GTest::gtest_main
)

target_link_libraries(
    test_int_base
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_unit_base)
gtest_discover_tests(test_int_base)

###############################################################################
# End of CMake file
###############################################################################
