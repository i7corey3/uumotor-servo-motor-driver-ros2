cmake_minimum_required(VERSION 3.8)
project(uumotor_servo_motor_driver)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()



# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)


# allows other cpp cpde to use the headers inside include folder
include_directories(include)


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

ament_target_dependencies(
  ${PROJECT_NAME}
  PUBLIC
  rclcpp
  
)


add_executable(driver src/test_node.cpp src/functions.cpp src/commands.cpp)
ament_target_dependencies(driver rclcpp)

add_library(fun src/functions.cpp)
add_library(cmd src/commands.cpp)
target_link_libraries(driver fun cmd serial)
ament_target_dependencies(cmd rclcpp)
target_link_libraries(uumotor_servo_motor_driver PUBLIC serial)




install(
  TARGETS 
  ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME}
)
install(
  DIRECTORY include/uumotor_servo_motor_driver/
  DESTINATION include/uumotor_servo_motor_driver/
)
# INSTALL
install(
  TARGETS 
  driver
  DESTINATION lib/${PROJECT_NAME}
)

ament_export_include_directories(
  include
)
ament_export_libraries(
  ${PROJECT_NAME}
)

ament_export_dependencies(
  
  rclcpp
  serial
  
)
ament_export_include_directories(include)
ament_package()
