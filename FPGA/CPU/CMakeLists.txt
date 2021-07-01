cmake_minimum_required(VERSION 3.9.4)
 
project(mcss)
 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(DCMAKE_RULE_MESSAGES OFF)
 
# Setting Some compilation flags
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
 
add_compile_options(-Wall -Wextra -pedantic)
 
if (CMAKE_BUILD_TYPE MATCHES Debug)
	message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")	
endif ()
if (CMAKE_BUILD_TYPE MATCHES Release)
	message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
	add_compile_options(-ffp-contract=fast -ffast-math -freciprocal-math -fmerge-all-constants)
	add_compile_options(-march=native)
	set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
endif ()
 
set(MAXFILES_DIR "max")
# Directory containing the C/C++ sources
set(CFILES_DIR "src")
# Directory containing the C/C++ headers
set(INCLUDE_DIR "inc")
 
include_directories("inc")
include_directories("inc/max")
 
# Recursively find all the files in the specified directories
file(GLOB_RECURSE MAXFILES ${MAXFILES_DIR}/*.max)
file(GLOB_RECURSE CFILES ${CFILES_DIR}/*.c* mcss.cpp)
 
 
message(STATUS "MAXFILES found ${MAXFILES}")
message(STATUS "CFILES found ${CFILES}")
message(STATUS "INCLUDE dirs ${INCLUDE_DIR}")
 
 
# Using slic-config to specify the correct flags and libraries
FIND_PROGRAM(SLIC_CONFIG slic-config)
if(SLIC_CONFIG)
        # ---- Get the release name ----
        EXECUTE_PROCESS(COMMAND ${SLIC_CONFIG} --cflags OUTPUT_VARIABLE SLIC_CFLAGS_QUOTED)
        EXECUTE_PROCESS(COMMAND ${SLIC_CONFIG} --libs   OUTPUT_VARIABLE SLIC_LDFLAGS_QUOTED)
		# Output of slic-config starts with space -- cmake considers this as error
		string(STRIP "${SLIC_LDFLAGS_QUOTED}" SLIC_LDFLAGS)
		include_directories($ENV{MAXCOMPILERDIR}/include/slic)	
else()
	message(FATAL_ERROR "slic config not found")
endif()
 
# Directory for the compiled maxfiles
set(MAXOBJS_DIR "max")
# List of the compiled object files used in the dependency tree 
set(MAXOBJS "")
 
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
 
# Link sources headers and maxfiles together
add_executable(mcss ${CFILES} ${MAXOBJS})
# Link slic libraries
target_link_libraries(mcss ${SLIC_LDFLAGS})