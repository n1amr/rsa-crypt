cmake_minimum_required(VERSION 3.6)
project(rsa)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DLOCAL_PC -DN1AMR -DN1AMR_f220929df")

set(SOURCE_FILES
        src/main.cpp
        src/bigint/BigInt.cpp
        src/bigint/DecimalHelpers.cpp)

add_executable(rsa ${SOURCE_FILES})

set(TESTS_SOURCE_FILES
        src/tests/main.cpp
        src/bigint/BigInt.cpp
        src/bigint/DecimalHelpers.cpp
        src/tests/bigint/bigint_tests.cpp
        src/tests/tests.cpp)

add_executable(tests ${TESTS_SOURCE_FILES})
