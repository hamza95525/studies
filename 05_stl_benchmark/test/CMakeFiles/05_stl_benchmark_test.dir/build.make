# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark

# Include any dependencies generated for this target.
include test/CMakeFiles/05_stl_benchmark_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/05_stl_benchmark_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/05_stl_benchmark_test.dir/flags.make

test/CMakeFiles/05_stl_benchmark_test.dir/src/DummyTest.cpp.o: test/CMakeFiles/05_stl_benchmark_test.dir/flags.make
test/CMakeFiles/05_stl_benchmark_test.dir/src/DummyTest.cpp.o: test/src/DummyTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/05_stl_benchmark_test.dir/src/DummyTest.cpp.o"
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/05_stl_benchmark_test.dir/src/DummyTest.cpp.o -c /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test/src/DummyTest.cpp

test/CMakeFiles/05_stl_benchmark_test.dir/src/DummyTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/05_stl_benchmark_test.dir/src/DummyTest.cpp.i"
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test/src/DummyTest.cpp > CMakeFiles/05_stl_benchmark_test.dir/src/DummyTest.cpp.i

test/CMakeFiles/05_stl_benchmark_test.dir/src/DummyTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/05_stl_benchmark_test.dir/src/DummyTest.cpp.s"
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test/src/DummyTest.cpp -o CMakeFiles/05_stl_benchmark_test.dir/src/DummyTest.cpp.s

test/CMakeFiles/05_stl_benchmark_test.dir/src/SmallTest.cpp.o: test/CMakeFiles/05_stl_benchmark_test.dir/flags.make
test/CMakeFiles/05_stl_benchmark_test.dir/src/SmallTest.cpp.o: test/src/SmallTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/05_stl_benchmark_test.dir/src/SmallTest.cpp.o"
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/05_stl_benchmark_test.dir/src/SmallTest.cpp.o -c /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test/src/SmallTest.cpp

test/CMakeFiles/05_stl_benchmark_test.dir/src/SmallTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/05_stl_benchmark_test.dir/src/SmallTest.cpp.i"
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test/src/SmallTest.cpp > CMakeFiles/05_stl_benchmark_test.dir/src/SmallTest.cpp.i

test/CMakeFiles/05_stl_benchmark_test.dir/src/SmallTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/05_stl_benchmark_test.dir/src/SmallTest.cpp.s"
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test/src/SmallTest.cpp -o CMakeFiles/05_stl_benchmark_test.dir/src/SmallTest.cpp.s

test/CMakeFiles/05_stl_benchmark_test.dir/src/MediumTest.cpp.o: test/CMakeFiles/05_stl_benchmark_test.dir/flags.make
test/CMakeFiles/05_stl_benchmark_test.dir/src/MediumTest.cpp.o: test/src/MediumTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/05_stl_benchmark_test.dir/src/MediumTest.cpp.o"
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/05_stl_benchmark_test.dir/src/MediumTest.cpp.o -c /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test/src/MediumTest.cpp

test/CMakeFiles/05_stl_benchmark_test.dir/src/MediumTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/05_stl_benchmark_test.dir/src/MediumTest.cpp.i"
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test/src/MediumTest.cpp > CMakeFiles/05_stl_benchmark_test.dir/src/MediumTest.cpp.i

test/CMakeFiles/05_stl_benchmark_test.dir/src/MediumTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/05_stl_benchmark_test.dir/src/MediumTest.cpp.s"
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test/src/MediumTest.cpp -o CMakeFiles/05_stl_benchmark_test.dir/src/MediumTest.cpp.s

test/CMakeFiles/05_stl_benchmark_test.dir/src/LargeTest.cpp.o: test/CMakeFiles/05_stl_benchmark_test.dir/flags.make
test/CMakeFiles/05_stl_benchmark_test.dir/src/LargeTest.cpp.o: test/src/LargeTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/CMakeFiles/05_stl_benchmark_test.dir/src/LargeTest.cpp.o"
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/05_stl_benchmark_test.dir/src/LargeTest.cpp.o -c /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test/src/LargeTest.cpp

test/CMakeFiles/05_stl_benchmark_test.dir/src/LargeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/05_stl_benchmark_test.dir/src/LargeTest.cpp.i"
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test/src/LargeTest.cpp > CMakeFiles/05_stl_benchmark_test.dir/src/LargeTest.cpp.i

test/CMakeFiles/05_stl_benchmark_test.dir/src/LargeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/05_stl_benchmark_test.dir/src/LargeTest.cpp.s"
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test/src/LargeTest.cpp -o CMakeFiles/05_stl_benchmark_test.dir/src/LargeTest.cpp.s

# Object files for target 05_stl_benchmark_test
05_stl_benchmark_test_OBJECTS = \
"CMakeFiles/05_stl_benchmark_test.dir/src/DummyTest.cpp.o" \
"CMakeFiles/05_stl_benchmark_test.dir/src/SmallTest.cpp.o" \
"CMakeFiles/05_stl_benchmark_test.dir/src/MediumTest.cpp.o" \
"CMakeFiles/05_stl_benchmark_test.dir/src/LargeTest.cpp.o"

# External object files for target 05_stl_benchmark_test
05_stl_benchmark_test_EXTERNAL_OBJECTS =

test/05_stl_benchmark_test: test/CMakeFiles/05_stl_benchmark_test.dir/src/DummyTest.cpp.o
test/05_stl_benchmark_test: test/CMakeFiles/05_stl_benchmark_test.dir/src/SmallTest.cpp.o
test/05_stl_benchmark_test: test/CMakeFiles/05_stl_benchmark_test.dir/src/MediumTest.cpp.o
test/05_stl_benchmark_test: test/CMakeFiles/05_stl_benchmark_test.dir/src/LargeTest.cpp.o
test/05_stl_benchmark_test: test/CMakeFiles/05_stl_benchmark_test.dir/build.make
test/05_stl_benchmark_test: lib05_stl_benchmark_lib.a
test/05_stl_benchmark_test: lib/libgtest.a
test/05_stl_benchmark_test: lib/libgtest_main.a
test/05_stl_benchmark_test: lib/libgtest.a
test/05_stl_benchmark_test: test/CMakeFiles/05_stl_benchmark_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable 05_stl_benchmark_test"
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/05_stl_benchmark_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/05_stl_benchmark_test.dir/build: test/05_stl_benchmark_test

.PHONY : test/CMakeFiles/05_stl_benchmark_test.dir/build

test/CMakeFiles/05_stl_benchmark_test.dir/clean:
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test && $(CMAKE_COMMAND) -P CMakeFiles/05_stl_benchmark_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/05_stl_benchmark_test.dir/clean

test/CMakeFiles/05_stl_benchmark_test.dir/depend:
	cd /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test /home/khamza/repos/oop_2019_g2_khamzat_sultanov/05_stl_benchmark/test/CMakeFiles/05_stl_benchmark_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/05_stl_benchmark_test.dir/depend

