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
CMAKE_COMMAND = /snap/clion/98/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/98/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake

# Include any dependencies generated for this target.
include CMakeFiles/01_cmake.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/01_cmake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/01_cmake.dir/flags.make

CMakeFiles/01_cmake.dir/main.cpp.o: CMakeFiles/01_cmake.dir/flags.make
CMakeFiles/01_cmake.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/01_cmake.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/01_cmake.dir/main.cpp.o -c /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/main.cpp

CMakeFiles/01_cmake.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/01_cmake.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/main.cpp > CMakeFiles/01_cmake.dir/main.cpp.i

CMakeFiles/01_cmake.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/01_cmake.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/main.cpp -o CMakeFiles/01_cmake.dir/main.cpp.s

# Object files for target 01_cmake
01_cmake_OBJECTS = \
"CMakeFiles/01_cmake.dir/main.cpp.o"

# External object files for target 01_cmake
01_cmake_EXTERNAL_OBJECTS =

01_cmake: CMakeFiles/01_cmake.dir/main.cpp.o
01_cmake: CMakeFiles/01_cmake.dir/build.make
01_cmake: libutiks.a
01_cmake: CMakeFiles/01_cmake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 01_cmake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/01_cmake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/01_cmake.dir/build: 01_cmake

.PHONY : CMakeFiles/01_cmake.dir/build

CMakeFiles/01_cmake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/01_cmake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/01_cmake.dir/clean

CMakeFiles/01_cmake.dir/depend:
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/CMakeFiles/01_cmake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/01_cmake.dir/depend

