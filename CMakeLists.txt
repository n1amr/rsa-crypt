cmake_minimum_required(VERSION 3.6)
project(rsa)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DLOCAL_PC -DN1AMR -DN1AMR_f220929df")

set(SOURCE_FILES main.cpp BigInt.cpp DecimalStringHelpers.cpp tests.cpp tests.h)
add_executable(rsa ${SOURCE_FILES})




