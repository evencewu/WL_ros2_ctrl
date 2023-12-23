cmake_minimum_required(VERSION 3.10)
project(wl_driver)

## Use C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#######################
## Find dependencies ##
#######################
find_package(ament_cmake_auto REQUIRED)
find_package(ethercat_to_can REQUIRED)
ament_auto_find_build_dependencies()

###########
## Build ##
###########
ament_auto_add_library(${PROJECT_NAME} SHARED
  src/driver_node.cpp
)

#target_include_directories(${PROJECT_NAME} PUBLIC )
#target_link_libraries(${PROJECT_NAME} )

rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN wl_driver::WlDriverNode
  EXECUTABLE wl_driver_node
)

#############
## Testing ##
#############

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


#############
## Install ##
#############

ament_auto_package(
  INSTALL_TO_SHARE
)
