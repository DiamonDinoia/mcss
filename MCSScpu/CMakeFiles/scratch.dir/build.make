# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /mnt/ccnas2/tdp/dc3117/cmake/cmake-3.12.3/bin/cmake

# The command to remove a file.
RM = /mnt/ccnas2/tdp/dc3117/cmake/cmake-3.12.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/ccnas2/tdp/dc3117/max/rng-cpu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/ccnas2/tdp/dc3117/max/rng-cpu

# Include any dependencies generated for this target.
include CMakeFiles/scratch.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/scratch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scratch.dir/flags.make

max/rng.o: max/rng.max
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/ccnas2/tdp/dc3117/max/rng-cpu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "compiling maxfile /mnt/ccnas2/tdp/dc3117/max/rng-cpu/max/rng.max"
	cd /mnt/ccnas2/tdp/dc3117/max/rng-cpu/max && /vol/cc/opt/maxeler/maxcompiler-2020.2/bin/sliccompile /mnt/ccnas2/tdp/dc3117/max/rng-cpu/max/rng.max rng.o

CMakeFiles/scratch.dir/src/random_mt.c.o: CMakeFiles/scratch.dir/flags.make
CMakeFiles/scratch.dir/src/random_mt.c.o: src/random_mt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/ccnas2/tdp/dc3117/max/rng-cpu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/scratch.dir/src/random_mt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/scratch.dir/src/random_mt.c.o   -c /mnt/ccnas2/tdp/dc3117/max/rng-cpu/src/random_mt.c

CMakeFiles/scratch.dir/src/random_mt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/scratch.dir/src/random_mt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/ccnas2/tdp/dc3117/max/rng-cpu/src/random_mt.c > CMakeFiles/scratch.dir/src/random_mt.c.i

CMakeFiles/scratch.dir/src/random_mt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/scratch.dir/src/random_mt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/ccnas2/tdp/dc3117/max/rng-cpu/src/random_mt.c -o CMakeFiles/scratch.dir/src/random_mt.c.s

CMakeFiles/scratch.dir/src/rng-cpu.c.o: CMakeFiles/scratch.dir/flags.make
CMakeFiles/scratch.dir/src/rng-cpu.c.o: src/rng-cpu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/ccnas2/tdp/dc3117/max/rng-cpu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/scratch.dir/src/rng-cpu.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/scratch.dir/src/rng-cpu.c.o   -c /mnt/ccnas2/tdp/dc3117/max/rng-cpu/src/rng-cpu.c

CMakeFiles/scratch.dir/src/rng-cpu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/scratch.dir/src/rng-cpu.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/ccnas2/tdp/dc3117/max/rng-cpu/src/rng-cpu.c > CMakeFiles/scratch.dir/src/rng-cpu.c.i

CMakeFiles/scratch.dir/src/rng-cpu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/scratch.dir/src/rng-cpu.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/ccnas2/tdp/dc3117/max/rng-cpu/src/rng-cpu.c -o CMakeFiles/scratch.dir/src/rng-cpu.c.s

# Object files for target scratch
scratch_OBJECTS = \
"CMakeFiles/scratch.dir/src/random_mt.c.o" \
"CMakeFiles/scratch.dir/src/rng-cpu.c.o"

# External object files for target scratch
scratch_EXTERNAL_OBJECTS = \
"/mnt/ccnas2/tdp/dc3117/max/rng-cpu/max/rng.o"

scratch: CMakeFiles/scratch.dir/src/random_mt.c.o
scratch: CMakeFiles/scratch.dir/src/rng-cpu.c.o
scratch: max/rng.o
scratch: CMakeFiles/scratch.dir/build.make
scratch: CMakeFiles/scratch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/ccnas2/tdp/dc3117/max/rng-cpu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable scratch"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scratch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scratch.dir/build: scratch

.PHONY : CMakeFiles/scratch.dir/build

CMakeFiles/scratch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/scratch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/scratch.dir/clean

CMakeFiles/scratch.dir/depend: max/rng.o
	cd /mnt/ccnas2/tdp/dc3117/max/rng-cpu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/ccnas2/tdp/dc3117/max/rng-cpu /mnt/ccnas2/tdp/dc3117/max/rng-cpu /mnt/ccnas2/tdp/dc3117/max/rng-cpu /mnt/ccnas2/tdp/dc3117/max/rng-cpu /mnt/ccnas2/tdp/dc3117/max/rng-cpu/CMakeFiles/scratch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/scratch.dir/depend
