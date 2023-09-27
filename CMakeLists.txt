cmake_minimum_required(VERSION 3.24)
project(mcss LANGUAGES CXX C)

option(SINGLE "enable single precision" ON)
option(USE_SHARED_MEMORY "enable explicit shared memory use" OFF)
option(GPU "enable GPU Acceleration" OFF)
option(FPGA_BUILD "enable FPGA Acceleration" OFF)
option(TESTS "enable tests" OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(DCMAKE_RULE_MESSAGES OFF)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

Include(FetchContent)
include(CheckLanguage)

set(CPM_DOWNLOAD_VERSION 0.38.1)

if (CPM_SOURCE_CACHE)
    set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
elseif (DEFINED ENV{CPM_SOURCE_CACHE})
    set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
else ()
    set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
endif ()
if (NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake to ${CPM_DOWNLOAD_LOCATION}")
    file(DOWNLOAD
            https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
            ${CPM_DOWNLOAD_LOCATION}
    )
endif ()
include(${CPM_DOWNLOAD_LOCATION})


CPMAddPackage(
        NAME Xoshiro
        GIT_REPOSITORY git@github.com:DiamonDinoia/VectorXoshiro.git
        GIT_TAG main
        GIT_SHALLOW YES
        GIT_PROGRESS YES
        EXCLUDE_FROM_ALL YES
        SYSTEM YES
)

CPMAddPackage(
        NAME MixMax
        GIT_REPOSITORY git@github.com:DiamonDinoia/mixmax.git
        GIT_TAG main
        GIT_SHALLOW YES
        GIT_PROGRESS YES
        EXCLUDE_FROM_ALL YES
        SYSTEM YES
)

message(STATUS "DETECTED C++ COMPILER:${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

if ("cxx_std_23" IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    message(STATUS "Using C++23 standard")
    set(CMAKE_CXX_STANDARD 23)
elseif ("cxx_std_20" IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    message(STATUS "Using C++20 standard")
    set(CMAKE_CXX_STANDARD 20)
elseif ("cxx_std_17" IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    set(CMAKE_CXX_STANDARD 17)
    message(STATUS "Detected support for C++17 standard")
elseif ("cxx_std_14" IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    set(CMAKE_CXX_STANDARD 14)
    message(STATUS "Detected support for C++14 standard")
else ()
    message(FATAL_ERROR "Cannot detect CXX_STANDARD of C++14 or newer.")
endif ()

if (GPU)
    check_language(CUDA)
    if (NOT CMAKE_CUDA_COMPILER)
        message(FATAL_ERROR "Requested CUDA support, but no CMAKE_CUDA_COMPILER available")
    endif ()
    enable_language(CUDA)
    if ("cuda_std_23" IN_LIST CMAKE_CUDA_COMPILE_FEATURES)
        set(CMAKE_CUDA_STANDARD 23)
        message(STATUS "Detected support for CUDA23 standard")
    elseif ("cuda_std_20" IN_LIST CMAKE_CUDA_COMPILE_FEATURES)
        set(CMAKE_CUDA_STANDARD 20)
        message(STATUS "Detected support for CUDA20 standard")
    elseif ("cuda_std_17" IN_LIST CMAKE_CUDA_COMPILE_FEATURES)
        set(CMAKE_CUDA_STANDARD 17)
        message(STATUS "Detected support for CUDA17 standard")
    elseif ("cuda_std_14" IN_LIST CMAKE_CUDA_COMPILE_FEATURES)
        set(CMAKE_CUDA_STANDARD 14)
        message(STATUS "Detected support for CUDA14 standard")
    else ()
        message(FATAL_ERROR "Cannot detect CUDA_STANDARD of C++14 or newer.")
    endif ()
    set(CMAKE_CUDA_STANDARD_REQUIRED ON)
endif ()

function(add_compilation_flags variableName)
    set(old_flags ${${variableName}})
    message(STATUS "COMPILATION FLAGS ${old_flags}")
    if (GPU)
        if (NOT "${old_flags}" STREQUAL "")
            string(REPLACE ";" "," CUDA_flags "${old_flags}")
            string(REPLACE "-pedantic" "-Wno-pedantic" CUDA_flags "${CUDA_flags}")
            add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:${old_flags}>$<$<COMPILE_LANGUAGE:CUDA>:-Xcompiler=${CUDA_flags}>")
        endif ()
    else ()
        add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:${old_flags}>")
    endif ()
endfunction()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    set(FLAGS -O0 -fstack-protector-all -Wall -Wextra -pedantic)
    add_compile_options("$<$<COMPILE_LANGUAGE:CUDA>:-G>")
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    set(FLAGS -fcx-limited-range -ffp-contract=fast -freciprocal-math
            -fmerge-all-constants -fno-math-errno -march=native -funroll-loops
            -ftree-vectorize)
elseif (CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
    set(FLAGS -g -fno-omit-frame-pointer -fcx-limited-range
            -ffp-contract=fast -freciprocal-math -fmerge-all-constants
            -fno-math-errno -march=native -funroll-loops -ftree-vectorize)
endif ()

if (SINGLE)
    add_definitions(-DSINGLE)
endif ()
if (USE_SHARED_MEMORY)
    add_definitions(-DUSE_SHARED_MEMORY)
endif ()

if (COUNT_NUMBERS)
    add_definitions(-DCOUNT_NUMBERS)
endif ()

add_compilation_flags(FLAGS)

find_package(OpenMP REQUIRED)
set(LIBRARIES OpenMP::OpenMP_CXX mixmax vectorXoshiro)

include_directories(
        "${mcss_SOURCE_DIR}/software-model/include"
        "${mcss_SOURCE_DIR}/common/include"
        "${mcss_SOURCE_DIR}/reference/include"
)

file(GLOB SOURCES
        "${mcss_SOURCE_DIR}/reference/src/*.cpp"
        "${mcss_SOURCE_DIR}/software-model/src/*.cpp"
        )

if (FPGA_BUILD)
    add_definitions(-DFPGA_BUILD=1)
    include_directories(FPGA/include)

    set(MAXFILES_DIR "FPGA/CPU/max")
    # Directory containing the C/C++ sources
    set(CFILES_DIR "FPGA/CPU/src")
    # Directory containing the C/C++ headers
    set(INCLUDE_DIR "FPGA/CPU/inc")

    include_directories(${INCLUDE_DIR})

    # Recursively find all the files in the specified directories
    file(GLOB_RECURSE MAXFILES ${MAXFILES_DIR}/*.max)
    file(GLOB_RECURSE CFILES ${CFILES_DIR}/*.c*)


    message(STATUS "MAXFILES found ${MAXFILES}")
    message(STATUS "CFILES found ${CFILES}")
    message(STATUS "INCLUDE dirs ${INCLUDE_DIR}")

    # Using slic-config to specify the correct flags and libraries
    FIND_PROGRAM(SLIC_CONFIG slic-config)
    if (SLIC_CONFIG)
        # ---- Get the release name ----
        EXECUTE_PROCESS(COMMAND ${SLIC_CONFIG} --cflags OUTPUT_VARIABLE SLIC_CFLAGS_QUOTED)
        EXECUTE_PROCESS(COMMAND ${SLIC_CONFIG} --libs OUTPUT_VARIABLE SLIC_LDFLAGS_QUOTED)
        # Output of slic-config starts with space -- cmake considers this as error
        string(STRIP "${SLIC_LDFLAGS_QUOTED}" SLIC_LDFLAGS)
        list(APPEND LIBRARIES ${SLIC_LDFLAGS})
        include_directories(
                $ENV{MAXCOMPILERDIR}/include/slic
                $ENV{MAXPOWERDIR}/src/maxpower/kernel/random/runtime
        )
        list(APPEND SOURCES $ENV{MAXPOWERDIR}/src/maxpower/kernel/random/runtime/random_mt.c)
    else ()
        message(FATAL_ERROR "slic config not found")
    endif ()

    # Directory for the compiled maxfiles
    set(MAXOBJS_DIR "max")
    # List of the compiled object files used in the dependency tree
    set(MAXOBJS "")

    # Using sliccompile to compile maxfiles
    FIND_PROGRAM(SLIC_COMPILE sliccompile)
    if (SLIC_COMPILE)
        # Creates a directory for the compiled maxfiles
        file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${MAXOBJS_DIR}")
        # Iterate over each maxfile
        foreach (MAXFILE ${MAXFILES})
            # Generate a name for the compiled maxfiles
            get_filename_component(MAXFILE_NAME ${MAXFILE} NAME)
            string(REPLACE ".max" ".o" MAXOBJ_NAME ${MAXFILE_NAME})
            # Compile the maxfiles
            add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${MAXOBJS_DIR}/${MAXOBJ_NAME}"
                    COMMAND ${SLIC_COMPILE} ${MAXFILE} ${MAXOBJ_NAME}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${MAXOBJS_DIR}
                    DEPENDS ${MAXFILE} COMMENT "compiling maxfile ${MAXFILE}")
            # Add the object to the list
            list(APPEND MAXOBJS "${CMAKE_CURRENT_BINARY_DIR}/${MAXOBJS_DIR}/${MAXOBJ_NAME}")
        endforeach ()
    else ()
        message(FATAL_ERROR "sliccompile not found")
    endif ()
	
    add_custom_target(MAX_OBJS_LIB SOURCES ${MAXOBJS})
    message(STATUS "max objects generated ${MAXOBJS}")
    list(APPEND LIBRARIES ${SLIC_LDFLAGS} ${MAXOBJS})
    list(APPEND SOURCES ${CFILES})
endif ()


if (GPU)
    add_definitions(-DGPU=1)
    set_property(GLOBAL PROPERTY CUDA_ARCHITECTURES native)
    list(APPEND GPU_FLAGS -Wno-deprecated-gpu-targets --default-stream per-thread
            --use_fast_math --extra-device-vectorization --expt-relaxed-constexpr
            --extended-lambda --restrict --ptxas-options=-v)
    add_compile_options("$<$<COMPILE_LANGUAGE:CUDA>:${GPU_FLAGS}>")
    find_package(CUDAToolkit REQUIRED)
    message("CUDA INCLUDE ${CUDA_INCLUDE_DIRS}")
    message(STATUS "CUDA Version: ${CUDAToolkit_VERSION_MAJOR}")
    message(STATUS "CUDA Path: ${CMAKE_CUDA_COMPILER}")
    message(STATUS "CUDA CUDAToolkit include: ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}")
    list(APPEND LIBRARIES CUDA::cudart_static CUDA::curand_static)
    message("GPU LIBRARIES: ${LIBRARIES}")
    include_directories("${mcss_SOURCE_DIR}/GPU/include")
    file(GLOB CUFILES "${mcss_SOURCE_DIR}/GPU/src/*.cu")
    list(APPEND SOURCES ${CUFILES})
endif ()

if (TESTS)
    add_subdirectory(test)
endif ()

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach (dir ${dirs})
    message(STATUS "dir='${dir}'")
endforeach ()

message(SOURCES = ${SOURCES})
message(LIBRARIES = ${LIBRARIES})

add_executable(mcss mcss.cpp ${SOURCES})
target_link_libraries(mcss PUBLIC ${LIBRARIES})
if (FPGA_BUILD)
    add_dependencies(mcss MAX_OBJS_LIB)
    target_compile_definitions(mcss PUBLIC FPGA_BUILD)
endif ()






