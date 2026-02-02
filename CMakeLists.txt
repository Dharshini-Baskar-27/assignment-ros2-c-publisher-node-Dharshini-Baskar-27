cmake_minimum_required(VERSION 3.8)
project(ros2_publisher)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

<<<<<<< HEAD
# Add executable target named 'publisher_node'
add_executable(publisher_node src/publisher_node.cpp)

# Add dependencies for rclcpp and std_msgs
=======
# Publisher node executable
add_executable(publisher_node src/publisher_node.cpp)

>>>>>>> 4ca381e (Assignment-2: Working ROS2 C++ publisher node)
ament_target_dependencies(publisher_node
  rclcpp
  std_msgs
)

<<<<<<< HEAD
# Install the target to the DESTINATION lib/${PROJECT_NAME}
=======
# Install executable so ros2 run can find it
>>>>>>> 4ca381e (Assignment-2: Working ROS2 C++ publisher node)
install(TARGETS
  publisher_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
