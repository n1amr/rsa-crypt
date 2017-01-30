cmake_minimum_required(VERSION 3.6)
project(rsa)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
add_definitions(-std=c++11 -O2)
add_definitions(-Wall -Wextra -pedantic)
add_definitions(
        -DN1AMR
        -DN1AMR_LOCAL_PC
        -DN1AMR_MULTIPLE_FILES
        -DN1AMR_FILE_INPUT)

set(SOURCE_FILES
        src/main/bigint/BigInt.cpp
        src/main/bigint/BigIntHelpers.cpp
        src/main/App.cpp
        src/main/App.h)

set(TESTS_FILES
        src/test/bigint/BigIntTest.cpp
        src/test/AppTest.cpp)

add_subdirectory(src/test/lib/googletest-master)
include_directories(src/test/lib/googletest-master/googletest/include)
include_directories(src/test/lib/googletest-master/googlemock/include)

add_executable(main ${SOURCE_FILES} src/main/main.cpp)
add_executable(tests ${SOURCE_FILES} ${TESTS_FILES} src/test/main.cpp)
target_link_libraries(tests gtest gtest_main)
