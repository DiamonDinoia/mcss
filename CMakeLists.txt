cmake_minimum_required(VERSION 3.9)
project(mcss)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(DCMAKE_RULE_MESSAGES OFF)

find_package(OpenMP REQUIRED)
set(LIBRARIES OpenMP::OpenMP_CXX)

if (NOT DEFINED SINGLE)
    set(SINGLE ON)
    add_definitions("-DSINGLE")
endif ()



if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_options(-fstack-protector-all)
    add_compile_options(-Wall -Wextra -pedantic)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Release)
    add_compile_options(-O3 -ffp-contract=fast -ffast-math -freciprocal-math -fmerge-all-constants)
    add_compile_options(-march=native)
endif ()

if (CMAKE_BUILD_TYPE MATCHES DebugOptimized)
    add_compile_options(-g -fno-omit-frame-pointer)
    add_compile_options(-O3 -ffp-contract=fast -ffast-math -freciprocal-math -fmerge-all-constants)
    add_compile_options(-march=native)
endif ()


include_directories(
        "${mcss_SOURCE_DIR}/software-model/include"
        "${mcss_SOURCE_DIR}/common/include"
        "${mcss_SOURCE_DIR}/reference/include"
)

file(GLOB SOURCES
        "${mcss_SOURCE_DIR}/common/src/*.cpp"
        "${mcss_SOURCE_DIR}/reference/src/*.cpp"
        "${mcss_SOURCE_DIR}/software-model/src/*.cpp"
        )

set(INCLUDE_DIRS "")
if (FPGA_BUILD)
    add_definitions(-DFPGA_BUILD)
    add_subdirectory(FPGA)
    include_directories(${INCLUDE_DIRS})
endif ()

if (TESTS)
    add_subdirectory(test)
endif ()


get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()

message(SOURCES = ${SOURCES})
message(LIBRARIES = ${LIBRARIES})

add_executable(mcss mcss.cpp ${SOURCES})
target_link_libraries(mcss PUBLIC ${LIBRARIES})
