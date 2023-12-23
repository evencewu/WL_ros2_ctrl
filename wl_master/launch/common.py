import os
import yaml

from ament_index_python.packages import get_package_share_directory, get_package_prefix
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration

from launch_ros.descriptions import ComposableNode

from launch.actions import TimerAction


def get_wl_driver_node(package, plugin, name):
    return ComposableNode(
        package=package,
        plugin=plugin,
        name=name,
        extra_arguments=[{"use_intra_process_comms": True}],
    )
    