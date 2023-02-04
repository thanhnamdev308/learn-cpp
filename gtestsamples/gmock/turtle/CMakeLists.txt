cmake_minimum_required(VERSION 3.0)

project(ProjectName) 

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})

# This flags are used if cmake is called with -DCMAKE_BUILD_TYPE=PROFILE
set(CMAKE_C_FLAGS_PROFILE --coverage)
set(CMAKE_CXX_FLAGS_PROFILE --coverage)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests src/test.cpp)
target_link_libraries(runTests gtest)
target_link_libraries(runTests gmock)
target_link_libraries(runTests pthread)
