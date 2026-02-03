cmake_minimum_required(VERSION 3.8)
project(ros2_publisher)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Publisher node executable
add_executable(publisher_node src/publisher_node.cpp)

ament_target_dependencies(publisher_node
  rclcpp
  std_msgs
)

# Install executable so ros2 run can find it
install(TARGETS
  publisher_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
