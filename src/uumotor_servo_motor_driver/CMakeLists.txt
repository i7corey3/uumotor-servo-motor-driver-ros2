cmake_minimum_required(VERSION 3.8)
project(uumotor_servo_motor_driver)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(serial REQUIRED)
find_package(rclcpp REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

## COMPILE
add_library(
  ${PROJECT_NAME}
  SHARED
  src/commands.cpp
  src/functions.cpp

)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  include
)

add_executable(driver src/test.cpp)

ament_target_dependencies(driver rclcpp)

ament_target_dependencies(
  ${PROJECT_NAME}
  serial

)

# INSTALL
install(
  TARGETS 
  driver
  DESTINATION share/${PROJECT_NAME}
)
install(
  DIRECTORY include/uumotor_servo_motor_driver/
  DESTINATION include/uumotor_servo_motor_driver/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

## EXPORTS
ament_export_include_directories(
  include
)
ament_export_libraries(
  ${PROJECT_NAME}
)
ament_export_dependencies(
  serial
)

ament_package()
