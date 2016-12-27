cmake_minimum_required(VERSION 3.6)
project(rsa)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DN1AMR -DN1AMR_LOCAL_PC -DN1AMR_MULTIPLE_FILES -DN1AMR_FILE_INPUT -O1 -Wall -Wextra -pedantic")

set(SOURCE_FILES
        src/main.cpp
        src/bigint/BigInt.cpp
        src/bigint/BigIntHelpers.cpp
        src/App.cpp
        src/App.h)

add_executable(main ${SOURCE_FILES})

set(TESTS_SOURCE_FILES
        src/tests/main.cpp
        src/bigint/BigInt.cpp
        src/bigint/BigIntHelpers.cpp
        src/tests/bigint/bigint_tests.cpp
        src/tests/tests.cpp)

add_executable(tests ${TESTS_SOURCE_FILES})
