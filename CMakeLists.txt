cmake_minimum_required(VERSION 3.9)
project(mcss)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenMP REQUIRED)

if (NOT DEFINED SINGLE)
    set(SINGLE ON)
    add_definitions("-DSINGLE")
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_options(-fstack-protector-all)
    add_compile_options(-Wall -Wextra -pedantic)
    add_subdirectory(test)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Release)
    add_compile_options(-O3 -ffp-contract=fast -ffast-math -freciprocal-math -fmerge-all-constants)
    add_compile_options(-march=native)
    add_subdirectory(test)
endif ()

if (CMAKE_BUILD_TYPE MATCHES DebugOptimized)
    add_compile_options(-g -fno-omit-frame-pointer)
    add_compile_options(-O3 -ffp-contract=fast -ffast-math -freciprocal-math -fmerge-all-constants)
    add_compile_options(-march=native)
    add_subdirectory(test)
endif ()

set(MAXFILES_DIR "MCSScpu/max")
# Directory containing the C/C++ sources
set(CFILES_DIR "MCSScpu/src")
# Directory containing the C/C++ headers
set(INCLUDE_DIR "${mcss_SOURCE_DIR}/MCSSCPU/inc")
 
# Recursively find all the files in the specified directories
file(GLOB_RECURSE MAXFILES ${MAXFILES_DIR}/*.max)
file(GLOB_RECURSE CFILES ${CFILES_DIR}/*.c*)
 
 
message(STATUS "MAXFILES found ${MAXFILES}")
message(STATUS "CFILES found ${CFILES}")
message(STATUS "INCLUDE dirs ${INCLUDE_DIR}")

include_directories(include)
include_directories("${INCLUDE_DIR}")
include_directories("${mcss_SOURCE_DIR}/*")
include_directories("${mcss_SOURCE_DIR}/MCSScpu/inc")
include_directories("${mcss_SOURCE_DIR}/MCSScpu/inc/max")
 
 
# Using slic-config to specify the correct flags and libraries
FIND_PROGRAM(SLIC_CONFIG slic-config)
if(SLIC_CONFIG)
        # ---- Get the release name ----
        EXECUTE_PROCESS(COMMAND ${SLIC_CONFIG} --cflags OUTPUT_VARIABLE SLIC_CFLAGS_QUOTED)
        EXECUTE_PROCESS(COMMAND ${SLIC_CONFIG} --libs   OUTPUT_VARIABLE SLIC_LDFLAGS_QUOTED)
	# Output of slic-config starts with space -- cmake considers this as error
	string(STRIP "${SLIC_LDFLAGS_QUOTED}" SLIC_LDFLAGS)
	include_directories($ENV{MAXCOMPILERDIR}/include/slic)
	include_directories($ENV{MAXCOMPILERDIR}/include/slic_maxeler)
	include_directories($ENV{MAXCOMPILERDIR}/src/slicinterface/)
else()
	message(FATAL_ERROR "slic config not found")
endif()
 
# Directory for the compiled maxfiles
set(MAXOBJS_DIR "/MCSScpu/max")
# List of the compiled object files used in the dependency tree 
set(MAXOBJS "MCSScpu/")
 
# Using sliccompile to compile maxfiles
FIND_PROGRAM(SLIC_COMPILE sliccompile)
if(SLIC_COMPILE)
	# Creates a directory for the compiled maxfiles
	file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${MAXOBJS_DIR}")
	# Iterate over each maxfile
	foreach(MAXFILE ${MAXFILES})
		# Generate a name for the compiled maxfiles 
		get_filename_component(MAXFILE_NAME ${MAXFILE} NAME)
		string(REPLACE ".max" ".o" MAXOBJ_NAME ${MAXFILE_NAME})
		# Compile the maxfiles
		add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${MAXOBJS_DIR}/${MAXOBJ_NAME}" 
			COMMAND ${SLIC_COMPILE} ${MAXFILE} ${MAXOBJ_NAME}
			WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${MAXOBJS_DIR}
			DEPENDS ${MAXFILE} COMMENT "compiling maxfile ${MAXFILE}")
		# Add the object to the list	
		set(MAXOBJS "${CMAKE_CURRENT_BINARY_DIR}/${MAXOBJS_DIR}/${MAXOBJ_NAME};${MAXOBJS}")
	endforeach()
else()
	message(FATAL_ERROR "sliccompile not found")
endif()
 
message(STATUS "max objects generated ${MAXOBJS}")

#file(GLOB SOURCES "${tests_SOURCE_DIR}/*" "${tests_SOURCE_DIR}/../src/*" "${tests_SOURCE_DIR}/../MCSScpu/src/*")


file(GLOB SOURCES "${mcss_SOURCE_DIR}/src/*")
message(SOURCES = ${SOURCES})

add_executable(mcss ${SOURCES} mcss.cpp)
target_link_libraries(mcss PUBLIC OpenMP::OpenMP_CXX)

add_executable(plot ${SOURCES} ${CFILES} ${MAXOBJS} util/c++/plot.cpp)
target_link_libraries(plot PUBLIC OpenMP::OpenMP_CXX ${SLIC_LDFLAGS})
