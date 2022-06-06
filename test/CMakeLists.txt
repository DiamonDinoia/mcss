cmake_minimum_required(VERSION 3.9)
project(tests)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.9)
FetchContent_MakeAvailable(Catch2)

include(CTest)
enable_testing()

add_definitions(-DTEST=42)

include_directories(include)

add_executable(test_ex test.cpp ksTest.cpp ${SOURCES})
list(APPEND LIBRARIES Catch2::Catch2)
target_link_libraries(test_ex PUBLIC ${LIBRARIES})
