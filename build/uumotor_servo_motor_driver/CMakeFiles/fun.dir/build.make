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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver

# Include any dependencies generated for this target.
include CMakeFiles/fun.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fun.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fun.dir/flags.make

CMakeFiles/fun.dir/src/functions.cpp.o: CMakeFiles/fun.dir/flags.make
CMakeFiles/fun.dir/src/functions.cpp.o: /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver/src/functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fun.dir/src/functions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fun.dir/src/functions.cpp.o -c /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver/src/functions.cpp

CMakeFiles/fun.dir/src/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fun.dir/src/functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver/src/functions.cpp > CMakeFiles/fun.dir/src/functions.cpp.i

CMakeFiles/fun.dir/src/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fun.dir/src/functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver/src/functions.cpp -o CMakeFiles/fun.dir/src/functions.cpp.s

# Object files for target fun
fun_OBJECTS = \
"CMakeFiles/fun.dir/src/functions.cpp.o"

# External object files for target fun
fun_EXTERNAL_OBJECTS =

libfun.a: CMakeFiles/fun.dir/src/functions.cpp.o
libfun.a: CMakeFiles/fun.dir/build.make
libfun.a: CMakeFiles/fun.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libfun.a"
	$(CMAKE_COMMAND) -P CMakeFiles/fun.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fun.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fun.dir/build: libfun.a

.PHONY : CMakeFiles/fun.dir/build

CMakeFiles/fun.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fun.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fun.dir/clean

CMakeFiles/fun.dir/depend:
	cd /home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver /home/corey/uumotor-servo-motor-driver-ros2/src/uumotor_servo_motor_driver /home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver /home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver /home/corey/uumotor-servo-motor-driver-ros2/build/uumotor_servo_motor_driver/CMakeFiles/fun.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fun.dir/depend

