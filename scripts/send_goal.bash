#!/bin/bash

read -p "Enter goal [1-5]: " goalNum
echo "Initiating run with goal $goalNum"

# http://wiki.ros.org/navigation/Tutorials/SendingSimpleGoals
case "$goalNum" in
    1)  
        echo "sending goal 1"
        rostopic pub /move_base_simple/goal geometry_msgs/PoseStamped '{header: {stamp: now, frame_id: "map"}, pose: {position: {x: 1.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}}'
        ;;
    2) 
        echo "sending goal 2"
        rostopic pub /move_base_simple/goal geometry_msgs/PoseStamped '{header: {stamp: now, frame_id: "map"}, pose: {position: {x: 1.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}}'
        ;;
    *)
        echo "Invalid goal"
        ;;
esac
