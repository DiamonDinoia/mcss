cmake_minimum_required(VERSION 3.9)
project(tests)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/Catch2)

add_definitions(-DTEST=42)

include_directories(include)

add_executable(test_ex test.cpp ksTest.cpp ${SOURCES})
list(APPEND LIBRARIES Catch2::Catch2)
target_link_libraries(test_ex PUBLIC ${LIBRARIES})






# -arch= Needs to be set in accordance with the GPU architecture that the CUDA files will be compiled for.
if (GPU)
	target_compile_options(test_ex PRIVATE $<$<COMPILE_LANGUAGE:CUDA>:-arch=sm_61 -Xcompiler>)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(test_ex PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -fstack-protector-all>)
    target_compile_options(test_ex PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -Wall -Wextra -pedantic>)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(test_ex PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -O3 -ffp-contract=fast -ffast-math -freciprocal-math -fmerge-all-constants>)
    target_compile_options(test_ex PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -march=native>)
endif ()

if (CMAKE_BUILD_TYPE MATCHES DebugOptimized)
    target_compile_options(test_ex PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -g -fno-omit-frame-pointer>)
    target_compile_options(test_ex PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -O3 -ffp-contract=fast -ffast-math -freciprocal-math -fmerge-all-constants>)
    target_compile_options(test_ex PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -march=native>)
endif ()



