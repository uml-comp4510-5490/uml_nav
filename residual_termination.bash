#!/bin/bash

echo 'Terminating any ROS nodes found...'
pkill -f ros
pkill -f nodelet
pkill -f gazebo
echo 'Done -- bye!'
