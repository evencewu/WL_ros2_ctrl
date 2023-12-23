import os
import sys

from launch_ros.actions import ComposableNodeContainer 
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription

from launch.actions import TimerAction

sys.path.append(os.path.join(get_package_share_directory('wl_master'), 'launch'))


def get_wl_real_container(driver_node):
    return ComposableNodeContainer(
        name='get_wl_real_container',
        namespace='',
        package='rclcpp_components',
        executable='component_container',
        composable_node_descriptions=[
            driver_node,
        ],
        output='screen',
    )

def generate_launch_description():
    from common import get_wl_driver_node

    wl_driver_node = get_wl_driver_node('wl_driver', 'wl_driver::WlDriverNode','wl_driver')

    wl_real_module = get_wl_real_container(wl_driver_node)
    
    
    return LaunchDescription(
        [
            wl_real_module,
        ]
    )