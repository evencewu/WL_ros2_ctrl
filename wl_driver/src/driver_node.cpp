#include "wl_driver/driver_node.hpp"

namespace wl_driver
{
  WlDriverNode::WlDriverNode(const rclcpp::NodeOptions &options) : Node("Wl_driver_node", options)
  {
    char phy[] = "enp5s0";
    //RCLCPP_INFO(this->get_logger(), "wl_driver启动");

    RCLCPP_INFO(this->get_logger(), "wl_driver启动,网口%s\n",phy);
    Ethercat.EcatStart(phy);

    for (int i = 0; i < 1000; i++)
    {
      Ethercat.packet_tx->LED = 0x03;
      RCLCPP_INFO(this->get_logger(), "loop\n");
      Ethercat.EcatSyncMsg();
    }

    safe_stop();
    Ethercat.EcatStop();
  }

  void WlDriverNode::safe_stop()
  {
    
  }
}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(wl_driver::WlDriverNode);