cmake_minimum_required(VERSION 3.18)
project(mp2-lab4-polinoms)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(include)


add_executable(mp2-lab4-polinoms include/Polinom.h include/Parser.h include/TList.h samples/main.cpp)
add_subdirectory(googletest)