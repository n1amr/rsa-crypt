cmake_minimum_required(VERSION 3.6)
project(rsa)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DN1AMR -DN1AMR_LOCAL_PC -DN1AMR_MULTIPLE_FILES -DN1AMR_FILE_INPUT -O2 -Wall -Wextra -pedantic")

set(SOURCE_FILES
        src/main/bigint/BigInt.cpp
        src/main/bigint/BigIntHelpers.cpp
        src/main/App.cpp
        src/main/App.h)

add_executable(main ${SOURCE_FILES} src/main/main.cpp)

set(TESTS_SOURCE_FILES
        src/main/bigint/BigInt.cpp
        src/main/bigint/BigIntHelpers.cpp
        src/tests/bigint/bigint_tests.cpp
        src/tests/tests.cpp)

add_executable(tests ${TESTS_SOURCE_FILES} src/tests/main.cpp)
