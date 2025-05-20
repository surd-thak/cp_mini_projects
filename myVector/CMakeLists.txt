cmake_minimum_required(VERSION 3.10)
project(MyVectorTest)

set(CMAKE_CXX_STANDARD 17)

# GoogleTest setup using FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Your test executable
add_executable(runTests test.cpp)

# Link GoogleTest
target_link_libraries(runTests gtest_main)

# Include your own header files if needed
target_include_directories(runTests PRIVATE ${CMAKE_SOURCE_DIR})

# Make tests discoverable by CTest
include(GoogleTest)
gtest_discover_tests(runTests)
