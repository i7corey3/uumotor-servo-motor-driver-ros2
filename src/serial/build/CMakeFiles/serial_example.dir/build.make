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
include CMakeFiles/serial_example.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/serial_example.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/serial_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serial_example.dir/flags.make

CMakeFiles/serial_example.dir/examples/serial_example.cc.o: CMakeFiles/serial_example.dir/flags.make
CMakeFiles/serial_example.dir/examples/serial_example.cc.o: /home/corey/uumotor-servo-motor-driver-ros2/src/serial/examples/serial_example.cc
CMakeFiles/serial_example.dir/examples/serial_example.cc.o: CMakeFiles/serial_example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/corey/uumotor-servo-motor-driver-ros2/src/serial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/serial_example.dir/examples/serial_example.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serial_example.dir/examples/serial_example.cc.o -MF CMakeFiles/serial_example.dir/examples/serial_example.cc.o.d -o CMakeFiles/serial_example.dir/examples/serial_example.cc.o -c /home/corey/uumotor-servo-motor-driver-ros2/src/serial/examples/serial_example.cc

CMakeFiles/serial_example.dir/examples/serial_example.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/serial_example.dir/examples/serial_example.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/corey/uumotor-servo-motor-driver-ros2/src/serial/examples/serial_example.cc > CMakeFiles/serial_example.dir/examples/serial_example.cc.i

CMakeFiles/serial_example.dir/examples/serial_example.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/serial_example.dir/examples/serial_example.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/corey/uumotor-servo-motor-driver-ros2/src/serial/examples/serial_example.cc -o CMakeFiles/serial_example.dir/examples/serial_example.cc.s

# Object files for target serial_example
serial_example_OBJECTS = \
"CMakeFiles/serial_example.dir/examples/serial_example.cc.o"

# External object files for target serial_example
serial_example_EXTERNAL_OBJECTS =

serial_example: CMakeFiles/serial_example.dir/examples/serial_example.cc.o
serial_example: CMakeFiles/serial_example.dir/build.make
serial_example: libserial.a
serial_example: CMakeFiles/serial_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/corey/uumotor-servo-motor-driver-ros2/src/serial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable serial_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serial_example.dir/build: serial_example
.PHONY : CMakeFiles/serial_example.dir/build

CMakeFiles/serial_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serial_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serial_example.dir/clean

CMakeFiles/serial_example.dir/depend:
	cd /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/corey/uumotor-servo-motor-driver-ros2/src/serial /home/corey/uumotor-servo-motor-driver-ros2/src/serial /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build /home/corey/uumotor-servo-motor-driver-ros2/src/serial/build/CMakeFiles/serial_example.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/serial_example.dir/depend

