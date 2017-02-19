cmake_minimum_required(VERSION 3.6)
project(rsa-crypt)

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
        src/main/REPL.cpp
        src/main/REPL.h
        src/main/RSA.cpp
        src/main/RSA.h)

set(TESTS_FILES
        src/test/bigint/BigIntTest.cpp
        src/test/RSA.cpp
        src/test/REPL.cpp)

set(LONG_TESTS_FILES
        src/test/bigint/BigIntGeneratedTest.cpp)

add_subdirectory(src/test/lib/googletest-master)
include_directories(src/test/lib/googletest-master/googletest/include)
include_directories(src/test/lib/googletest-master/googlemock/include)

add_executable(main ${SOURCE_FILES} src/main/main.cpp)
target_compile_definitions(main PRIVATE NDEBUG)

add_executable(main_debug ${SOURCE_FILES} src/main/main.cpp)
target_compile_definitions(main_debug PRIVATE CELL_SIZE=8)

add_executable(tests ${SOURCE_FILES} ${TESTS_FILES} src/test/main.cpp)
target_link_libraries(tests gtest gtest_main)

add_executable(tests_long ${SOURCE_FILES} ${TESTS_FILES} ${LONG_TESTS_FILES} src/test/main.cpp)
target_link_libraries(tests_long gtest gtest_main)

add_executable(tests_8bit ${SOURCE_FILES} ${TESTS_FILES} src/test/main.cpp)
target_link_libraries(tests_8bit gtest gtest_main)
target_compile_definitions(tests_8bit PRIVATE CELL_SIZE=8)

add_executable(tests_long_8bit ${SOURCE_FILES} ${TESTS_FILES} ${LONG_TESTS_FILES} src/test/main.cpp)
target_link_libraries(tests_long_8bit gtest gtest_main)
target_compile_definitions(tests_long_8bit PRIVATE CELL_SIZE=8)
