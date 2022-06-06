cmake_minimum_required(VERSION 3.9)
project(mcss LANGUAGES CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(DCMAKE_RULE_MESSAGES OFF)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

Include(FetchContent)
include(CheckLanguage)

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
elseif ("cxx_std_11" IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    set(CMAKE_CXX_STANDARD 11)
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
        message(STATUS "Detected support for CUDA20 standard")
    elseif ("cuda_std_20" IN_LIST CMAKE_CUDA_COMPILE_FEATURES)
        set(CMAKE_CUDA_STANDARD 20)
        message(STATUS "Detected support for CUDA20 standard")
    elseif ("cuda_std_17" IN_LIST CMAKE_CUDA_COMPILE_FEATURES)
        set(CMAKE_CUDA_STANDARD 17)
        message(STATUS "Detected support for CUDA17 standard")
    elseif ("cuda_std_14" IN_LIST CMAKE_CUDA_COMPILE_FEATURES)
        set(CMAKE_CUDA_STANDARD 14)
        message(STATUS "Detected support for CUDA14 standard")
    elseif ("cuda_std_11" IN_LIST CMAKE_CUDA_COMPILE_FEATURES)
        set(CMAKE_CUDA_STANDARD 11)
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

add_compilation_flags(FLAGS)

if (NOT DEFINED SINGLE)
    set(SINGLE ON)
    add_definitions("-DSINGLE")
endif ()

if (GPU)
    enable_language(CUDA)
endif ()

find_package(OpenMP REQUIRED)
set(LIBRARIES OpenMP::OpenMP_CXX)


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

if (FPGA_BUILD)
    add_definitions(-DFPGA_BUILD)
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

    message(STATUS "max objects generated ${MAXOBJS}")
    list(APPEND SOURCES ${MAXOBJS} ${CFILES})
    list(APPEND LIBRARIES ${SLIC_LDFLAGS})
endif ()


if (GPU)
    if (${CMAKE_VERSION} VERSION_LESS_EQUAL "3.13.4")
        cuda_select_nvcc_arch_flags(ARCH_FLAGS "Auto") # optional argument for arch to add
        message("ARCH_FLAGS = ${ARCH_FLAGS}")
        string(REPLACE "-gencode;" "--generate-code=" ARCH_FLAGS "${ARCH_FLAGS}")
        string(APPEND CMAKE_CUDA_FLAGS "${ARCH_FLAGS}")
    else ()
        include(FindCUDA/select_compute_arch)
        CUDA_DETECT_INSTALLED_GPUS(INSTALLED_GPU_CCS_1)
        string(STRIP "${INSTALLED_GPU_CCS_1}" INSTALLED_GPU_CCS_2)
        string(REPLACE " " ";" INSTALLED_GPU_CCS_3 "${INSTALLED_GPU_CCS_2}")
        string(REPLACE "." "" CUDA_ARCH_LIST "${INSTALLED_GPU_CCS_3}")
        SET(CMAKE_CUDA_ARCHITECTURES ${CUDA_ARCH_LIST})
        set_property(GLOBAL PROPERTY CUDA_ARCHITECTURES "${CUDA_ARCH_LIST}")
    endif ()
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
    FetchContent_Declare(
            cudawrappers
            GIT_REPOSITORY https://github.com/eyalroz/cuda-api-wrappers.git
            GIT_TAG v0.5.0
            GIT_SHALLOW TRUE
            GIT_PROGRESS TRUE)
    FetchContent_GetProperties(cudawrappers)
    if (NOT CUDAWRAPPERS_POPULATED)
        FetchContent_Populate(cudawrappers)
        add_subdirectory(${cudawrappers_SOURCE_DIR} ${cudawrappers_BINARY_DIR} EXCLUDE_FROM_ALL)
        list(APPEND LIBRARIES runtime-and-driver)
    endif ()
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







