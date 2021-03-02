cmake_minimum_required(VERSION 3.10)
project(mcss)

set(CMAKE_CXX_STANDARD 11)

if (CMAKE_BUILD_TYPE MATCHES Debug)
#message(STATUS "Build type: ${​​CMAKE_BUILD_TYPE}​​")
add_compile_options(-fstack-protector-all)
add_compile_options(-Wall -Wextra -pedantic)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Release)
#message(STATUS "Build type: ${​​CMAKE_BUILD_TYPE}​​")
add_compile_options(-g -fno-omit-frame-pointer)
add_compile_options(-O3 -ffp-contract=fast -ffast-math -freciprocal-math -fmerge-all-constants)
add_compile_options(-march=native)
endif ()

add_executable(mcss
mcss.cc
Readme.txt)