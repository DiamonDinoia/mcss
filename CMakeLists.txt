cmake_minimum_required(VERSION 3.9)
project(mcss)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(DCMAKE_RULE_MESSAGES OFF)


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
	
	include_directories("${mcss_SOURCE_DIR}/GPU/include")
	file(GLOB CUFILES "${mcss_SOURCE_DIR}/GPU/src/*.cu")
	list(APPEND SOURCES ${CUFILES})

	add_definitions(-DGPU)
		
    find_package(CUDA REQUIRED)
	
    CUDA_SELECT_NVCC_ARCH_FLAGS(CUDA_ARCHS 3.5 5.0 5.2 5.3 6.0 6.2 7.0 7.5)
	
    include_directories(${CUDA_INCLUDE_DIRS})
    list(APPEND LIBRARIES ${CUDA_LIBRARIES})

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




# -arch= Needs to be set in accordance with the GPU architecture that the CUDA files will be compiled for.
if (GPU)
	target_compile_options(mcss PRIVATE $<$<COMPILE_LANGUAGE:CUDA>:-arch=sm_61 -Xcompiler>)
endif ()



if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(mcss PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -fstack-protector-all>)
    target_compile_options(mcss PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -Wall -Wextra -pedantic>)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(mcss PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -O3 -ffp-contract=fast -ffast-math -freciprocal-math -fmerge-all-constants>)
    target_compile_options(mcss PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -march=native>)
endif ()

if (CMAKE_BUILD_TYPE MATCHES DebugOptimized)
    target_compile_options(mcss PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -g -fno-omit-frame-pointer>)
    target_compile_options(mcss PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -O3 -ffp-contract=fast -ffast-math -freciprocal-math -fmerge-all-constants>)
    target_compile_options(mcss PRIVATE $<$<COMPILE_LANGUAGE:CXX>: -march=native>)
endif ()









