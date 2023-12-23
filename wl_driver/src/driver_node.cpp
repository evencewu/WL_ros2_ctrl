#include "wl_driver/driver_node.hpp"

namespace wl_driver
{
  WlDriverNode::WlDriverNode(const rclcpp::NodeOptions &options) : Node("Wl_driver_node", options)
  {
    char phy[] = "enp5s0";
    RCLCPP_INFO(this->get_logger(), "wl_driver启动");
    //RCLCPP_INFO(this->get_logger(), "wl_driver启动%d",ecat::call_1());
    //RCLCPP_INFO(this->get_logger(), "wl_driver启动,网口%s\n",phy);
    //Ethercat.EcatStart(phy);
    //Ethercat.SetUserStop(this->safe_stop);
  }
}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(wl_driver::WlDriverNode);