# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /snap/clion/107/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/107/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lewskiy_/Projects/C/JiPP/Lab6/Lab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lewskiy_/Projects/C/JiPP/Lab6/Lab/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab.dir/flags.make

CMakeFiles/Lab.dir/main.c.o: CMakeFiles/Lab.dir/flags.make
CMakeFiles/Lab.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewskiy_/Projects/C/JiPP/Lab6/Lab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lab.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lab.dir/main.c.o   -c /home/lewskiy_/Projects/C/JiPP/Lab6/Lab/main.c

CMakeFiles/Lab.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lewskiy_/Projects/C/JiPP/Lab6/Lab/main.c > CMakeFiles/Lab.dir/main.c.i

CMakeFiles/Lab.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lewskiy_/Projects/C/JiPP/Lab6/Lab/main.c -o CMakeFiles/Lab.dir/main.c.s

# Object files for target Lab
Lab_OBJECTS = \
"CMakeFiles/Lab.dir/main.c.o"

# External object files for target Lab
Lab_EXTERNAL_OBJECTS =

Lab: CMakeFiles/Lab.dir/main.c.o
Lab: CMakeFiles/Lab.dir/build.make
Lab: CMakeFiles/Lab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewskiy_/Projects/C/JiPP/Lab6/Lab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Lab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab.dir/build: Lab

.PHONY : CMakeFiles/Lab.dir/build

CMakeFiles/Lab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab.dir/clean

CMakeFiles/Lab.dir/depend:
	cd /home/lewskiy_/Projects/C/JiPP/Lab6/Lab/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewskiy_/Projects/C/JiPP/Lab6/Lab /home/lewskiy_/Projects/C/JiPP/Lab6/Lab /home/lewskiy_/Projects/C/JiPP/Lab6/Lab/cmake-build-debug /home/lewskiy_/Projects/C/JiPP/Lab6/Lab/cmake-build-debug /home/lewskiy_/Projects/C/JiPP/Lab6/Lab/cmake-build-debug/CMakeFiles/Lab.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab.dir/depend
