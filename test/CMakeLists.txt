cmake_minimum_required(VERSION 3.9)
project(tests)

add_definitions(-DTEST=42)

include_directories(include)
include_directories("${tests_SOURCE_DIR}/../include")

file(GLOB SOURCES "${tests_SOURCE_DIR}/*" "${tests_SOURCE_DIR}/../src/*")
message(TEST SOURCES = ${SOURCES})

add_executable(test ${SOURCES})

find_package(OpenMP REQUIRED)
target_link_libraries(test PUBLIC OpenMP::OpenMP_CXX)
