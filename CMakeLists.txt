cmake_minimum_required(VERSION 3.10)
project(mcss)

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
set(CMAKE_CXX_FLAGS "-fopenmp")

#if (CMAKE_BUILD_TYPE MATCHES Debug)
##message(STATUS "Build type: ${​​CMAKE_BUILD_TYPE}​​")
#add_compile_options(-fstack-protector-all)
#add_compile_options(-Wall -Wextra -pedantic)
#endif ()

if (CMAKE_BUILD_TYPE MATCHES Release)
#message(STATUS "Build type: ${​​CMAKE_BUILD_TYPE}​​")
#add_compile_options(-g -fno-omit-frame-pointer)
add_compile_options(-O3 -fopenmp -ffp-contract=fast -ffast-math -freciprocal-math -fmerge-all-constants)
add_compile_options(-march=native)
endif ()

add_executable(mcss mcss.cpp MultithreadedMCSS.h MultithreadedMCSS.cpp)
add_executable(mcssOriginal mcssOriginal.cpp)
add_executable(comparison CompareDistributions.cpp MultithreadedMCSS.cpp MultithreadedMCSS.h Utils/ks-test.cpp Utils/ks-test.h Utils/Utils.cpp Utils/Utils.h)