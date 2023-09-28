# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/corey/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/corey/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/corey/uumotor-servo-motor-driver-ros2/src/serial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/serial-test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/serial-test.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/serial-test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/serial-test.dir/flags.make

tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o: tests/CMakeFiles/serial-test.dir/flags.make
tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o: /home/corey/uumotor-servo-motor-driver-ros2/src/serial/tests/unix_serial_tests.cc
tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o: tests/CMakeFiles/serial-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/corey/uumotor-servo-motor-driver-ros2/src/serial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o"
	cd /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o -MF CMakeFiles/serial-test.dir/unix_serial_tests.cc.o.d -o CMakeFiles/serial-test.dir/unix_serial_tests.cc.o -c /home/corey/uumotor-servo-motor-driver-ros2/src/serial/tests/unix_serial_tests.cc

tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/serial-test.dir/unix_serial_tests.cc.i"
	cd /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/corey/uumotor-servo-motor-driver-ros2/src/serial/tests/unix_serial_tests.cc > CMakeFiles/serial-test.dir/unix_serial_tests.cc.i

tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/serial-test.dir/unix_serial_tests.cc.s"
	cd /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/corey/uumotor-servo-motor-driver-ros2/src/serial/tests/unix_serial_tests.cc -o CMakeFiles/serial-test.dir/unix_serial_tests.cc.s

# Object files for target serial-test
serial__test_OBJECTS = \
"CMakeFiles/serial-test.dir/unix_serial_tests.cc.o"

# External object files for target serial-test
serial__test_EXTERNAL_OBJECTS =

tests/serial-test: tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o
tests/serial-test: tests/CMakeFiles/serial-test.dir/build.make
tests/serial-test: gtest/libgtest_main.a
tests/serial-test: gtest/libgtest.a
tests/serial-test: libserial.a
tests/serial-test: tests/CMakeFiles/serial-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/corey/uumotor-servo-motor-driver-ros2/src/serial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable serial-test"
	cd /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/serial-test.dir/build: tests/serial-test
.PHONY : tests/CMakeFiles/serial-test.dir/build

tests/CMakeFiles/serial-test.dir/clean:
	cd /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/serial-test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/serial-test.dir/clean

tests/CMakeFiles/serial-test.dir/depend:
	cd /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/corey/uumotor-servo-motor-driver-ros2/src/serial /home/corey/uumotor-servo-motor-driver-ros2/src/serial/tests /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build/tests /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build/tests/CMakeFiles/serial-test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/serial-test.dir/depend

