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
include CMakeFiles/utiks.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/utiks.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/utiks.dir/flags.make

CMakeFiles/utiks.dir/main.cpp.o: CMakeFiles/utiks.dir/flags.make
CMakeFiles/utiks.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/utiks.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utiks.dir/main.cpp.o -c /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/main.cpp

CMakeFiles/utiks.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utiks.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/main.cpp > CMakeFiles/utiks.dir/main.cpp.i

CMakeFiles/utiks.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utiks.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/main.cpp -o CMakeFiles/utiks.dir/main.cpp.s

CMakeFiles/utiks.dir/test.cpp.o: CMakeFiles/utiks.dir/flags.make
CMakeFiles/utiks.dir/test.cpp.o: test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/utiks.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utiks.dir/test.cpp.o -c /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/test.cpp

CMakeFiles/utiks.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utiks.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/test.cpp > CMakeFiles/utiks.dir/test.cpp.i

CMakeFiles/utiks.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utiks.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/test.cpp -o CMakeFiles/utiks.dir/test.cpp.s

# Object files for target utiks
utiks_OBJECTS = \
"CMakeFiles/utiks.dir/main.cpp.o" \
"CMakeFiles/utiks.dir/test.cpp.o"

# External object files for target utiks
utiks_EXTERNAL_OBJECTS =

libutiks.a: CMakeFiles/utiks.dir/main.cpp.o
libutiks.a: CMakeFiles/utiks.dir/test.cpp.o
libutiks.a: CMakeFiles/utiks.dir/build.make
libutiks.a: CMakeFiles/utiks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libutiks.a"
	$(CMAKE_COMMAND) -P CMakeFiles/utiks.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utiks.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/utiks.dir/build: libutiks.a

.PHONY : CMakeFiles/utiks.dir/build

CMakeFiles/utiks.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/utiks.dir/cmake_clean.cmake
.PHONY : CMakeFiles/utiks.dir/clean

CMakeFiles/utiks.dir/depend:
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake /home/khamza/repos/oop_2019_g2_khamzat_sultanov/01_cmake/CMakeFiles/utiks.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/utiks.dir/depend

