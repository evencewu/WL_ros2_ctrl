#pragma once

// ROS
#include "rclcpp/rclcpp.hpp"
#include <rclcpp/logging.hpp>
#include <rclcpp/qos.hpp>
#include <rclcpp/utilities.hpp>

// C++ system
#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "ecat_can_base/ecat_base.hpp"
#include "wl_driver/a1_motor.hpp"

namespace wl_driver
{
  class WlDriverNode : public rclcpp::Node
  {
  public:
    explicit WlDriverNode(const rclcpp::NodeOptions &options);
    void safe_stop();
    
  private:
    A1Motor leg_motor[4];

    ecat::EcatBase Ethercat;
  };
}