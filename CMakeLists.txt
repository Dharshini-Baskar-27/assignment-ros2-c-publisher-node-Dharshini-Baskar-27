cmake_minimum_required(VERSION 3.8)
project(ros2_publisher)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Add executable target named 'publisher_node'
add_executable(publisher_node src/publisher_node.cpp)

# Add dependencies for rclcpp and std_msgs
ament_target_dependencies(publisher_node
  rclcpp
  std_msgs
)

# Install the target to the DESTINATION lib/${PROJECT_NAME}
install(TARGETS
  publisher_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
