# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/112/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/112/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/zamfirescu/CLionProjects/Tema 2 SD"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/zamfirescu/CLionProjects/Tema 2 SD/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Tema_2_SD.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tema_2_SD.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tema_2_SD.dir/flags.make

CMakeFiles/Tema_2_SD.dir/main.cpp.o: CMakeFiles/Tema_2_SD.dir/flags.make
CMakeFiles/Tema_2_SD.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/zamfirescu/CLionProjects/Tema 2 SD/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tema_2_SD.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tema_2_SD.dir/main.cpp.o -c "/home/zamfirescu/CLionProjects/Tema 2 SD/main.cpp"

CMakeFiles/Tema_2_SD.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tema_2_SD.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/zamfirescu/CLionProjects/Tema 2 SD/main.cpp" > CMakeFiles/Tema_2_SD.dir/main.cpp.i

CMakeFiles/Tema_2_SD.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tema_2_SD.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/zamfirescu/CLionProjects/Tema 2 SD/main.cpp" -o CMakeFiles/Tema_2_SD.dir/main.cpp.s

# Object files for target Tema_2_SD
Tema_2_SD_OBJECTS = \
"CMakeFiles/Tema_2_SD.dir/main.cpp.o"

# External object files for target Tema_2_SD
Tema_2_SD_EXTERNAL_OBJECTS =

Tema_2_SD: CMakeFiles/Tema_2_SD.dir/main.cpp.o
Tema_2_SD: CMakeFiles/Tema_2_SD.dir/build.make
Tema_2_SD: CMakeFiles/Tema_2_SD.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/zamfirescu/CLionProjects/Tema 2 SD/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tema_2_SD"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tema_2_SD.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tema_2_SD.dir/build: Tema_2_SD

.PHONY : CMakeFiles/Tema_2_SD.dir/build

CMakeFiles/Tema_2_SD.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tema_2_SD.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tema_2_SD.dir/clean

CMakeFiles/Tema_2_SD.dir/depend:
	cd "/home/zamfirescu/CLionProjects/Tema 2 SD/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/zamfirescu/CLionProjects/Tema 2 SD" "/home/zamfirescu/CLionProjects/Tema 2 SD" "/home/zamfirescu/CLionProjects/Tema 2 SD/cmake-build-debug" "/home/zamfirescu/CLionProjects/Tema 2 SD/cmake-build-debug" "/home/zamfirescu/CLionProjects/Tema 2 SD/cmake-build-debug/CMakeFiles/Tema_2_SD.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Tema_2_SD.dir/depend

