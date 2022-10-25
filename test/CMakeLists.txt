cmake_minimum_required(VERSION 3.9)
project(tests)

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

add_test(NAME all_tests COMMAND  $<TARGET_FILE:test_ex>)