cmake_minimum_required(VERSION 3.10)
project(mcss)

set(CMAKE_CXX_STANDARD 11)

if(CMAKE_BUILD_TYPE MATCHES Debug)
#message(STATUS "Build type: ${​​CMAKE_BUILD_TYPE}​​")
add_compile_options(-fstack-protector-all)
add_compile_options(-Wall -Wextra -pedantic)
endif()

if(CMAKE_BUILD_TYPE MATCHES Release)
#message(STATUS "Build type: ${​​CMAKE_BUILD_TYPE}​​")
#add_compile_options(-g -fno-omit-frame-pointer)
add_compile_options(-O3 -ffp-contract=fast -ffast-math -freciprocal-math -fmerge-all-constants)
add_compile_options(-march=native)
endif()

add_executable(mcss include/mcssMultithreaded.h src/mcssMultithreaded.cpp src/common.cpp include/common.h src/mcss.cpp)
add_executable(test test/compareDistributions.cpp src/mcssMultithreaded.cpp include/mcssMultithreaded.h test/ksTest.cpp include/test/ksTest.h src/mcssOriginal.cpp include/mcssOriginal.h src/common.cpp include/common.h include/test/compareDistributions.h test/test.cpp)

find_package(OpenMP REQUIRED)
target_link_libraries(mcss PUBLIC OpenMP::OpenMP_CXX)
target_link_libraries(test PUBLIC OpenMP::OpenMP_CXX)

find_package(Catch2 REQUIRED)
target_link_libraries(test PRIVATE Catch2::Catch2)