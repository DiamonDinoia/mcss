project(mcssFPGA)

# Using slic-config to specify the correct flags and libraries
FIND_PROGRAM(SLIC_CONFIG slic-config)

set(MAXFILES_DIR "CPU/max")
# Directory containing the C/C++ sources
set(CFILES_DIR "CPU/src")
# Directory containing the C/C++ headers
set(INCLUDE_DIR "CPU/inc")

set(INCLUDE_DIRS "${INCLUDE_DIR};include;$ENV{MAXPOWERDIR}/src/maxpower/kernel/random/runtime" PARENT_SCOPE)
include_directories(
        ${INCLUDE_DIR}
        include
        $ENV{MAXPOWERDIR}/src/maxpower/kernel/random/runtime
)

# Recursively find all the files in the specified directories
file(GLOB_RECURSE MAXFILES ${MAXFILES_DIR}/*.max)
file(GLOB_RECURSE CFILES ${CFILES_DIR}/*.c*)


message(STATUS "MAXFILES found ${MAXFILES}")
message(STATUS "CFILES found ${CFILES}")
message(STATUS "INCLUDE dirs ${INCLUDE_DIR}")


if (SLIC_CONFIG)
    # ---- Get the release name ----
    EXECUTE_PROCESS(COMMAND ${SLIC_CONFIG} --cflags OUTPUT_VARIABLE SLIC_CFLAGS_QUOTED)
    EXECUTE_PROCESS(COMMAND ${SLIC_CONFIG} --libs OUTPUT_VARIABLE SLIC_LDFLAGS_QUOTED)
    # Output of slic-config starts with space -- cmake considers this as error
    string(STRIP "${SLIC_LDFLAGS_QUOTED}" SLIC_LDFLAGS)
    include_directories($ENV{MAXCOMPILERDIR}/include/slic)
else ()
    message(FATAL_ERROR "slic config not found")
endif ()

# Directory for the compiled maxfiles
set(MAXOBJS_DIR "CPU/max")
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
        set(MAXOBJS "${CMAKE_CURRENT_BINARY_DIR}/${MAXOBJS_DIR}/${MAXOBJ_NAME};${MAXOBJS}")
    endforeach ()
else ()
    message(FATAL_ERROR "sliccompile not found")
endif ()

message(STATUS "max objects generated ${MAXOBJS}")

add_library(maxpower STATIC IMPORTED)
set_target_properties(
        maxpower
        PROPERTIES IMPORTED_LOCATION
        "$ENV{MAXPOWERDIR}/lib/libmaxpower.a")

set(SOURCES "${SOURCES};${MAXOBJS};${CFILES}" PARENT_SCOPE)
set(LIBRARIES "${LIBRARIES};${SLIC_LDFLAGS};maxpower" PARENT_SCOPE)
#list(APPEND SOURCES ${MAXOBJS} ${CFILES})

#message(SOURCES = ${SOURCES})
