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
CMAKE_SOURCE_DIR = /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver

# Include any dependencies generated for this target.
include CMakeFiles/cmd.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cmd.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cmd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmd.dir/flags.make

CMakeFiles/cmd.dir/src/commands.cpp.o: CMakeFiles/cmd.dir/flags.make
CMakeFiles/cmd.dir/src/commands.cpp.o: /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver/src/commands.cpp
CMakeFiles/cmd.dir/src/commands.cpp.o: CMakeFiles/cmd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cmd.dir/src/commands.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cmd.dir/src/commands.cpp.o -MF CMakeFiles/cmd.dir/src/commands.cpp.o.d -o CMakeFiles/cmd.dir/src/commands.cpp.o -c /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver/src/commands.cpp

CMakeFiles/cmd.dir/src/commands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cmd.dir/src/commands.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver/src/commands.cpp > CMakeFiles/cmd.dir/src/commands.cpp.i

CMakeFiles/cmd.dir/src/commands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cmd.dir/src/commands.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver/src/commands.cpp -o CMakeFiles/cmd.dir/src/commands.cpp.s

# Object files for target cmd
cmd_OBJECTS = \
"CMakeFiles/cmd.dir/src/commands.cpp.o"

# External object files for target cmd
cmd_EXTERNAL_OBJECTS =

libcmd.a: CMakeFiles/cmd.dir/src/commands.cpp.o
libcmd.a: CMakeFiles/cmd.dir/build.make
libcmd.a: CMakeFiles/cmd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcmd.a"
	$(CMAKE_COMMAND) -P CMakeFiles/cmd.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cmd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cmd.dir/build: libcmd.a
.PHONY : CMakeFiles/cmd.dir/build

CMakeFiles/cmd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cmd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cmd.dir/clean

CMakeFiles/cmd.dir/depend:
	cd /home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver /home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver /home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver /home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver/CMakeFiles/cmd.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/cmd.dir/depend
