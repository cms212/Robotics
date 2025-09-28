# this must be run from the workspace directory, NOT from within the package
# so copy it to your workspace root directory and then run '. go.sh' from that 
# directory
colcon build
source install/setup.bash
ros2 launch robot test_launch.py
